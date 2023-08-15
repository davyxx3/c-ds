//
// Created by Davy on 2021/2/8.
//

#include <stdlib.h>
#include <stdio.h>
#include "PriorityQueue.h"
#include <math.h>

struct BinHeapStruct {
    int capacity;
    int size;
    int *elements;
};

// 检查一个节点是否只有一个子节点
int HasOnlyOneChild(PriorityQueue queue, int index);

// 传入两个索引，返回值最小的那个
int FindMinPosition(PriorityQueue queue, int LeftIndex, int RightIndex);

// 获取队列的最后一个元素
int GetLastElement(PriorityQueue queue);

// 获取二叉堆的行数
int GetRow(PriorityQueue queue);

// 下滤
void PercolateDown(PriorityQueue queue, int position);

// 上滤
void PercolateUp(PriorityQueue queue, int position);

// 在传入数组构建优先队列前，进行合法性检查
int BuildCheck(int capacity, const int *array, int size);

// 复制一个数组的内容到另一个数组
void ArrayCopy(const int *from, int *to, int size);


// 检查一个节点是否只有一个子节点
int HasOnlyOneChild(PriorityQueue queue, int index) {
    return 2 * index == queue->size;
}

// 传入两个索引，返回值最小的那个
int FindMinPosition(PriorityQueue queue, int LeftIndex, int RightIndex) {
    return queue->elements[LeftIndex] > queue->elements[RightIndex] ? RightIndex : LeftIndex;
}

// 获取队列的最后一个元素
int GetLastElement(PriorityQueue queue) {
    return queue->elements[queue->size];
}

// 获取二叉堆的行数
int GetRow(PriorityQueue queue) {
    return ((int) (log(queue->size) / log(2))) + 1;
}

// 下滤
void PercolateDown(PriorityQueue queue, int position) {
    // 记录下滤元素的值
    int temp = queue->elements[position];
    // i用于记录插入位置，MinChild记录最小儿子节点
    int i, MinChild;
    // 一路沿堆向下寻找插入的位置
    for (i = position; 2 * i <= queue->size; i = MinChild) {
        if (HasOnlyOneChild(queue, i)) {
            // 如果只有节点只有一个儿子，则最小儿子为左儿子
            MinChild = 2 * i;
        } else {
            // 如果节点有两个儿子，则在左右儿子中选出最小儿子
            MinChild = FindMinPosition(queue, 2 * i, 2 * i + 1);
        }
        if (temp > queue->elements[MinChild]) {
            // 若下滤元素的值大于这个最小儿子，则用最小儿子作为当前节点的值
            queue->elements[i] = queue->elements[MinChild];
        } else {
            // 若下滤元素的值小于最小儿子，则说明已经找到插入位置，直接终止循环即可
            break;
        }
    }
    // 向插入位置插入元素
    queue->elements[i] = temp;
}

// 上滤
void PercolateUp(PriorityQueue queue, int position) {
    // 记录上滤元素的值
    int temp = queue->elements[position];
    // i记录插入位置
    int i;
    // 一路沿堆向上寻找插入的位置
    for (i = position; temp < queue->elements[i / 2] && i != 1; i /= 2) {
        // 当上滤元素的值小于根节点的值，说明插入位置为根节点，则把当前位置的值用根节点的值代替
        queue->elements[i] = queue->elements[i / 2];
    }
    queue->elements[i] = temp;
}

// 在传入数组构建优先队列前，进行合法性检查
int BuildCheck(int capacity, const int *array, int size) {
    if (capacity <= 0) {
        printf("队列容量必须大于0！");
        return 0;
    }
    if (size <= 0) {
        printf("数组容量必须大于0！");
        return 0;
    }
    if (array == NULL) {
        printf("数组为空！");
        return 0;
    }
    if (capacity < size) {
        printf("队列容量不能小于数组的大小！");
        return 0;
    }
    return 1;
}

// 复制一个数组的内容到优先队列数组（假定队列数组的长度足够长）
void ArrayCopy(const int *from, int *to, int size) {
    for (int i = 0; i < size; i++) {
        to[i + 1] = from[i];
    }
}

// 获取一个空的优先队列
PriorityQueue GetEmptyPriorityQueue(int capacity) {
    if (capacity > 0) {
        PriorityQueue ret = (PriorityQueue) malloc(sizeof(struct BinHeapStruct));
        ret->capacity = capacity;
        ret->size = 0;
        // 注意：数组的容量要加1，因为数组的下标是从0开始的
        ret->elements = (int *) malloc(sizeof(int) * (capacity + 1));
        return ret;
    } else {
        printf("队列容量不能小于等于0！");
        return NULL;
    }
}

// 删除队列
void Destroy(PriorityQueue queue) {
    free(queue->elements);
    free(queue);
}

// 清空队列
void MakeEmpty(PriorityQueue queue) {
    if (!IsEmpty(queue)) {
        queue->elements = (int *) malloc(sizeof(int) * (queue->capacity));
        queue->size = 0;
    }
}

// 向队列中插入一个元素
void Insert(PriorityQueue queue, int value) {
    if (!IsFull(queue)) {
        // 插入位置为数组的下一个空闲位置
        int position = ++queue->size;
        // 将值插入
        queue->elements[position] = value;
        // 上滤，使元素处在正确的位置
        PercolateUp(queue, position);
    } else {
        printf("队列已满！插入失败！");
    }
}

// 删除队列的最小元素并返回
int DeleteMin(PriorityQueue queue) {
    if (!IsEmpty(queue)) {
        // 保存返回的值
        int ret = queue->elements[1];
        // 将数组最后一个值放到最前面
        queue->elements[1] = GetLastElement(queue);
        // 数组大小减1
        queue->size--;
        // 下滤，使元素处在正确的位置
        PercolateDown(queue, 1);
        return ret;
    } else {
        printf("队列为空！");
        return INT_MAX;
    }
}

// 返回队列的最小元素
int FindMin(PriorityQueue queue) {
    if (!IsEmpty(queue)) {
        return queue->elements[1];
    } else {
        printf("队列为空！");
        return INT_MAX;
    }
}

// 检查队列是否为空
int IsEmpty(PriorityQueue queue) {
    return queue->size == 0;
}

// 检查队列是否已满
int IsFull(PriorityQueue queue) {
    return queue->size == queue->capacity;
}

// 打印优先队列
void PrintPriorityQueue(PriorityQueue queue) {
    if (!IsEmpty(queue)) {
        int row = GetRow(queue);
        // i控制行数
        for (int i = 0; i < row; i++) {
            // 在打印每一行前，先打印一些用于缩进的空格
            for (int j = 2 * (row - i); j > 0; j--) {
                printf(" ");
            }
            // 确定开始打印的元素索引
            int index = (int) pow(2, i);
            // 打印元素
            for (int j = index; j < 2 * index && j <= queue->size; j++) {
                printf("%d ", queue->elements[j]);
            }
            // 打印换行符
            printf("\n");
        }
    } else {
        printf("队列为空！");
    }
}

// 根据一个数组构建优先队列
PriorityQueue GetPriorityQueue(int capacity, const int *array, int size) {
    if (BuildCheck(capacity, array, size)) {
        PriorityQueue ret = GetEmptyPriorityQueue(capacity);
        if (ret != NULL) {
            // 复制数组到队列中
            ArrayCopy(array, ret->elements, size);
            ret->size = size;
            // 循环进行下滤
            for (int i = size / 2; i > 0; i--) {
                PercolateDown(ret, i);
            }
            return ret;
        }
    }
    return NULL;
}

// 降低元素的值
void DecreaseKey(PriorityQueue queue, int position, int change) {
    if (position <= 0 || position > queue->size) {
        printf("位置错误！");
        return;
    } else if (change < 0) {
        printf("改变值不能为负数！");
        return;
    } else {
        // 对应元素减去改变值
        queue->elements[position] -= change;
        // 上滤
        PercolateUp(queue, position);
    }
}

// 增加元素的值
void IncreaseKey(PriorityQueue queue, int position, int change) {
    if (position <= 0 || position > queue->size) {
        printf("位置错误！");
        return;
    } else if (change < 0) {
        printf("改变值不能为负数！");
        return;
    } else {
        // 对应元素加上改变值
        queue->elements[position] += change;
        // 下滤
        PercolateDown(queue, position);
    }
}

// 删除指定位置的元素
void Delete(PriorityQueue queue, int position) {
    if (position <= 0 || position > queue->size) {
        printf("位置错误！");
        return;
    } else {
        // 先将指定位置的元素值设置为无限小
        DecreaseKey(queue, position, 9999);
        // 再删除最小值即可
        DeleteMin(queue);
    }
}
