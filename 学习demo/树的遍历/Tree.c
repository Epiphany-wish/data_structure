#include"Tree.h"
Stack CreatStack()//����һ��ջ
{
	Stack s;
	s.data = (ElementType*)malloc(sizeof(ElementType) * 2);//�����ʼ�ڴ�
	s.top = 0;
	s.capacity = 2;
	return s;
}
void Stackpush(Stack* s, ElementType item)//��ջ
{
	if (s->top == s->capacity)
	{
		ElementType new = (ElementType)realloc(s->data, sizeof(BinTree) * s->capacity * 2);
		if (new == NULL)
			exit(0);
		s->data = new;
		s->capacity *= 2;
	}//��ջ��������
	s->data[s->top++] = item;
}
void Stackpop(Stack* s)//��ջ
{
	if (s->top == 0)
		return;
	s->top--;
}
int Stacksize(Stack* s)//�ж�ջ��Ԫ������
{
	return s->top;
}
ElementType Stacktop(Stack* s)//����ջ��Ԫ��
{
	if (s->top > 0)//���ջ��Ϊ���򷵻�ջ��Ԫ��
		return s->data[s->top - 1];
	else
		return;
}
bool Stackempty(Stack* s)//�ж�ջ�Ƿ�Ϊ��
{
	return s->top == 0;//���ջΪ�գ�����true�����򷵻�false
}
void DestroyStack(Stack* s)//�ݻ�ջ
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
BinTree* CreatBinTree()  // ����һ��������
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
	BT->right->left->right = Insert(8);//ָ������һ��������
	return BT;
}
bool IsEmpty(BinTree* BT) // �ж��� BT �Ƿ�Ϊ�� 
{
	return (BT->left == NULL && BT->right == NULL);
}
// ����
/*void  PreOrderTraversal(BinTree* BT){
	if(BT){
		printf("%d",BT->data);  // ��ӡ��
		PreOrderTraversal(BT->left);  // ����������
		PreOrderTraversal(BT->right);  // ����������
	}
} */
void PreOrderTraversal(BinTree* BT)  // ���������������
{
	Stack s = CreatStack();//��������ʼ����ջ S
	BinTree* T = BT;
	while (T || !Stackempty(&s))// ������Ϊ�ջ��ջ���� 
	{
		while (T)
		{
			Stackpush(&s, T);// ѹջ����һ�������ý�� 
			printf("%d ", T->data);// ���ʽ��
			T = T->left;// ����������
		}
		if (!Stackempty(&s))// ����ջ���� 
		{
			T = Stacktop(&s);
			Stackpop(&s);
			T = T->right;// �����ҽ��
		}
	}
	DestroyStack(&s);
}
// ����ݹ� 
/*void InOrderTraversal(BinTree* BT){
	if(BT){
		InOrderTraversal(BT->left);  // ����������
		printf("%d",BT->data);  // ��ӡ��
		InOrderTraversal(BT->right);  // ����������
	}
} */
void InOrderTraversal(BinTree* BT)    // �������������� 
{
	BinTree* T = BT;
	Stack S = CreatStack();  // ��������ʼ����ջ S
	while (T || !Stackempty(&S)) {  // ������Ϊ�ջ��ջ���� 
		while (T) {
			Stackpush(&S, T);    // ѹջ
			T = T->left;   // ���������� 
		}
		if (!Stackempty(&S)) {  // ����ջ���� 
			T=Stacktop(&S);
			Stackpop(&S);    // ��ջ
			printf("%d ", T->data);  // ���ʽ��
			T = T->right;  // �����ҽ�� 
		}
	}
}
// ����
void PostOrderTraversal(BinTree* BT){
	if(BT){
		PostOrderTraversal(BT->left);  // ����������
		PostOrderTraversal(BT->right);  // ����������
		printf("%d ",BT->data);  // ��ӡ��
	}
} 
int  GetHeight(BinTree* BT) {
	int hl, hr, maxh;
	if (BT) {
		hl = GetHeight(BT->left);  // ���������߶� 
		hr = GetHeight(BT->right);  // ���������߶� 
		maxh = (hl > hr) ? hl : hr;
		return maxh + 1;  // ��ǰ���߶�Ϊ�����������ĸ߶�+1 
	}
	else
		return 0;
}