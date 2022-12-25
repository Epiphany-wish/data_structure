#include"Stack.h"
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
		ElementType* new = (ElementType*)realloc(s->data, sizeof(Stack)*s->capacity * 2);
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