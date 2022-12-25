#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElementType;//ElementType 暂时定义为 int 类型
typedef struct Snode
{
	ElementType* data;// 存储堆栈元素
	int top;//栈顶元素下一个的下标
	int capacity;//栈的容量
}Stack;
Stack CreatStack();
void Stackpush(Stack* s, ElementType item);
void Stackpop(Stack* s);
int Stacksize(Stack* s);
ElementType Stacktop(Stack* s);
bool Stackempty(Stack* s);
void DestroyStack(Stack* s);