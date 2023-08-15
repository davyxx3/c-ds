//
// Created by Davy on 2021/2/18.
//

#include <stdlib.h>
#include <stdio.h>
#include "MatrixGraph.h"

// 初始化一个没有边的有向图
AdjacencyMatrixGraph CreateGraph(int VertexNum) {
    // 创建邻接矩阵
    AdjacencyMatrixGraph ret = (AdjacencyMatrixGraph) malloc(sizeof(struct AdjacencyMatrixGraphNode));
    ret->VertexNum = VertexNum;
    ret->EdgeNum = 0;
    ret->AdjacencyMatrix = (WeightType **) malloc(sizeof(WeightType *) * VertexNum);
    for (int i = 0; i < VertexNum; i++) {
        ret->AdjacencyMatrix[i] = (WeightType *) malloc(sizeof(WeightType) * VertexNum);
    }
    // 默认为有向图
    ret->IsDirected = 1;
    // 将所有权值都设为0
    for (int i = 0; i < ret->VertexNum; i++) {
        for (int j = 0; j < ret->VertexNum; j++) {
            ret->AdjacencyMatrix[i][j] = 0;
        }
    }
    return ret;
}

// 插入一条边
void InsertEdge(AdjacencyMatrixGraph graph, Edge edge) {
    graph->AdjacencyMatrix[edge->from][edge->to] = edge->weight;
    if (graph->IsDirected == 0) {
        // 若为无向图，则还要改变对称位置的值
        graph->AdjacencyMatrix[edge->to][edge->from] = edge->weight;
    }
    // 边数加1
    graph->EdgeNum++;
}

// 建立一个图
AdjacencyMatrixGraph BuildGraph() {
    printf("Please enter the number of vertexes:");
    int VertexNum;
    int EdgeNum;
    scanf("%d", &VertexNum);
    AdjacencyMatrixGraph ret = CreateGraph(VertexNum);
    printf("Please enter the number of edges:");
    scanf("%d", &EdgeNum);
    if (EdgeNum > 0) {
        Edge NewEdge = (Edge) malloc(sizeof(struct EdgeNode));
        for (int i = 0; i < EdgeNum; i++) {
            scanf("%d %d %d", &NewEdge->from, &NewEdge->to, &NewEdge->weight);
            InsertEdge(ret, NewEdge);
        }
    }
    return ret;
}

// 打印一个图
void PrintGraph(AdjacencyMatrixGraph graph) {
    printf("\n");
    for (int i = 0; i < graph->EdgeNum; i++) {
        for (int j = 0; j < graph->EdgeNum; j++) {
            printf("%d\t", graph->AdjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}
