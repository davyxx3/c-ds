//
// Created by Davy on 2021/2/10.
//

#include <stdlib.h>
#include <stdio.h>
#include "DisjointSet.h"

// 获得一个初始的不相交集
DisjointSet GetEmptySet(int size) {
    DisjointSet ret = (DisjointSet) malloc(sizeof(int) * (size + 1));
    for (int i = 1; i <= size; i++) {
        ret[i] = 0;
    }
    return ret;
}

// 链接两个元素
void SetUnion(DisjointSet set, int FirstElement, int SecondElement) {
    int FirstUnion = Find(set, FirstElement);
    int SecondUnion = Find(set, SecondElement);
    // 按高度求并
    if (FirstUnion != SecondUnion) {
        if (set[FirstUnion] > set[SecondUnion]) {
            // 当第二课树比较高时，把第一颗树连接到第二棵树上
            set[FirstUnion] = SecondUnion;
        } else {
            // 否则把第二棵树连接到第一棵树上
            if (set[FirstUnion] == set[SecondUnion]) {
                // 若两棵树高度相同，则高度加1
                set[FirstUnion]--;
            }
            set[SecondUnion] = FirstUnion;
        }
        printf("链接成功！\n");
    } else {
        printf("链接失败！这两个元素已经处于链接状态了！\n");
    }
}

// 查询一个元素所属的集合
int Find(DisjointSet set, int element) {
    if (set[element] <= 0) {
        return element;
    } else {
        // 路径压缩
        return set[element] = Find(set, set[element]);
    }
}

// 获取集合的总数
int GetTotalSet(DisjointSet set, int size) {
    int TotalSet = 0;
    for (int i = 1; i <= size; ++i) {
        if (set[i] <= 0) {
            TotalSet++;
        }
    }
    return TotalSet;
}

// 打印不相交集
void PrintDisjointSet(DisjointSet set, int size) {
    for (int i = 1; i <= size; ++i) {
        printf("%d ", set[i]);
    }
}
