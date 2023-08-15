//
// Created by Davy on 2021/2/8.
//

#include <stdio.h>
#include "PriorityQueue.h"

int main(int argc, char **argv) {
    PriorityQueue queue1 = GetEmptyPriorityQueue(20);
    Insert(queue1, 21);
    Insert(queue1, 16);
    Insert(queue1, 13);
    Insert(queue1, 32);
    Insert(queue1, 26);
    Insert(queue1, 65);
    Insert(queue1, 68);
    Insert(queue1, 19);
    Insert(queue1, 31);
    Insert(queue1, 24);
/*    int array[10] = {21, 16, 13, 32, 26, 65, 68, 19, 31, 24};
    PriorityQueue queue2 = GetPriorityQueue(20, array, 10);
    PrintPriorityQueue(queue2);
    DeleteMin(queue2);
    printf("***************\n");
    PrintPriorityQueue(queue2);*/
    PrintPriorityQueue(queue1);
    printf("***************\n");
    DecreaseKey(queue1, 10, 15);
    PrintPriorityQueue(queue1);

}

