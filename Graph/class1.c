#include <stdio.h>

#define Default_Vertices_Size 10

typedef char VertexType;
typedef struct GraphMtx
{
    VertexType Vex[Default_Vertices_Size];
    int Edge[Default_Vertices_Size][Default_Vertices_Size];
    int vexnum, arcnum;
}GraphMtx;

void InitGraph(GraphMtx* g)
{
    int i = 0, j = 0;
    for(i = 0; i < Default_Vertices_Size; i++)
    {
        for(j = 0; j < Default_Vertices_Size; j++)
        {
            g->Edge[i][j] = 0;
        }
    }
    g->vexnum = g->arcnum = 0;
}

void ShowGraph(GraphMtx* g)
{
    printf("   ");
    int i = 0, j = 0;
    for(i = 0; i < g->vexnum; i++)
    {
        printf("%c  ", g->Vex[i]);
    }
    printf("\n");
    for(i = 0; i < g->vexnum; i++)
    {
        printf("%c  ", g->Vex[i]);
        for(j = 0; j < g->vexnum; j++)
        {
            printf("%d  ", g->Edge[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void InsertGraph(GraphMtx* g, VertexType v)
{
    if(g->vexnum > Default_Vertices_Size)
        return;
    g->Vex[g->vexnum++] = v;
}

int GetVertexPos(GraphMtx* g, VertexType v)
{
    int i = 0;
    for(i = 0; i < g->vexnum; i++)
    {
        if(g->Vex[i] == v)
            return i;
    }
    return -1;
}

void InsertEdge(GraphMtx* g, VertexType v1, VertexType v2)
{
    int p1 = GetVertexPos(g, v1);
    int p2 = GetVertexPos(g, v2);
    if(p1 == -1 || p2 == -1)
        return;

    if(g->Edge[p1][p2])
        return;

    g->Edge[p1][p2] = g->Edge[p2][p1] = 1;
    g->arcnum++;
}

int main()
{
    GraphMtx gm;
    InitGraph(&gm);

    InsertGraph(&gm, 'A');
    InsertGraph(&gm, 'B');
    InsertGraph(&gm, 'C');
    InsertGraph(&gm, 'D');
    InsertGraph(&gm, 'E');

    InsertEdge(&gm, 'A', 'B');
    InsertEdge(&gm, 'A', 'D');
    InsertEdge(&gm, 'B', 'C');
    InsertEdge(&gm, 'B', 'E');
    InsertEdge(&gm, 'C', 'E');
    InsertEdge(&gm, 'C', 'D');

    ShowGraph(&gm);
    return 0;
}