//
// Created by Davy on 2021/2/5.
//

#ifndef ALGO_LINKEDLIST_H
#define ALGO_LINKEDLIST_H

struct NodeStructure;

typedef struct NodeStructure *Node;
typedef Node LinkedList;

// 得到一个空的链表
LinkedList GetEmptyList();

// 将链表清空为初始状态
LinkedList MakeEmpty(LinkedList list);

// 检查链表是否为空
int IsEmpty(LinkedList list);

// 检查此节点是否为链表的最后一个节点
int IsLast(LinkedList list, Node node);

// 根据传入的值寻找其在链表中的位置
Node Find(LinkedList list, int value);

// 删除含有传入的值的节点
void Delete(LinkedList list, int value);

// 寻找含有传入值的前一个节点
Node FindPrevious(LinkedList list, int value);

// 在相应位置插入一个值
void Insert(LinkedList list, Node position, int value);

// 删除链表
void DeleteList(LinkedList list);

// 在链表末尾添加一个节点
void Add(LinkedList list, int value);

// 寻找链表的最后一个节点
Node FindLast(LinkedList list);

// 返回当前链表的节点数
int GetSize(LinkedList list);

// 返回当前链表的第一个节点
Node FindFirst(LinkedList list);

// 创建一个新节点
Node CreateNewNode(int value);

// 检查此节点是否为链表的头节点
int IsHeader(LinkedList list, Node node);

// 输出链表到标准输出流
void PrintList(LinkedList list);

// 根据节点得到索引（从0开始）
int GetIndex(LinkedList list, Node node);

// 获取节点中的值
int GetElement(Node node);

// 根据索引获取节点
Node GetNode(LinkedList list, int index);

// 链表反转
void ReverseList(LinkedList list);

#endif //ALGO_LINKEDLIST_H
