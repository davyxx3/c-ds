//
// Created by Davy on 2021/2/20.
//

#include "Queue.h"

int main(int argc, char **argv) {
    Queue queue = CreateEmptyQueue(10);
    Enqueue(queue, 4);
    Enqueue(queue, 1);
    Enqueue(queue, 6);
    Dequeue(queue);
    Enqueue(queue, 10);
    Dequeue(queue);
    Enqueue(queue, 0);
    Enqueue(queue, 11);
    Enqueue(queue, 12);
    Enqueue(queue, 13);
    Dequeue(queue);
    PrintQueue(queue);
}

