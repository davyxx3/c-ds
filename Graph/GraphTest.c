//
// Created by Davy on 2021/2/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "ListGraph.h"

int main(int argc, char **argv) {
    ListGraph graph = BuildGraph();
    PrintGraph(graph);
    int *TopNum = malloc(sizeof(int) * graph->VertexNum);
    TopSort(graph, TopNum);
    for (int i = 0; i < graph->VertexNum; i++) {
        printf("%d ", TopNum[i]);
    }
}