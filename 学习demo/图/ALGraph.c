#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
int visited[MAXSIZE] = { 0 };
typedef int VerTexType;
typedef struct ArcNode
{
	int adjvex;//记录顶点的下表
	struct ArcNode* next;//指向下一个节点
}ArcNode;
typedef struct VNode
{
	VerTexType data;//存储节点数据
	ArcNode* firstarc;// //指针域，用于保存邻接表的关系
}VNode;
typedef struct ALGraph
{
	//定义一个数组，保存图的顶点
	VNode vexs[MAXSIZE];
	//定义两个变量，保存当前图的顶点个数以及边的条数
	int vexnum, arcnum;
}ALGraph;
void CreatUDG(ALGraph* G)//无向图的创建
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
		//头插法
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