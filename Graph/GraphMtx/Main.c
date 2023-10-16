#include "GraphMtx.h"

void TestGraph1()
{
    GraphMtx gm;
    InitGraph(&gm);
    InsertVetex(&gm, 'A');
    InsertVetex(&gm, 'B');
    InsertVetex(&gm, 'C');
    InsertVetex(&gm, 'D');
    InsertVetex(&gm, 'E');

    InsertEdge(&gm, 'A', 'B');
    InsertEdge(&gm, 'A', 'D');
    InsertEdge(&gm, 'B', 'C');
    InsertEdge(&gm, 'B', 'E');
    InsertEdge(&gm, 'C', 'E');
    InsertEdge(&gm, 'C', 'D');

    ShowGraph(&gm);
}

void TestGraph2()
{
    GraphMtx gm;
    InitGraph(&gm);
    InsertVetex(&gm, 'A');
    InsertVetex(&gm, 'B');
    InsertVetex(&gm, 'C');
    InsertVetex(&gm, 'D');
    InsertVetex(&gm, 'E');

    InsertEdge(&gm, 'A', 'B');
    InsertEdge(&gm, 'A', 'D');
    InsertEdge(&gm, 'B', 'C');
    InsertEdge(&gm, 'B', 'E');
    InsertEdge(&gm, 'C', 'E');
    InsertEdge(&gm, 'C', 'D');

    ShowGraph(&gm);
    RemoveEdge(&gm, 'A', 'B');
    ShowGraph(&gm);
}

void TestGraph3()
{
    GraphMtx gm;
    InitGraph(&gm);
    InsertVetex(&gm, 'A');
    InsertVetex(&gm, 'B');
    InsertVetex(&gm, 'C');
    InsertVetex(&gm, 'D');
    InsertVetex(&gm, 'E');

    InsertEdge(&gm, 'A', 'B');
    InsertEdge(&gm, 'A', 'D');
    InsertEdge(&gm, 'B', 'C');
    InsertEdge(&gm, 'B', 'E');
    InsertEdge(&gm, 'C', 'E');
    InsertEdge(&gm, 'C', 'D');

    ShowGraph(&gm);
    RemoveVetex(&gm, 'C');
    ShowGraph(&gm);
}

void TestGraph4()
{
    GraphMtx gm;
    InitGraph(&gm);
    InsertVetex(&gm, 'A');
    InsertVetex(&gm, 'B');
    InsertVetex(&gm, 'C');
    InsertVetex(&gm, 'D');
    InsertVetex(&gm, 'E');

    InsertEdge(&gm, 'A', 'B');
    InsertEdge(&gm, 'A', 'D');
    InsertEdge(&gm, 'B', 'C');
    InsertEdge(&gm, 'B', 'E');
    InsertEdge(&gm, 'C', 'E');
    InsertEdge(&gm, 'C', 'D');

    ShowGraph(&gm);

    int p = GetFirstNeighbor(&gm, 'D');
    printf("D's first neighbor is: %c\n", gm.Vex[p]);

    int pn = GetNextNeighbor(&gm, 'C', 'D');
    printf("C's next neighbor other than D is: %c\n", gm.Vex[pn]);

}

int main()
{
    TestGraph4();
    return 0;
}