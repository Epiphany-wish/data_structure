#include"Stack.h"
int main()
{
	//�����Ƿ�ʵ��
	Stack s = CreatStack();
	Stackpush(&s, 3);
	Stackpush(&s, 4);
	Stackpush(&s, 5);
	Stackpush(&s, 6);
	Stackpush(&s, 7);
	while (!Stackempty(&s))
	{
		printf("%d ", Stacktop(&s));
		Stackpop(&s);
	}//���γ�ջ
	DestroyStack(&s);
	return 0;
}