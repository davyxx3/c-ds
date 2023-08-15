//
// Created by Davy on 2021/2/5.
//

#ifndef ALGO_BST_H
#define ALGO_BST_H

struct TreeNode;

typedef struct TreeNode *Node;
typedef struct TreeNode *BST;

// 获得一棵空的二叉搜索树
BST GetEmptyBST();

// 清空二叉搜索树为初始状态
BST MakeEmpty(BST tree);

// 寻找传入值对应的节点
Node Find(BST tree, int value);

// 寻找最小值节点
Node FindMin(BST tree);

// 寻找最大值节点
Node FindMax(BST tree);

// 插入一个节点
BST Insert(BST tree, int value);

// 删除一个节点
BST Delete(BST tree, int value);

// 返回节点的元素
int GetElement(Node node);

// 获得二叉搜索树的节点个数
int GetSize(BST tree);

// 打印二叉搜索树
void PrintTree(BST tree);

// 判断二叉搜索树是否为空
int IsEmpty(BST tree);

// 创建一个新的节点
Node CreateNewNode(int value);

// 判断一个节点是否为叶子节点
int IsLeaf(Node node);

struct TreeNode {
    int element;
    BST left;
    BST right;
};

#endif //ALGO_BST_H
