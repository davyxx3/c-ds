//
// Created by Davy on 2021/2/10.
//

#include <stdio.h>
#include "DisjointSet.h"

int main(int argc, char **argv) {
    DisjointSet set = GetEmptySet(10);
    SetUnion(set, 1, 5);
    SetUnion(set, 2, 8);
    SetUnion(set, 2, 7);
    SetUnion(set, 1, 9);
    SetUnion(set, 3, 4);
    SetUnion(set, 6, 10);
    SetUnion(set, 6, 10);
    printf("total set: %d\n", GetTotalSet(set, 10));
    PrintDisjointSet(set, 10);
}

