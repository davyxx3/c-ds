//
// Created by Davy on 2021/2/5.
//

#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

// 获得一棵空的二叉搜索树
BST GetEmptyBST() {
    BST ret = NULL;
    return ret;
}

// 清空二叉搜索树为初始状态
BST MakeEmpty(BST tree) {
    if (!IsEmpty(tree)) {
        MakeEmpty(tree->left);
        MakeEmpty(tree->right);
        free(tree);
    }
    return NULL;
}

// 寻找传入值对应的节点
Node Find(BST tree, int value) {
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

// 寻找最小值节点
Node FindMin(BST tree) {
    if (IsEmpty(tree)) {
        return NULL;
    } else if (IsEmpty(tree->left)) {
        return tree;
    } else {
        return FindMin(tree->left);
    }
}

// 寻找最大值节点
Node FindMax(BST tree) {
    if (IsEmpty(tree)) {
        return NULL;
    } else if (IsEmpty(tree->right)) {
        return tree;
    } else {
        return FindMax(tree->right);
    }
}

// 插入一个节点
BST Insert(BST tree, int value) {
    if (IsEmpty(tree)) {
        return CreateNewNode(value);
    } else if (value < tree->element) {
        tree->left = Insert(tree->left, value);
        return tree;
    } else if (value > tree->element) {
        tree->right = Insert(tree->right, value);
        return tree;
    } else {
        printf("该值已存在！\n");
        return tree;
    }
}

// 删除一个节点
BST Delete(BST tree, int value) {
    if (IsEmpty(tree)) {
        printf("树为空！");
        return NULL;
    } else if (value < tree->element) {
        tree->left = Delete(tree->left, value);
        return tree;
    } else if (value > tree->element) {
        tree->right = Delete(tree->right, value);
        return tree;
    } else {
        if (tree->left != NULL && tree->right != NULL) {
            Node ReplacedNode = FindMin(tree->right);
            tree->element = ReplacedNode->element;
            tree->right = Delete(tree->right, ReplacedNode->element);
            return tree;
        } else {
            Node ret = NULL;
            if (tree->left == NULL) {
                ret = tree->right;
            } else {
                ret = tree->left;
            }
            free(tree);
            return ret;
        }
    }
}

// 返回节点的元素
int GetElement(Node node) {
    return node->element;
}

// 获得二叉搜索树的节点个数
int GetSize(BST tree) {
    if (IsEmpty(tree)) {
        return 0;
    } else {
        return GetSize(tree->left) + GetSize(tree->right) + 1;
    }
}

// 打印二叉搜索树
void PrintTree(BST tree) {
    if (!IsEmpty(tree)) {
        printf("%d  ", tree->element);
        PrintTree(tree->left);
        PrintTree(tree->right);
    }
}

// 创建一个新的节点
Node CreateNewNode(int value) {
    Node ret = (Node) malloc(sizeof(struct TreeNode));
    ret->element = value;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

// 判断二叉搜索树是否为空
int IsEmpty(BST tree) {
    return tree == NULL;
}

// 判断一个节点是否为叶子节点
int IsLeaf(Node node) {
    return node->left == NULL && node->right == NULL;
}
