#include "GraphLnk.h"

void GrapgLnkTest1()
{
    GraphLnk gl;
    InitGraph(&gl);
    InsertVertex(&gl, 'A');
    InsertVertex(&gl, 'B');
    InsertVertex(&gl, 'C');
    InsertVertex(&gl, 'D');
    InsertVertex(&gl, 'E');

    InsertEdges(&gl, 'A', 'B');
    InsertEdges(&gl, 'A', 'D');
    InsertEdges(&gl, 'B', 'C');
    InsertEdges(&gl, 'B', 'E');
    InsertEdges(&gl, 'C', 'D');
    InsertEdges(&gl, 'C', 'E');

    ShowGraph(&gl);
}

void GrapgLnkTest2()
{
    GraphLnk gl;
    InitGraph(&gl);
    InsertVertex(&gl, 'A');
    InsertVertex(&gl, 'B');
    InsertVertex(&gl, 'C');
    InsertVertex(&gl, 'D');
    InsertVertex(&gl, 'E');

    InsertEdges(&gl, 'A', 'B');
    InsertEdges(&gl, 'A', 'D');
    InsertEdges(&gl, 'B', 'C');
    InsertEdges(&gl, 'B', 'E');
    InsertEdges(&gl, 'C', 'D');
    InsertEdges(&gl, 'C', 'E');

    ShowGraph(&gl);

    RemoveEdges(&gl, 'A', 'C');
    ShowGraph(&gl);
}

void GrapgLnkTest3()
{
    GraphLnk gl;
    InitGraph(&gl);
    InsertVertex(&gl, 'A');
    InsertVertex(&gl, 'B');
    InsertVertex(&gl, 'C');
    InsertVertex(&gl, 'D');
    InsertVertex(&gl, 'E');

    InsertEdges(&gl, 'A', 'B');
    InsertEdges(&gl, 'A', 'D');
    InsertEdges(&gl, 'B', 'C');
    InsertEdges(&gl, 'B', 'E');
    InsertEdges(&gl, 'C', 'D');
    InsertEdges(&gl, 'C', 'E');

    ShowGraph(&gl);

    RemoveVetex(&gl, 'C');
    ShowGraph(&gl);
    
}

void GrapgLnkTest4()
{
    GraphLnk gl;
    InitGraph(&gl);
    InsertVertex(&gl, 'A');
    InsertVertex(&gl, 'B');
    InsertVertex(&gl, 'C');
    InsertVertex(&gl, 'D');
    InsertVertex(&gl, 'E');

    InsertEdges(&gl, 'A', 'B');
    InsertEdges(&gl, 'A', 'D');
    InsertEdges(&gl, 'B', 'C');
    InsertEdges(&gl, 'B', 'E');
    InsertEdges(&gl, 'C', 'D');
    InsertEdges(&gl, 'C', 'E');

    ShowGraph(&gl);
    // int ret = GetFirstNeighbor(&gl, 'A');

    int ret = GetNextNeighbor(&gl, 'B', 'E');
    printf("%d\n", ret);
}

int main()
{
    GrapgLnkTest4();
    return 0;
}