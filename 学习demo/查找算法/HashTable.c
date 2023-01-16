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
	int addr = Hash(key);	//��ɢ�е�ַ
	while (H->data[addr] != NULLKEY)	//�������Ĭ��ֵ��˵������ֵ����
		addr = (addr + 1) % HASHSIZE;	//���Ŷ�ַ��������̽��
	H->data[addr] = key;	//�ҵ�λ�ú���� 
}
int SearchKeyInHash(HashTable H, int key, int* addr) {
	*addr = Hash(key);	//�����ɢ�е�ַ
	while (H.data[*addr] != key) {	//���ǹؼ��֣�˵��������keyռ���� 
		*addr = (*addr + 1) % HASHSIZE;	//һ��һ���� 
		if (H.data[*addr] == NULLKEY || *addr == Hash(key))//����ص�ԭ�㣬�����ҵ���Ĭ��ֵ��˵������û�����key
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
	//����
	if (SearchKeyInHash(*H, 15, &i))
		printf("�ҵ��ˣ�\n");
	else
		printf("�ؼ��ֲ����ڣ�\n");
	return 0;
}