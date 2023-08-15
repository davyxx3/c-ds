//
// Created by Davy on 2021/2/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "ListGraph.h"
#include "Queue.h"

#define INFINITY 9999

// 寻找未被收录的最小路径顶点
Vertex FindMinDist(ListGraph graph, const int *known, const int *dist);

// 初始化一个无边的图
ListGraph CreateGraph(int VertexNum) {
    // 创建邻接表
    ListGraph ret = (ListGraph) malloc(sizeof(struct GraphNode));
    ret->VertexNum = VertexNum;
    ret->EdgeNum = 0;
    ret->AdjList = (AdjList) malloc(sizeof(struct AdjListNode) * VertexNum);
    // 将邻接表的每一项都设为NULL
    for (int i = 0; i < VertexNum; i++) {
        ret->AdjList[i].FirstEdge = NULL;
    }
    return ret;
}

// 插入一条边
void InsertEdge(ListGraph graph, Edge edge) {
    // 构建新的邻接顶点
    AdjVertex NewVertex = (AdjVertex) malloc(sizeof(struct AdjVertexNode));
    NewVertex->vertex = edge->to;
    NewVertex->weight = edge->weight;
    NewVertex->next = graph->AdjList[edge->from].FirstEdge;
    // 将顶点插入邻接表对应位置
    graph->AdjList[edge->from].FirstEdge = NewVertex;
    // 边数加1
    graph->EdgeNum++;
}

// 建立一个图
ListGraph BuildGraph() {
    printf("Please enter the number of vertexes:");
    int VertexNum;
    int EdgeNum;
    scanf("%d", &VertexNum);
    ListGraph ret = CreateGraph(VertexNum);
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
void PrintGraph(ListGraph graph) {
    printf("\n");
    for (int i = 0; i < graph->VertexNum; i++) {
        printf("%d -> ", i);
        AdjVertex v = graph->AdjList[i].FirstEdge;
        while (v != NULL) {
            printf("{vertex: %d weight: %d} ", v->vertex, v->weight);
            v = v->next;
        }
        printf("\n");
    }
}

// 求单源无权最短路径，结果放在path中
void FindUnweightedPath(ListGraph graph, Vertex vertex, int *path) {
    int *dist = malloc(sizeof(int) * graph->VertexNum);
    for (int i = 0; i < graph->VertexNum; ++i) {
        dist[i] = INFINITY;
    }
    if (vertex > graph->VertexNum) {
        printf("Out of boundary!");
    }
    dist[vertex] = 0;
    Unweighted(graph, vertex, dist, path);
    free(dist);
}

// 无权最短路径算法
void Unweighted(ListGraph graph, Vertex vertex, int *dist, int *path) {
    Queue queue = CreateEmptyQueue(graph->VertexNum);
    // 将原点入队
    Enqueue(queue, vertex);
    // 处理每一个顶点，当队列为空时停止
    while (!IsEmpty(queue)) {
        // 从队列中取一个顶点处理
        int CurrentVertex = Dequeue(queue);
        // 获取这个顶点的第一个邻接点
        AdjVertex AdjVertex = graph->AdjList[CurrentVertex].FirstEdge;
        // 对每一个邻接点进行处理
        while (AdjVertex != NULL) {
            // 若顶点未处理过，则进行处理；若已经处理过，则跳过该顶点
            if (dist[AdjVertex->vertex] == INFINITY) {
                // 更新距离
                dist[AdjVertex->vertex] = dist[CurrentVertex] + 1;
                // 更新路径
                path[AdjVertex->vertex] = CurrentVertex;
                // 放入队列
                Enqueue(queue, AdjVertex->vertex);
            }
            // 处理下一个邻接点
            AdjVertex = AdjVertex->next;
        }
    }
    // 删除队列，释放空间
    DeleteQueue(queue);
}

// 求单源有权最短路径，结果放在path中
void FindWeightedPath(ListGraph graph, Vertex vertex, int *path) {
    int *dist = malloc(sizeof(int) * graph->VertexNum);
    for (int i = 0; i < graph->VertexNum; ++i) {
        dist[i] = INFINITY;
    }
    if (vertex > graph->VertexNum) {
        printf("Out of boundary!");
    }
    dist[vertex] = 0;
    Dijkstra(graph, dist, path);
    free(dist);
}

// Dijkstra算法
void Dijkstra(ListGraph graph, int *dist, int *path) {
    // 创建标记数组
    int *known = (int *) malloc(sizeof(int) * graph->VertexNum);
    for (int i = 0; i < graph->VertexNum; i++) {
        known[i] = 0;
    }
    while (1) {
        // 取未被收录的最小路径顶点
        int CurrentVertex = FindMinDist(graph, known, dist);
        // 若已经收录完所有顶点，则跳出循环
        if (CurrentVertex == -1) {
            break;
        }
        // 收录该顶点
        known[CurrentVertex] = 1;
        AdjVertex AdjVertex = graph->AdjList[CurrentVertex].FirstEdge;
        // 更新所有邻接顶点
        while (AdjVertex != NULL) {
            // 若邻接顶点未被收录且可以被更新
            if (known[AdjVertex->vertex] == 0 && dist[CurrentVertex] + AdjVertex->weight < dist[AdjVertex->vertex]) {
                // 更新顶点的最短路径
                dist[AdjVertex->vertex] = dist[CurrentVertex] + AdjVertex->weight;
                // 更新路径信息
                path[AdjVertex->vertex] = CurrentVertex;
            }
            // 更新下一个邻接节点
            AdjVertex = AdjVertex->next;
        }
    }
    // 释放空间
    free(known);
}

// 寻找未被收录的最小路径顶点
Vertex FindMinDist(ListGraph graph, const int *known, const int *dist) {
    int MinVertex = -1;
    int MinDist = INFINITY;
    for (int i = 0; i < graph->VertexNum; i++) {
        if (known[i] == 0 && dist[i] < MinDist) {
            MinVertex = i;
            MinDist = dist[i];
        }
    }
    return MinVertex;
}

// 打印最短路径
void PrintPath(int *path, Vertex vertex) {
    if (path[vertex] != -1) {
        PrintPath(path, path[vertex]);
    }
    printf("%d ", vertex);
}

// 拓扑排序，将结果放入TopNum数组中
void TopSort(ListGraph graph, int *TopNum) {
    // 创建记录0入度顶点的队列
    Queue ZeroIndegreeVertexs = CreateEmptyQueue(graph->VertexNum);
    // 创建入度记录数组
    int *indegree = (int *) malloc(sizeof(int) * graph->VertexNum);
    // 初始化数组
    for (int i = 0; i < graph->VertexNum; i++) {
        indegree[i] = 0;
    }
    // 计算所有顶点的入度
    for (int i = 0; i < graph->VertexNum; i++) {
        AdjVertex j = graph->AdjList[i].FirstEdge;
        while (j != NULL) {
            indegree[j->vertex]++;
            j = j->next;
        }
    }
    // 将入度为0的顶点放入队列
    for (int i = 0; i < graph->VertexNum; i++) {
        if (indegree[i] == 0) {
            Enqueue(ZeroIndegreeVertexs, i);
        }
    }
    // 计数变量
    int count = 0;
    // 当队列为空时，停止循环
    while (!IsEmpty(ZeroIndegreeVertexs)) {
        // 获取一个入度为0的顶点
        Vertex CurrentVertex = Dequeue(ZeroIndegreeVertexs);
        // 记录拓扑顺序
        TopNum[count++] = CurrentVertex;
        // 更改邻接顶点的入度数量
        AdjVertex AdjVertex = graph->AdjList[CurrentVertex].FirstEdge;
        while (AdjVertex != NULL) {
            // 若更改后入度为0，则入队
            if (--indegree[AdjVertex->vertex] == 0) {
                Enqueue(ZeroIndegreeVertexs, AdjVertex->vertex);
            }
            AdjVertex = AdjVertex->next;
        }
    }
    // 若拓扑排序数与顶点数不相符，则说明图是有圈的
    if (count != graph->VertexNum) {
        printf("Graph has a cycle!");
    }
    // 释放空间
    DeleteQueue(ZeroIndegreeVertexs);
}



