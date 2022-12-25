#include"Stack.h"
int main()
{
	//测试是否实现
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
	}//依次出栈
	DestroyStack(&s);
	return 0;
}