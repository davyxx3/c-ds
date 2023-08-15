//
// Created by Davy on 2021/2/5.
//

#include <stdio.h>
#include "LinkedList.h"

int main(int argc, char **argv) {
    LinkedList list = GetEmptyList();
    Add(list, 8);
    Add(list, 10);
    Add(list, 12);
    Add(list, 13);
/*    Delete(list, 12);
    PrintList(list);
    printf("%d\n", GetElement(GetNode(list, 0)));
    printf("%d\n", GetSize(list));*/
    PrintList(list);
    ReverseList(list);
    PrintList(list);
    return 0;
}
