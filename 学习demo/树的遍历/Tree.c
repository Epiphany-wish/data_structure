#include"Tree.h"
Stack CreatStack()//创建一个栈
{
	Stack s;
	s.data = (ElementType*)malloc(sizeof(ElementType) * 2);//分配初始内存
	s.top = 0;
	s.capacity = 2;
	return s;
}
void Stackpush(Stack* s, ElementType item)//入栈
{
	if (s->top == s->capacity)
	{
		ElementType new = (ElementType)realloc(s->data, sizeof(BinTree) * s->capacity * 2);
		if (new == NULL)
			exit(0);
		s->data = new;
		s->capacity *= 2;
	}//对栈进行扩容
	s->data[s->top++] = item;
}
void Stackpop(Stack* s)//出栈
{
	if (s->top == 0)
		return;
	s->top--;
}
int Stacksize(Stack* s)//判断栈的元素数量
{
	return s->top;
}
ElementType Stacktop(Stack* s)//返回栈顶元素
{
	if (s->top > 0)//如果栈不为空则返回栈顶元素
		return s->data[s->top - 1];
	else
		return;
}
bool Stackempty(Stack* s)//判断栈是否为空
{
	return s->top == 0;//如果栈为空，返回true，否则返回false
}
void DestroyStack(Stack* s)//摧毁栈
{
	free(s->data);
	s->data = NULL;
	s->top = 0;
	s->capacity = 0;
}
BinTree* Insert(int data)
{
	BinTree* node = (BinTree*)malloc(sizeof(BinTree));
	node->data = data;
	node-> left = NULL;
	node->right = NULL;
	return node;
}
BinTree* CreatBinTree()  // 创建一个二叉树
{
	BinTree* BT;
	BT = (BinTree*)malloc(sizeof(BinTree));
	BT->data = 1;
	BT->left = Insert(2);
	BT->right = Insert(3);
	BT->left->left = Insert(4);
	BT->left->right = Insert(6);
	BT->left->right->left = Insert(5);
	BT->right->left = Insert(7);
	BT->right->right = Insert(9);
	BT->right->left->right = Insert(8);//指定生成一个二叉树
	return BT;
}
bool IsEmpty(BinTree* BT) // 判断树 BT 是否为空 
{
	return (BT->left == NULL && BT->right == NULL);
}
// 先序
/*void  PreOrderTraversal(BinTree* BT){
	if(BT){
		printf("%d",BT->data);  // 打印根
		PreOrderTraversal(BT->left);  // 进入左子树
		PreOrderTraversal(BT->right);  // 进入右子树
	}
} */
void PreOrderTraversal(BinTree* BT)  // 先序遍历，根左右
{
	Stack s = CreatStack();//创建并初始化堆栈 S
	BinTree* T = BT;
	while (T || !Stackempty(&s))// 当树不为空或堆栈不空 
	{
		while (T)
		{
			Stackpush(&s, T);// 压栈，第一次遇到该结点 
			printf("%d ", T->data);// 访问结点
			T = T->left;// 遍历左子树
		}
		if (!Stackempty(&s))// 当堆栈不空 
		{
			T = Stacktop(&s);
			Stackpop(&s);
			T = T->right;// 访问右结点
		}
	}
	DestroyStack(&s);
}
// 中序递归 
/*void InOrderTraversal(BinTree* BT){
	if(BT){
		InOrderTraversal(BT->left);  // 进入左子树
		printf("%d",BT->data);  // 打印根
		InOrderTraversal(BT->right);  // 进入右子树
	}
} */
void InOrderTraversal(BinTree* BT)    // 中序遍历，左根右 
{
	BinTree* T = BT;
	Stack S = CreatStack();  // 创建并初始化堆栈 S
	while (T || !Stackempty(&S)) {  // 当树不为空或堆栈不空 
		while (T) {
			Stackpush(&S, T);    // 压栈
			T = T->left;   // 遍历左子树 
		}
		if (!Stackempty(&S)) {  // 当堆栈不空 
			T=Stacktop(&S);
			Stackpop(&S);    // 出栈
			printf("%d ", T->data);  // 访问结点
			T = T->right;  // 访问右结点 
		}
	}
}
// 后序
void PostOrderTraversal(BinTree* BT){
	if(BT){
		PostOrderTraversal(BT->left);  // 进入左子树
		PostOrderTraversal(BT->right);  // 进入右子树
		printf("%d ",BT->data);  // 打印根
	}
} 
int  GetHeight(BinTree* BT) {
	int hl, hr, maxh;
	if (BT) {
		hl = GetHeight(BT->left);  // 求左子树高度 
		hr = GetHeight(BT->right);  // 求右子树高度 
		maxh = (hl > hr) ? hl : hr;
		return maxh + 1;  // 当前结点高度为左右子树最大的高度+1 
	}
	else
		return 0;
}