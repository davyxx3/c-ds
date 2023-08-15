//
// Created by Davy on 2021/2/6.
//
#include <stdio.h>
#include "BST.h"

int main(int argc, char **argv) {
    BST tree = GetEmptyBST();
    tree = Insert(tree, 5);
    tree = Insert(tree, 3);
    tree = Insert(tree, 4);
    tree = Insert(tree, 6);
    tree = Insert(tree, 1);
    tree = Insert(tree, 2);
    printf("size: %d\n", GetSize(tree));
    printf("max value: %d\n", GetElement(FindMax(tree)));
    printf("min value: %d\n", GetElement(FindMin(tree)));
    PrintTree(tree);
    printf("\n");
    printf("%d\n", GetElement(Find(tree, 2)));
    tree = Delete(tree, 3);
    PrintTree(tree);
    tree = MakeEmpty(tree);
    PrintTree(tree);
}

