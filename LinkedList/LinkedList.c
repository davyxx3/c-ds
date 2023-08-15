//
// Created by Davy on 2021/2/5.
//

#include"LinkedList.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

// 节点结构的声明
struct NodeStructure {
    int element;
    Node next;
};

// 得到一个空的链表
LinkedList GetEmptyList() {
    // 创建头节点
    LinkedList ret = (LinkedList) malloc(sizeof(struct NodeStructure));
    ret->element = 0;
    ret->next = NULL;
    return ret;
}

// 将链表清空为初始状态
LinkedList MakeEmpty(LinkedList list) {
    if (!IsEmpty(list)) {
        DeleteList(FindFirst(list));
        list->next = NULL;
    }
    return list;
}

// 检查链表是否为空
int IsEmpty(LinkedList list) {
    return list->next == NULL;
}

// 检查此节点是否为链表的最后一个节点
int IsLast(LinkedList list, Node node) {
    if (!IsEmpty(list)) {
        list = FindLast(list);
        return list == node;
    } else {
        return 0;
    }
}

// 根据传入的值寻找其在链表中的位置
Node Find(LinkedList list, int value) {
    if (!IsEmpty(list)) {
        list = FindFirst(list);
        while (list != NULL) {
            if (list->element == value) {
                return list;
            }
            list = list->next;
        }
        return NULL;
    } else {
        return NULL;
    }
}

// 删除含有传入的值的节点
void Delete(LinkedList list, int value) {
    if (!IsEmpty(list)) {
        Node position = Find(list, value);
        Node PreviousNode = FindPrevious(list, value);
        if (position != NULL && PreviousNode != NULL) {
            Node NextNode = position->next;
            PreviousNode->next = NextNode;
        }
        free(position);
    }
}

// 寻找含有传入值的前一个节点
Node FindPrevious(LinkedList list, int value) {
    if (!IsEmpty(list)) {
        while (list->next != NULL) {
            if (list->next->element == value) {
                return list;
            }
            list = list->next;
        }
        return NULL;
    }
    return NULL;
}

// 在相应位置插入一个值
void Insert(LinkedList list, Node position, int value) {

}

// 删除链表
void DeleteList(LinkedList list) {
    while (list != NULL) {
        Node tem = list;
        list = list->next;
        free(tem);
    }
}

// 在链表末尾添加一个节点
void Add(LinkedList list, int value) {
    if (!IsEmpty(list)) {
        Node last = FindLast(list);
        Node NewNode = CreateNewNode(value);
        last->next = NewNode;
    } else {
        list->next = CreateNewNode(value);
    }
}

// 寻找链表的最后一个节点
Node FindLast(LinkedList list) {
    if (!IsEmpty(list)) {
        while (list->next != NULL) {
            list = list->next;
        }
        return list;
    } else {
        return NULL;
    }
}

// 返回当前链表的节点数
int GetSize(LinkedList list) {
    if (!IsEmpty(list)) {
        list = FindFirst(list);
        int TotalSize = 0;
        while (list != NULL) {
            TotalSize++;
            list = list->next;
        }
        return TotalSize;
    } else {
        return 0;
    }
}

// 返回当前链表的第一个节点
Node FindFirst(LinkedList list) {
    if (!IsEmpty(list)) {
        return list->next;
    } else {
        return NULL;
    }
}

// 创建一个新节点
Node CreateNewNode(int value) {
    Node ret = (Node) malloc(sizeof(struct NodeStructure));
    ret->element = value;
    ret->next = NULL;
    return ret;
}

// 检查此节点是否为链表的头节点
int IsHeader(LinkedList list, Node node) {
    return list == node;
}

// 输出链表到标准输出流
void PrintList(LinkedList list) {
    if (!IsEmpty(list)) {
        list = FindFirst(list);
        while (list != NULL) {
            printf("%d  ", list->element);
            list = list->next;
        }
        printf("\n");
    } else {
        printf("List is empty!\n");
    }
}

// 根据节点得到索引（从0开始）
int GetIndex(LinkedList list, Node node) {
    if (node == NULL) {
        return -1;
    }
    if (!IsEmpty(list)) {
        int ListSize = GetSize(list);
        list = FindFirst(list);
        for (int i = 0; i < ListSize; ++i) {
            if (list == node) {
                return i;
            }
            list = list->next;
        }
        return -1;
    } else {
        return -1;
    }
}

// 获取节点中的值
int GetElement(Node node) {
    if (node != NULL) {
        return node->element;
    } else {
        exit(-1);
    }
}

// 根据索引获取节点
Node GetNode(LinkedList list, int index) {
    int ListSize = GetSize(list);
    if (index < 0 || index > ListSize) {
        return NULL;
    }
    list = FindFirst(list);
    while (index != 0) {
        list = list->next;
        index--;
    }
    return list;
}

/*// 链表反转（方法一）
void ReverseList(LinkedList list) {
    Node first = FindFirst(list);
    Node i, j, k;
    for (i = first, j = first->next, k = j->next; j != NULL; i = j, j = k, k = (k == NULL ? NULL : k->next)) {
        j->next = i;
    }
    first->next = NULL;
    list->next = i;
}*/

// 链表反转（方法二）
void ReverseList(LinkedList list) {
    Node header = list;
    Node first = FindFirst(list);
    Node i, j;
    for (i = first->next, j = first; j->next != NULL; i = j->next) {
        j->next = i->next;
        Node OldFirst = header->next;
        header->next = i;
        i->next = OldFirst;
    }
}

/*// 链表反转（方法三）
void ReverseList(LinkedList list) {
    LinkedList ReversedList = GetEmptyList();
    for (Node i = FindFirst(list); i != NULL; i = i->next) {
        Node NewNode = CreateNewNode(i->element);
        NewNode->next = ReversedList->next;
        ReversedList->next = NewNode;
    }
    MakeEmpty(list);
    list->next = ReversedList->next;
}*/

