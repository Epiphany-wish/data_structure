#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int ElementType;//ElementType ��ʱ����Ϊ int ����
typedef struct Snode
{
	ElementType* data;// �洢��ջԪ��
	int top;//ջ��Ԫ����һ�����±�
	int capacity;//ջ������
}Stack;
Stack CreatStack();
void Stackpush(Stack* s, ElementType item);
void Stackpop(Stack* s);
int Stacksize(Stack* s);
ElementType Stacktop(Stack* s);
bool Stackempty(Stack* s);
void DestroyStack(Stack* s);