//
// Created by Davy on 2021/2/10.
//

#ifndef DISJOINTSET_DISJOINTSET_H
#define DISJOINTSET_DISJOINTSET_H

typedef int *DisjointSet;

// 获得空的不相交集
DisjointSet GetEmptySet(int size);

// 链接两个元素
void SetUnion(DisjointSet set, int FirstElement, int SecondElement);

// 查询一个元素所属的集合
int Find(DisjointSet set, int element);

// 获取集合的总数
int GetTotalSet(DisjointSet set, int size);

// 打印不相交集
void PrintDisjointSet(DisjointSet set, int size);

#endif //DISJOINTSET_DISJOINTSET_H
