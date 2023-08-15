//
// Created by Davy on 2021/2/20.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef int ElementType;

struct QueueNode {
    int capacity;
    int front;
    int rear;
    int size;
    int *array;
};

typedef struct QueueNode *Queue;

// 检查队列是否为空
int IsEmpty(Queue queue);

// 判断队列是否已满
int IsFull(Queue queue);

// 创建空的队列
Queue CreateEmptyQueue(int capacity);

// 删除队列
void DeleteQueue(Queue queue);

// 清空队列
void MakeEmpty(Queue queue);

// 入队
void Enqueue(Queue queue, ElementType value);

// 获取队列首元素
ElementType GetFront(Queue queue);

// 出队
ElementType Dequeue(Queue queue);

// 打印队列
void PrintQueue(Queue queue);

#endif //QUEUE_QUEUE_H
