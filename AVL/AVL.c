//
// Created by Davy on 2021/2/6.
//

#include "AVL.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct AVLNode {
    int element;
    Node left;
    Node right;
    int height;
};

// 检查树是否为空
int IsEmpty(AVLTree tree) {
    return tree == NULL;
}

// 获取一棵空的AVL树
AVLTree GetEmptyTree() {
    AVLTree ret = NULL;
    return ret;
}

// 清空AVL树
AVLTree MakeEmpty(AVLTree tree) {
    if (!IsEmpty(tree)) {
        MakeEmpty(tree->left);
        MakeEmpty(tree->right);
        free(tree);
    }
    return NULL;
}

// 创建一个新的节点
Node CreateNewNode(int value) {
    Node ret = (Node) malloc(sizeof(struct AVLNode));
    ret->element = value;
    ret->left = NULL;
    ret->right = NULL;
    ret->height = 0;
    return ret;
}

// 根据值获取对应节点
Node Find(AVLTree tree, int value) {
    if (IsEmpty(tree)) {
        return NULL;
    } else if (value == tree->element) {
        return tree;
    } else if (value < tree->element) {
        return Find(tree->left, value);
    } else {
        return Find(tree->right, value);
    }
}

// 找到树中的最大值
Node FindMax(AVLTree tree) {
    if (IsEmpty(tree)) {
        return NULL;
    } else if (IsEmpty(tree->left)) {
        return tree;
    } else {
        return FindMin(tree->left);
    }
}

// 找到树中的最小值
Node FindMin(AVLTree tree) {
    if (IsEmpty(tree)) {
        return NULL;
    } else if (IsEmpty(tree->right)) {
        return tree;
    } else {
        return FindMax(tree->right);
    }
}

// 插入一个节点
AVLTree Insert(AVLTree tree, int value) {
    if (IsEmpty(tree)) {
        tree = CreateNewNode(value);
    } else if (value < tree->element) {
        tree->left = Insert(tree->left, value);
        // 检查左子树高度是否比右子树高度多2，若是，则必须进行旋转
        if (GetHeight(tree->left) - GetHeight(tree->right) == 2) {
            if (value < tree->left->element) {
                // 如果值比左子树根节点小，说明是插入在了左子树的左侧，需要进行一次左单旋转
                tree = SingleRotateWithLeft(tree);
            } else {
                // 如果值比左子树根节点大，说明是插入在了左子树的右侧，需要进行一次左双旋转
                tree = DoubleRotateWithLeft(tree);
            }
        }
    } else if (value > tree->element) {
        tree->right = Insert(tree->right, value);
        // 检查右子树高度是否比左子树高度多2，若是，则必须进行旋转
        if (GetHeight(tree->right) - GetHeight(tree->left) == 2) {
            if (value < tree->right->element) {
                // 如果值比右子树根节点小，说明是插入在了右子树的左侧，需要进行一次右双旋转
                tree = DoubleRotateWithRight(tree);
            } else {
                // 如果值比右子树根节点大，说明是插入在了右子树的右侧，需要进行一次右单旋转
                tree = SingleRotateWithRight(tree);
            }
        }
    }
    // 每插入一次，就更新从根节点到新节点路径上所有节点的高度
    tree->height = UpdateHeight(tree);
    return tree;
}

// 返回一个节点的高度
int GetHeight(Node node) {
    if (IsEmpty(node)) {
        return -1;
    } else {
        return node->height;
    }
}

// 更新一个节点的高度
int UpdateHeight(Node node) {
    // 取两个子树高度的最大值，再加一
    return fmax(GetHeight(node->left), GetHeight(node->right)) + 1;
}

// 左单旋转
AVLTree SingleRotateWithLeft(AVLTree tree) {
    // 进行旋转
    Node NewRoot = tree->left;
    tree->left = NewRoot->right;
    NewRoot->right = tree;
    // 因为进行了旋转，所以要更新两个节点的高度（先更新下面的，再更新上面的）
    tree->height = UpdateHeight(tree);
    NewRoot->height = UpdateHeight(NewRoot);
    // 返回新的根节点
    return NewRoot;
}

// 右单旋转
AVLTree SingleRotateWithRight(AVLTree tree) {
    // 进行旋转
    Node NewRoot = tree->right;
    tree->right = NewRoot->left;
    NewRoot->left = tree;
    // 因为进行了旋转，所以要更新两个节点的高度（先更新下面的，再更新上面的）
    tree->height = UpdateHeight(tree);
    NewRoot->height = UpdateHeight(NewRoot);
    // 返回新的根节点
    return NewRoot;
}

// 左双旋转
AVLTree DoubleRotateWithLeft(AVLTree tree) {
    tree->left = SingleRotateWithRight(tree->left);
    // 不需要更新高度（因为在单旋转中已经更新了）
    return SingleRotateWithLeft(tree);
}

// 右双旋转
AVLTree DoubleRotateWithRight(AVLTree tree) {
    tree->right = SingleRotateWithLeft(tree->right);
    // 不需要更新高度（因为在单旋转中已经更新了）
    return SingleRotateWithRight(tree);
}

// 打印AVL树
void PrintTree(AVLTree tree) {
    if (!IsEmpty(tree)) {
        printf("%d ", tree->element);
        PrintTree(tree->left);
        PrintTree(tree->right);
    }
}