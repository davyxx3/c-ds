//
// Created by Davy on 2021/2/7.
//

#include "AVL.h"

int main(int argc, char **argv) {
    AVLTree tree = GetEmptyTree();
    tree = Insert(tree, 3);
    tree = Insert(tree, 2);
    tree = Insert(tree, 1);
    tree = Insert(tree, 4);
    tree = Insert(tree, 5);
    tree = Insert(tree, 6);
    tree = Insert(tree, 7);
    tree = Insert(tree, 16);
    tree = Insert(tree, 15);
    tree = Insert(tree, 14);
    tree = Insert(tree, 13);
    tree = Insert(tree, 12);
    tree = Insert(tree, 11);
    tree = Insert(tree, 10);
    tree = Insert(tree, 8);
    tree = Insert(tree, 9);
    PrintTree(tree);
}

