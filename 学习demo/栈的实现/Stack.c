#include"Stack.h"
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
		ElementType* new = (ElementType*)realloc(s->data, sizeof(Stack)*s->capacity * 2);
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