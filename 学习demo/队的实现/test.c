#include"Quene.h"
int main()
{
	Quene* Q = InitQuene();
	PushQuene(Q, 5);
	PushQuene(Q, 6);
	PushQuene(Q, 7);
	PushQuene(Q, 8);
	PushQuene(Q, 9);
	while (!EmptyQuene(Q))
	{
		printf("%d\n", FrontQuene(Q));
		PopQuene(Q);
		printf("size=%d\n", SizeQuene(Q));
	}//ÒÀ´Î³ö¶Ó
	DestroyQuene(Q);
	free(Q);
	return 0;
}