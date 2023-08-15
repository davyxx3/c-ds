//
// Created by Davy on 2021/2/6.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H

struct AVLNode;
typedef struct AVLNode *Node;
typedef struct AVLNode *AVLTree;

// 检查树是否为空
int IsEmpty(AVLTree tree);

// 获取一棵空的AVL树
AVLTree GetEmptyTree();

// 清空AVL树
AVLTree MakeEmpty(AVLTree tree);

// 创建一个新的节点
Node CreateNewNode(int value);

// 根据值获取对应节点
Node Find(AVLTree tree, int value);

// 找到树中的最大值
Node FindMax(AVLTree tree);

// 找到树中的最小值
Node FindMin(AVLTree tree);

// 插入一个节点
AVLTree Insert(AVLTree tree, int value);

// 返回一个节点的高度
int GetHeight(Node node);

// 更新一个节点的高度
int UpdateHeight(Node node);

// 左单旋转
AVLTree SingleRotateWithLeft(AVLTree tree);

// 右单旋转
AVLTree SingleRotateWithRight(AVLTree tree);

// 左双旋转
AVLTree DoubleRotateWithLeft(AVLTree tree);

// 右双旋转
AVLTree DoubleRotateWithRight(AVLTree tree);

// 打印AVL树
void PrintTree(AVLTree tree);

#endif //AVL_AVL_H
