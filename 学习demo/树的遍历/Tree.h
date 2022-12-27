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
typedef BinTree* ElementType;//ElementType 暂时定义为 BinTree* 类型
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
BinTree* CreatBinTree();   // 创建一个二叉树
bool IsEmpty(BinTree* BT);  // 判断树 BT 是否为空 
void PreOrderTraversal(BinTree* BT);   // 先序遍历，根左右
void InOrderTraversal(BinTree* BT);    // 中序遍历，左根右 
void PostOrderTraversal(BinTree* BT);  // 后序遍历，左右根 
int  GetHeight(BinTree* BT);