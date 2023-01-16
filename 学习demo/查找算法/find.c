#include<stdio.h>
#include<stdlib.h>
int m = 7;
typedef int KeyType;
typedef struct Elementype
{
	KeyType key;
}ElementType;
typedef struct STable//顺序表
{
	ElementType* data;
	int length;// 表长
}STable;
typedef struct BSTree//二叉树
{
	ElementType data;
	struct BSTree* lchild;
	struct BSTree* rchild;
}BSTree;
int Sqsearch(STable* s, KeyType key)//顺序查找
{
	int i;
	for (i = 0; i < s->length; i++)
	{
		if (key == s->data[i].key)
			return i;
	}
	return -1;
}
int Search_bin(STable* s, KeyType key)//二分查找
{
	int low = 0, high = s->length-1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (key== s->data[mid].key) //key的值就等于中间位置的值
			return mid;
		if (key < s->data[mid].key) //key的值位于小半部分
			high = mid - 1;
		if (key > s->data[mid].key) //ekey值位于大半部分
			low = mid + 1;
	}
	return -1;
}
int Search_bin(STable* S, KeyType key, int low, int high)//二分查找的递归法
{
	//递归的终止条件
	if (low > high)
		return -1;
	//递归的变化体
	int mid = (high + low) / 2;
	if (key == S->data[mid].key)
		return mid;
	if (key < S->data[mid].key)
		return Search_bin(S, key, low, mid - 1);
	else
		return Search_bin(S, key, mid + 1, high);
}
/*二叉树查找算法*/
void InsertBSTree(BSTree** tree,KeyType key)//二叉排序树的插入
{
	if (*tree == NULL)
	{
		*tree = (BSTree *)calloc(sizeof(BSTree), 1);
		(* tree)->data.key = key;
	}
	if (key < ( * tree)->data.key)
		InsertBSTree(&(*tree)->lchild, key);
	else if (key > ( * tree)->data.key)
		InsertBSTree(&(*tree)->rchild, key);
}
void CreateBStree(BSTree** tree, STable* s)//二叉排序树的生成
{
	int i;
	for (i = 0; i < s->length; i++)
	{
		InsertBSTree(tree, s->data[i].key);
	}
}
BSTree* SearchBS(BSTree* tree, KeyType key)//二叉排序树的查找算法
{
	if (tree != NULL && tree->data.key == key)
		return tree;
	if (tree->data.key > key)
		return SearchBS(tree->lchild, key);
	else
		return SearchBS(tree->rchild, key);
}
void InorderBSTree(BSTree* tree)//中序遍历
{
	if (tree == NULL)
		return;
	InorderBSTree(tree->lchild);
	printf("%d ", tree->data.key);
	InorderBSTree(tree->rchild);
}
int main()
{
	//测试
	STable S;
	S.length = 5;
	S.data = (ElementType*)malloc(sizeof(ElementType) * (S.length + 1));
	S.data[0].key = 26;
	S.data[1].key = 35;
	S.data[2].key = 17;
	S.data[3].key = 42;
	S.data[4].key = 56;
	BSTree* tree = NULL;
	CreateBStree(&tree, &S);
	BSTree* ret= SearchBS(tree, 17);
	printf("%d\n", ret->data.key);
	InorderBSTree(tree);//输出排序后的数
	free(S.data);
	S.length = 0;
	return 0;
}