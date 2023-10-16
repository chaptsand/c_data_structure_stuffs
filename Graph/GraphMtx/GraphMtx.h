#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define Default_Vertex_Size 10

typedef char VertexType;

typedef struct GraphMtx
{
    VertexType Vex[Default_Vertex_Size];
    int Edge[Default_Vertex_Size][Default_Vertex_Size];
    int vexnum, arcnum;
}GraphMtx;

void InitGraph(GraphMtx* g);
void ShowGraph(GraphMtx* g);

void InsertVetex(GraphMtx* g, VertexType v);
void RemoveVetex(GraphMtx* g, VertexType v);
int GetVertexPos(GraphMtx* g, VertexType v);

void InsertEdge(GraphMtx* g, VertexType v1, VertexType v2);
void RemoveEdge(GraphMtx* g, VertexType v1, VertexType v2);

int GetFirstNeighbor(GraphMtx* g, VertexType v);
int GetNextNeighbor(GraphMtx* g, VertexType v, VertexType w);
