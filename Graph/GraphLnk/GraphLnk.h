#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define Default_Vertex_Size 10

typedef char VertexType;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode* link;
}ArcNode;

typedef struct VexNode
{
    VertexType data;
    ArcNode* adjarc;
}VexNode,AdjList[Default_Vertex_Size];

typedef struct GraphLnk
{
    AdjList vertices;
    int vexnum, arcnum;
}GraphLnk;

void InitGraph(GraphLnk* g);
int GetVertexPos(GraphLnk* g, VertexType v);
void ShowGraph(GraphLnk* g);
void InsertVertex(GraphLnk* g, VertexType v);
void InsertEdges(GraphLnk* g, VertexType v1, VertexType v2);

void RemoveEdges(GraphLnk* g, VertexType v1, VertexType v2);
void RemoveVetex(GraphLnk* g, VertexType v);

int GetFirstNeighbor(GraphLnk* g, VertexType v);
int GetNextNeighbor(GraphLnk* g, VertexType v, VertexType w);

