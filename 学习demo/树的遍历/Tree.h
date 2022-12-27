#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}BinTree;
typedef BinTree* ElementType;//ElementType ��ʱ����Ϊ BinTree* ����
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
BinTree* CreatBinTree();   // ����һ��������
bool IsEmpty(BinTree* BT);  // �ж��� BT �Ƿ�Ϊ�� 
void PreOrderTraversal(BinTree* BT);   // ���������������
void InOrderTraversal(BinTree* BT);    // �������������� 
void PostOrderTraversal(BinTree* BT);  // ������������Ҹ� 
int  GetHeight(BinTree* BT);