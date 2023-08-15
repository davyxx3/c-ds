//
// Created by Davy on 2021/2/20.
//

#ifndef GRAPH_LISTGRAPH_H
#define GRAPH_LISTGRAPH_H

// 图结构
struct GraphNode;
// 邻接表结构
struct AdjListNode;
// 邻接顶点结构
struct AdjVertexNode;
// 边结构
struct EdgeNode;

typedef int WeightType;
typedef int Vertex;
typedef struct GraphNode *ListGraph;
typedef struct AdjListNode *AdjList;
typedef struct AdjVertexNode *AdjVertex;

typedef struct EdgeNode *Edge;

// 图的结构
struct GraphNode {
    int VertexNum;
    int EdgeNum;
    AdjList AdjList;
};

// 邻接表数组的结构
struct AdjListNode {
    AdjVertex FirstEdge;
};

// 表节点的结构
struct AdjVertexNode {
    Vertex vertex;
    WeightType weight;
    AdjVertex next;
};

// 边的结构
struct EdgeNode {
    Vertex from;
    Vertex to;
    WeightType weight;
};

// 初始化一个无边的图
ListGraph CreateGraph(int VertexNum);

// 插入一条边
void InsertEdge(ListGraph graph, Edge edge);

// 建立一个图
ListGraph BuildGraph();

// 打印一个图
void PrintGraph();

// 求单源无权最短路径，结果放在path中
void FindUnweightedPath(ListGraph graph, Vertex vertex, int *path);

// 无权最短路径算法
void Unweighted(ListGraph graph, Vertex vertex, int *dist, int *path);

// 求单源有权最短路径，结果放在path中
void FindWeightedPath(ListGraph graph, Vertex vertex, int *path);

// Dijkstra算法
void Dijkstra(ListGraph graph, int *dist, int *path);

// 打印最短路径
void PrintPath(int *path, Vertex vertex);

// 拓扑排序，将结果放入TopNum数组中
void TopSort(ListGraph graph, int *TopNum);

#endif //GRAPH_LISTGRAPH_H
