//
// Created by Davy on 2021/2/20.
//

#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

// 检查队列是否为空
int IsEmpty(Queue queue) {
    return queue->size == 0;
}

// 判断队列是否已满
int IsFull(Queue queue) {
    return queue->size == queue->capacity;
}

// 创建空的队列
Queue CreateEmptyQueue(int capacity) {
    Queue ret = (Queue) malloc(sizeof(struct QueueNode));
    ret->capacity = capacity;
    ret->size = 0;
    ret->front = 0;
    ret->rear = -1;
    ret->array = (ElementType *) malloc(sizeof(ElementType) * capacity);
    return ret;
}

// 删除队列
void DeleteQueue(Queue queue) {
    free(queue->array);
    free(queue);
}

// 清空队列
void MakeEmpty(Queue queue) {
    if (!IsEmpty(queue)) {
        queue->size = 0;
        queue->front = 0;
        queue->rear = -1;
        free(queue->array);
        queue->array = (ElementType *) malloc(sizeof(ElementType) * queue->capacity);
    }
}

// 入队
void Enqueue(Queue queue, ElementType value) {
    if (!IsFull(queue)) {
        queue->size++;
        if (++queue->rear == queue->capacity) {
            queue->rear = 0;
        }
        queue->array[queue->rear] = value;
    } else {
        printf("Queue is full!\n");
    }
}

// 获取队列首元素
ElementType GetFront(Queue queue) {
    if (!IsEmpty(queue)) {
        return queue->array[queue->front];
    } else {
        printf("Queue is empty!\n");
        exit(-1);
    }
}

// 出队
ElementType Dequeue(Queue queue) {
    if (!IsEmpty(queue)) {
        queue->size--;
        ElementType ret = queue->array[queue->front];
        if (++queue->front == queue->capacity) {
            queue->front = 0;
        }
        return ret;
    } else {
        printf("Queue is empty!\n");
        exit(-1);
    }
}

// 打印队列
void PrintQueue(Queue queue) {
    if (!IsEmpty(queue)) {
        for (int i = queue->front; i != queue->rear;) {
            printf("%d ", queue->array[i]);
            if (++i == queue->capacity) {
                i = 0;
            }
        }
        printf("%d", queue->array[queue->rear]);
    } else {
        printf("Queue is empty!\n");
    }
}
