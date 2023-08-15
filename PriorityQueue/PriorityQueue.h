//
// Created by Davy on 2021/2/8.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H

struct BinHeapStruct;
typedef struct BinHeapStruct *PriorityQueue;

// 获取一个空的优先队列
PriorityQueue GetEmptyPriorityQueue(int capacity);

// 删除队列
void Destroy(PriorityQueue queue);

// 清空队列
void MakeEmpty(PriorityQueue queue);

// 向队列中插入一个元素
void Insert(PriorityQueue queue, int value);

// 删除队列的最小元素并返回
int DeleteMin(PriorityQueue queue);

// 返回队列的最小元素
int FindMin(PriorityQueue queue);

// 检查队列是否为空
int IsEmpty(PriorityQueue queue);

// 检查队列是否已满
int IsFull(PriorityQueue queue);

// 打印优先队列
void PrintPriorityQueue(PriorityQueue queue);

// 根据一个数组构建优先队列
PriorityQueue GetPriorityQueue(int capacity, const int *array, int size);

// 降低元素的值
void DecreaseKey(PriorityQueue queue, int position, int change);

// 增加元素的值
void IncreaseKey(PriorityQueue queue, int position, int change);

// 删除指定位置的元素
void Delete(PriorityQueue queue, int position);

#endif //PRIORITYQUEUE_PRIORITYQUEUE_H
