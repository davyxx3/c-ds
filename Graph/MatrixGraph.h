//
// Created by Davy on 2021/2/18.
//

#ifndef GRAPH_MATRIXGRAPH_H
#define GRAPH_MATRIXGRAPH_H

struct AdjacencyMatrixGraphNode;
struct EdgeNode;

typedef struct AdjacencyMatrixGraphNode *AdjacencyMatrixGraph;
typedef struct EdgeNode *Edge;
typedef int Vertex;
typedef int WeightType;

struct AdjacencyMatrixGraphNode {
    int VertexNum;
    int EdgeNum;
    WeightType **AdjacencyMatrix;
    int IsDirected;
};

struct EdgeNode {
    Vertex from;
    Vertex to;
    WeightType weight;
};

// 初始化一个没有边的图
AdjacencyMatrixGraph CreateGraph(int VertexNum);

// 插入一条边
void InsertEdge(AdjacencyMatrixGraph graph, Edge edge);

// 建立一个图
AdjacencyMatrixGraph BuildGraph();

// 打印一个图
void PrintGraph(AdjacencyMatrixGraph graph);


#endif //GRAPH_MATRIXGRAPH_H
