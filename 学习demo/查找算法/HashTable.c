#include<stdio.h>
#include<stdlib.h>
#define HASHSIZE 12
#define NULLKEY -32768
typedef int ElementType;
typedef struct HashTable
{
	ElementType* data;
	int length;
}HashTable;
void InitHashTable(HashTable* H) {
	int i;
	H->length = HASHSIZE;
	H->data = (ElementType*)malloc(HASHSIZE * sizeof(ElementType));
	for (i = 0; i < HASHSIZE; i++)
		H->data[i] = NULLKEY;
}
int Hash(int key) 
{
	return key % HASHSIZE;
}
void InsertHash(HashTable* H, int key) 
{
	int addr = Hash(key);	//求散列地址
	while (H->data[addr] != NULLKEY)	//如果不是默认值，说明有数值存在
		addr = (addr + 1) % HASHSIZE;	//开放定址法的线性探测
	H->data[addr] = key;	//找到位置后插入 
}
int SearchKeyInHash(HashTable H, int key, int* addr) {
	*addr = Hash(key);	//先求出散列地址
	while (H.data[*addr] != key) {	//不是关键字，说明被其他key占用了 
		*addr = (*addr + 1) % HASHSIZE;	//一个一个找 
		if (H.data[*addr] == NULLKEY || *addr == Hash(key))//如果回到原点，或者找到了默认值，说明表里没有这个key
			return 0;
	}
	return 1;
}
void printHashTable(HashTable H)
{
	int i;
	for (i = 0; i < HASHSIZE; i++)
		printf("%d ", H.data[i]);
	printf("\n");
}
int main()
{
	int i;
	HashTable* H = (HashTable*)malloc(sizeof(HashTable));
	int a[10] = { 1,13,2,3,4,5,6,15,20,40 };
	InitHashTable(H);
	printHashTable(*H);
	for (i = 0; i < 10; i++)
		InsertHash(H, a[i]);
	printHashTable(*H);
	//查找
	if (SearchKeyInHash(*H, 15, &i))
		printf("找到了！\n");
	else
		printf("关键字不存在！\n");
	return 0;
}