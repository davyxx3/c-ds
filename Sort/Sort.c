//
// Created by Davy on 2021/2/9.
//

#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

// 在归并排序中，获取结果数组
int *GetResultArray(int size);

// 在归并排序中，进行两个数组的归并
void Merge(int *array, int *ResultArray, int begin, int mid, int end);

// 在归并排序中，执行递归归并
void MergeSortProcess(int *array, int *ResultArray, int begin, int end);

// 在快速排序中，进行排序处理
void QuickSortProcess(int *array, int begin, int end);

// 交换数组中的两个元素
void Exchange(int *array, int first, int second);

// 在快速排序中实现中值分割
int MedianSplit(int *array, int begin, int end);

// 插入排序
void InsertionSort(int *array, int size) {
    // 针对每个元素
    for (int i = 1; i < size; ++i) {
        // 先保存当前元素
        int temp = array[i];
        // position记录插入的位置
        int position;
        // 若前一个值大于当前元素，则把前一个值右移到当前位置，然后position-1
        for (position = i; temp < array[position - 1] && position > 0; position--) {
            array[position] = array[position - 1];
        }
        array[position] = temp;
    }
}

// 希尔排序
void ShellSort(int *array, int size) {
    // 最外层循环控制递增序列
    for (int i = size / 2; i > 0; i /= 2) {
        // 第二层循环控制当前元素
        for (int j = i; j < size; j++) {
            int temp = array[j];
            int position;
            // 第三层循环寻找插入位置
            for (position = j; temp < array[position - i] && position > 0; position -= i) {
                array[position] = array[position - i];
            }
            array[position] = temp;
        }
    }
}

// 归并排序
void MergeSort(int *array, int size) {
    // 创建结果数组
    int *ResultArray = GetResultArray(size);
    // 执行递归归并
    MergeSortProcess(array, ResultArray, 0, size);
    // 删除结果数组
    free(ResultArray);
}

// 在归并排序中，执行递归归并
void MergeSortProcess(int *array, int *ResultArray, int begin, int end) {
    // 若数组长度不为1
    if (end - begin != 1) {
        // 获取中间位置
        int mid = (begin + end) / 2;
        // 使左边的序列有序
        MergeSortProcess(array, ResultArray, begin, mid);
        // 使右边的序列有序
        MergeSortProcess(array, ResultArray, mid, end);
        // 归并两个有序的序列
        Merge(array, ResultArray, begin, mid, end);
    }
}

// 在归并排序中，获取结果数组
int *GetResultArray(int size) {
    return (int *) malloc(size * sizeof(int));
}

void Merge(int *array, int *ResultArray, int begin, int mid, int end) {
    // i取左边，j取右边，k放入结果数组
    int i, j, k;
    // 进行归并直到有一边取完为止
    for (i = k = begin, j = mid; i < mid && j < end; k++) {
        if (array[i] < array[j]) {
            // 若左边的元素较小，则放入结果数组
            ResultArray[k] = array[i++];
        } else {
            // 反之放入右边的元素
            ResultArray[k] = array[j++];
        }
    }
    // 若左边没取完，则一直取完左边的数组
    while (i < mid) {
        ResultArray[k++] = array[i++];
    }
    // 若右边没取完，则一直取完右边的数组
    while (j < end) {
        ResultArray[k++] = array[j++];
    }
    // 复制回原数组
    for (i = begin; i < end; i++) {
        array[i] = ResultArray[i];
    }
}

// 快速排序
void QuickSort(int *array, int size) {
    // 快速排序的处理程序
    QuickSortProcess(array, 0, size);
}

// 在快速排序中，进行排序处理
void QuickSortProcess(int *array, int begin, int end) {
    // 如果数组长度大于等于10，才使用快速排序，否则使用插入排序（速度更快）
    if (end - begin >= 10) {
        // 获取枢纽值
        int pivot = MedianSplit(array, begin, end);
        // i、j用于遍历数组，交换元素
        int i, j;
        // 开始时，i处于数组开头，j处于枢纽元处（因为这两个元素都已经在中值分割中归位，所以不用判断）
        for (i = begin, j = end - 2;;) {
            // i找到大于枢纽值的元素
            while (array[++i] < pivot) {}
            // j找到小于枢纽值的元素
            while (array[--j] > pivot) {}
            // 若i、j没有相遇过，则说明没遍历完，交换元素
            if (i < j) {
                // 交换元素
                Exchange(array, i, j);
            } else {
                // 若i、j已经相遇，则说明遍历完成，退出循环
                break;
            }
        }
        // 当前i位置的元素就是大于枢纽值的元素，则交换此元素和枢纽值
        Exchange(array, i, end - 2);
        // 递归排序左边
        QuickSortProcess(array, begin, i);
        // 递归排序右边
        QuickSortProcess(array, i + 1, end);
    } else {
        // 使用插入排序
        InsertionSort(array + begin, end - begin);
    }
}

// 在快速排序中实现中值分割
int MedianSplit(int *array, int begin, int end) {
    // 获取中间位置
    int mid = (begin + end) / 2;
    // 排序三个位置的值
    if (array[begin] > array[mid]) {
        Exchange(array, begin, mid);
    }
    if (array[begin] > array[end]) {
        Exchange(array, begin, end - 1);
    }
    if (array[mid] > array[end]) {
        Exchange(array, mid, end - 1);
    }
    // 排序完成后，把枢纽值放在数组倒数第二个元素
    Exchange(array, mid, end - 2);
    // 返回枢纽值
    return array[end - 2];
}

// 交换数组中的两个元素
void Exchange(int *array, int first, int second) {
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

// 打印数组
void PrintArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}
