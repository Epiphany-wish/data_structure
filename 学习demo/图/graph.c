#include<stdio.h>
#include<stdlib.h>
#define MAX 32767
#define MAXSIZE 100
typedef int VerTexType;//�趥�����������Ϊint
typedef int ArcType;//��ߵ�Ȩֵ��������Ϊint
int visited[MAX] = { 0 };
typedef struct AMGraph
{
	VerTexType vexs[MAXSIZE];//�����
	ArcType arcs[MAXSIZE][MAXSIZE];//�ڽӾ���
	int vexnum;//ͼ�ı���
	int arcnum;//ͼ�Ķ�����
}AMGraph;
void InitGraph(AMGraph* G)
{
	int i, j;
	scanf("%d %d", &G->arcnum, &G->vexnum);
	for (int i = 0; i < G->arcnum; ++i)
	{
		for (int j = 0; j < G->arcnum; ++j)
		{
			G->arcs[i][j] = MAX;
		}
	}
}
void CreateGraph(AMGraph* G)//����ͼ
{
	int i = 0, j = 0;
	for (i = 0; i < G->arcnum; i++)
		scanf("%d", &G->vexs[i]);
	for (i = 0; i < G->arcnum; i++)
	{
		for (j = i + 1; j < G->arcnum; j++)
		{
			scanf("%d", &G->arcs[i][j]);
			G->arcs[j][i] = G->arcs[i][j];//��Ϊ������ͼ�����Զ�Ӧ�Ķ�ά�����ضԽ��߶Գ�
		}
	}
}
void DFS(AMGraph* G,int a)//�����������
{
	int i;
	visited[a] = 1;
	for (i = 0; i < G->arcnum; i++)
	{
		////����ҵ�һ�������Ķ��㣬���Ҹö��㻹û�б����ʹ�������ݹ麯��
		if (!visited[i] && G->arcs[a][i] != MAX)
			DFS(G, i);
	}
}
void BFS(AMGraph *G);
{
	int i,j;
	for(i=0;i<G->arcnum;i++)
	{
		for(j=0;j<G->arcnum;j++)
		{
			if ((G.arcs[i][j] != MAX) && visited[j] == 0)
            {
                visited[j] = 1;
            }
		}
	}
 } 
int main()
{
	AMGraph G;
	InitGraph(&G);
	CreateGraph(&G);
	DFS(&G, 0);
	return 0;
}
