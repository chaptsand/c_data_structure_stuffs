#include "GraphLnk.h"

void InitGraph(GraphLnk* g)
{
    g->arcnum = g->vexnum = 0;

    int i = 0;
    for(i = 0; i < Default_Vertex_Size; i++)
    {
        g->vertices[i].adjarc = NULL;
    }
}

int GetVertexPos(GraphLnk* g, VertexType v)
{
    int i = 0;
    for(i = 0; i < g->vexnum; i++)
    {
        if(g->vertices[i].data == v)
            return i;
    }
    return -1;
}

void ShowGraph(GraphLnk* g)
{
    ArcNode* cur;
    int i = 0;

    for(i = 0; i < g->vexnum; i++)
    {
        printf("[%d] %c:> ", i, g->vertices[i].data);
        cur = g->vertices[i].adjarc;
        while (cur)
        {
            printf("%d-->", cur->adjvex);
            cur = cur->link;
        }
        printf("Nul.\n");
    }
    printf("\n");
}
void InsertVertex(GraphLnk* g, VertexType v)
{
    if(g->vexnum >= Default_Vertex_Size)
        return;

    g->vertices[g->vexnum++].data = v;
}

void InsertEdges(GraphLnk* g, VertexType v1, VertexType v2)
{
    int p1 = GetVertexPos(g, v1);
    int p2 = GetVertexPos(g, v2);
    if(p1 == -1 || p2 == -1)
        return;

    ArcNode* s = (ArcNode*)malloc(sizeof(ArcNode));
    assert(s);

    s->adjvex = p2;
    s->link = g->vertices[p1].adjarc;
    g->vertices[p1].adjarc = s;

    ArcNode* t = (ArcNode*)malloc(sizeof(ArcNode));
    assert(t);
    t->adjvex = p1;
    t->link = g->vertices[p2].adjarc;
    g->vertices[p2].adjarc = t;

    g->arcnum++;
}

void RemoveEdges(GraphLnk* g, VertexType v1, VertexType v2)
{
    int p1 = GetVertexPos(g, v1);
    int p2 = GetVertexPos(g, v2);
    if(p1 == -1 || p2 == -1)
        return;

    ArcNode* prev = NULL;
    ArcNode* cur = g->vertices[p1].adjarc;
    while (cur != NULL && cur->adjvex != p2)
    {
        prev = cur;
        cur = cur->link;
    }

    if(cur == NULL)
        return;

    if(prev == NULL)
    {
        g->vertices[p1].adjarc = cur->link;
    }
    else
    {
        prev->link = cur->link;
    }
    free(cur);
    cur = NULL;


    prev = NULL;
    cur = g->vertices[p2].adjarc;
    while (cur->adjvex != p1)
    {
        prev = cur;
        cur = cur->link;
    }
    if(prev == NULL)
    {
        g->vertices[p2].adjarc = cur->link;
    }
    else
    {
        prev->link = cur->link;
    }
    free(cur);
    cur = NULL;
    g->arcnum--;
}

void RemoveVetex(GraphLnk* g, VertexType v)
{
    int p = GetVertexPos(g, v);
    if(p == -1)
        return;

    ArcNode* cur = g->vertices[p].adjarc;

    int k;
    ArcNode* prev = NULL;
    ArcNode* s;
    while (cur != NULL)
    {
        k = cur->adjvex;
        s = g->vertices[k].adjarc;
        while (s != NULL && s->adjvex != p)
        {
            prev = s;
            s = s->link;
        }
        if(s != NULL)
        {
            if(prev == NULL)
            {
                g->vertices[k].adjarc = s->link;
            }
            else
            {
                prev->link = s->link;
            }
            free(s);
        }
        g->vertices[p].adjarc = cur->link;
        free(cur);
        cur = g->vertices[p].adjarc;
    }

    g->vexnum--;
    g->vertices[p].data = g->vertices[g->vexnum].data;
    g->vertices[p].adjarc = g->vertices[g->vexnum].adjarc;

    s = g->vertices[p].adjarc;
    while (s != NULL)
    {
        k = s->adjvex;
        cur = g->vertices[k].adjarc;
        while (cur != NULL)
        {
            if(cur->adjvex == g->vexnum)
            {
                cur->adjvex = p;
                break;
            }
            cur = cur->link;
        }
        s = s->link;
    }
}

int GetFirstNeighbor(GraphLnk* g, VertexType v)
{
    int p = GetVertexPos(g, v);
    if(p == -1)
        return -1;
    
    ArcNode* cur = g->vertices[p].adjarc;
    return  (cur != NULL) ? cur->adjvex : -1;
}

int GetNextNeighbor(GraphLnk* g, VertexType v, VertexType w)
{
    int p1 = GetVertexPos(g, v);
    int p2 = GetVertexPos(g, w);
    if(p1 == -1 || p2 == -1)
        return -1;

    ArcNode* cur = g->vertices[p1].adjarc;
    while (cur != NULL && cur->adjvex != p2)
    {
        cur = cur->link;
    }
    if(cur != NULL && cur->link != NULL)
    {
        return cur->link->adjvex;
    }
    return -1;
}