#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int visited[MAXSIZE] = { 0 };
typedef int VerTexType;
typedef struct ArcNode
{
	int adjvex;//��¼������±�
	struct ArcNode* next;//ָ����һ���ڵ�
}ArcNode;
typedef struct VNode
{
	VerTexType data;//�洢�ڵ�����
	ArcNode* firstarc;// //ָ�������ڱ����ڽӱ�Ĺ�ϵ
}VNode;
typedef struct ALGraph
{
	//����һ�����飬����ͼ�Ķ���
	VNode vexs[MAXSIZE];
	//�����������������浱ǰͼ�Ķ�������Լ��ߵ�����
	int vexnum, arcnum;
}ALGraph;
void CreatUDG(ALGraph* G)//����ͼ�Ĵ���
{
	int i,j,k;
	scanf("%d %d", &G->arcnum, &G->vexnum);
	for ( i= 0; i < G->arcnum; ++i)
	{
		scanf("%d",&G->vexs[i].data);
		G->vexs[i].firstarc = NULL;
	}
	for (k = 0; k < G->vexnum; k++)
	{
		//ͷ�巨
		scanf("%d %d", &i, &j);
		ArcNode* p1 =(ArcNode*) malloc(sizeof(ArcNode));
		p1->adjvex = i;
		p1->next = G->vexs[i].firstarc;
		G->vexs[i].firstarc = p1;
		ArcNode* p2 = (ArcNode*)malloc(sizeof(ArcNode));
		p2->adjvex = j;
		p2->next = G->vexs[j].firstarc;
		G->vexs[j].firstarc = p2;
	}
}
void DFS(ALGraph* G, int a)
{
	int i = 0;
	visited[a] = 1;
	ArcNode* p = G->vexs[a].firstarc;
	while (p != NULL)
	{
		int i = p->adjvex;
		if (visited[i] == 0)
		{
			DFS(G, i);
		}
		p = p->next;
	}
}
int main()
{
	ALGraph G;
	CreatUDG(&G);
	DFS(&G, 0);
	return 0;
}