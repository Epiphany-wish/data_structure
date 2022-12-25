#include"Quene.h"
Quene* InitQuene()//初始化队列
{
	Quene* Q;
	Q = (Quene*)malloc(sizeof(Quene));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}
void PushQuene(Quene* Q, ElementType item)//入队
{
	Node* newnode = (Node*)malloc(sizeof(Node));//建立新节点
	newnode->data = item;
	newnode->next = NULL;
	if (Q->front == NULL)//判断队列是否为空
	{
		Q->front = Q->rear=newnode;
	}
	else
	{
		Q->rear->next = newnode;
		Q->rear = newnode;
	}
}
void PopQuene(Quene* Q)//出队
{
	if (Q->front == NULL)
		exit(0);
	Node* next = Q->front->next;
	free(Q->front);
	Q->front = next;
	if (next == NULL)//队列只有一个元素
		Q->rear = NULL;
}
ElementType FrontQuene(Quene* Q)//返回队列头节点元素
{
	if (Q->front != NULL)
		return Q->front->data;
	else
		exit(0);
}
int SizeQuene(Quene* Q)//返回队列元素数量
{
	Node* cur = Q->front;
	int len = 0;
	while (cur)
	{
		len++;
		cur = cur->next;
	}
	return len;
}
bool EmptyQuene(Quene* Q)//判断队列是否为空
{
	return Q->front == NULL;
}
void DestroyQuene(Quene* Q)//释放队列各节点内存
{
	Node* cur = Q->front;
	while (cur != NULL)
	{
		Node* next = cur->next;
		free(cur);
		cur = next;
	}
	Q->front = NULL;
	Q->rear = NULL;
}