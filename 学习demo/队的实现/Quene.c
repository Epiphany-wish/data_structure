#include"Quene.h"
Quene* InitQuene()//��ʼ������
{
	Quene* Q;
	Q = (Quene*)malloc(sizeof(Quene));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}
void PushQuene(Quene* Q, ElementType item)//���
{
	Node* newnode = (Node*)malloc(sizeof(Node));//�����½ڵ�
	newnode->data = item;
	newnode->next = NULL;
	if (Q->front == NULL)//�ж϶����Ƿ�Ϊ��
	{
		Q->front = Q->rear=newnode;
	}
	else
	{
		Q->rear->next = newnode;
		Q->rear = newnode;
	}
}
void PopQuene(Quene* Q)//����
{
	if (Q->front == NULL)
		exit(0);
	Node* next = Q->front->next;
	free(Q->front);
	Q->front = next;
	if (next == NULL)//����ֻ��һ��Ԫ��
		Q->rear = NULL;
}
ElementType FrontQuene(Quene* Q)//���ض���ͷ�ڵ�Ԫ��
{
	if (Q->front != NULL)
		return Q->front->data;
	else
		exit(0);
}
int SizeQuene(Quene* Q)//���ض���Ԫ������
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
bool EmptyQuene(Quene* Q)//�ж϶����Ƿ�Ϊ��
{
	return Q->front == NULL;
}
void DestroyQuene(Quene* Q)//�ͷŶ��и��ڵ��ڴ�
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