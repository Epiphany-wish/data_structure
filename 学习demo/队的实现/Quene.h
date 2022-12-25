#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElementType;
typedef struct Node
{
	ElementType data;
	struct Node* next;
}Node;
typedef struct Qnode
{
	Node* front;//指向对头节点
	Node* rear;//指向队尾节点
}Quene;
Quene* InitQuene();
void PushQuene(Quene* Q, ElementType item);
void PopQuene(Quene* Q);
ElementType FrontQuene(Quene* Q);
int SizeQuene(Quene* Q);
bool EmptyQuene(Quene* Q);
void DestroyQuene(Quene* Q);