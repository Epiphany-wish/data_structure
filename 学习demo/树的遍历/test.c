#include"Tree.h"
int main()
{
	//�����Ƿ�ʵ��
	BinTree* BT = CreatBinTree();
	PreOrderTraversal(BT);
	printf("\n");
	InOrderTraversal(BT);
	printf("\n");
	PostOrderTraversal(BT);
	printf("\n");
	printf("height=%d\n", GetHeight(BT));
	return 0;
}