#include<stdio.h>
#include<stdlib.h>
#define MAX 32767
#define MAXSIZE 100
typedef int VerTexType;//设顶点的数据类型为int
typedef int ArcType;//设边的权值数据类型为int
int visited[MAX] = { 0 };
typedef struct AMGraph
{
	VerTexType vexs[MAXSIZE];//顶点表
	ArcType arcs[MAXSIZE][MAXSIZE];//邻接矩阵
	int vexnum;//图的边数
	int arcnum;//图的顶点数
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
void CreateGraph(AMGraph* G)//创建图
{
	int i = 0, j = 0;
	for (i = 0; i < G->arcnum; i++)
		scanf("%d", &G->vexs[i]);
	for (i = 0; i < G->arcnum; i++)
	{
		for (j = i + 1; j < G->arcnum; j++)
		{
			scanf("%d", &G->arcs[i][j]);
			G->arcs[j][i] = G->arcs[i][j];//因为是无向图，所以对应的二维矩阵沿对角线对称
		}
	}
}
void DFS(AMGraph* G,int a)//深度优先搜索
{
	int i;
	visited[a] = 1;
	for (i = 0; i < G->arcnum; i++)
	{
		////如果找到一个相连的顶点，并且该顶点还没有被访问过，进入递归函数
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
