#include "GraphMtx.h"

void InitGraph(GraphMtx* g)
{
    g->vexnum = g->arcnum = 0;

    for(int i = 0; i < Default_Vertex_Size; i++)
    {
        for(int j =0; j < Default_Vertex_Size; j++)
        {
            g->Edge[i][j] = 0;
        }
    }
}

void ShowGraph(GraphMtx* g)
{
    int i =0, j = 0;
    printf("   ");
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

void InsertVetex(GraphMtx* g, VertexType v)
{
    if(g->vexnum >= Default_Vertex_Size)
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
    {
        // printf("非法输入\n");
        return;
    }

    if(g->Edge[p1][p2])
    {
        // printf("%c与%c之间边已存在！\n", g->Vex[p1], g->Vex[p2]);
        return;
    }

    g->Edge[p1][p2] = g->Edge[p2][p1] = 1;
    g->arcnum++;    
}

void RemoveEdge(GraphMtx* g, VertexType v1, VertexType v2)
{
    int p1 = GetVertexPos(g, v1);
    int p2 = GetVertexPos(g, v2);

    if(p1 == -1 || p2 == -1)
        return;

    if(g->Edge[p1][p2] == 0)
        return;
    
    g->Edge[p1][p2] = g->Edge[p2][p1] = 0;
    g->arcnum--;
}

void RemoveVetex(GraphMtx* g, VertexType v)
{
    int p = GetVertexPos(g, v);

    if(p == -1)
        return;
    
    int i = 0, j = 0;
    for(i = p; i < g->vexnum - 1; i++)
    {
        g->Vex[i] = g->Vex[i+1];
    }

    int countedges = 0;
    for(i = 0; i < g->vexnum; i++)
    {
        if(g->Edge[p][i])
        {
            countedges++;
        }
    }

    for(i = 0; i < g->vexnum; i++)
    {
        for(j = p; j < g->vexnum - 1; j++)
        {
            g->Edge[i][j] = g->Edge[i][j+1];
        }
    }

    for(i = p; i < g->vexnum - 1; i++)
    {
        for(j = 0; j < g->vexnum; j++)
        {
            g->Edge[i][j] = g->Edge[i+1][j];
        }
    }
    g->vexnum--;
    g->arcnum -= countedges;
}

/*
void RemoveVetex(GraphMtx* g, VertexType v)
{
    int p = GetVertexPos(g, v);

    if(p == -1)
        return;
    
    int i = 0;
    int countedges = 0;
    for(i = 0; i < g->vexnum; i++)
    {
        if(g->Edge[p][i])
        {
            countedges++;
        }
    }

    g->Vex[p] = g->Vex[g->vexnum-1];
    
    for(i = 0; i < g->vexnum; i++)
    {
        g->Edge[i][p] = g->Edge[i][g->vexnum - 1];
    }

    int j = 0;
    for(j = 0; j < g->vexnum; j++)
    {
        g->Edge[p][j] = g->Edge[g->vexnum - 1][j];
    }

    g->vexnum--;
    g->arcnum -= countedges;
}
*/

int GetFirstNeighbor(GraphMtx* g, VertexType v)
{
    int p = GetVertexPos(g, v);
    if(p == -1)
        return -1;

    for(int i = 0; i < g->vexnum; i++)
    {
        if(g->Edge[p][i] == 1)
            return i;
    }

    return -1;
}

int GetNextNeighbor(GraphMtx* g, VertexType v, VertexType w)
{
    int pv = GetVertexPos(g, v);
    int pw = GetVertexPos(g, w);
    if(pv == -1 || pw == -1)
        return -1;

    for(int i = pw + 1; i < g->vexnum; i++)
    {
        if(g->Edge[pv][i] == 1)
            return i;
    }
    return -1;
}