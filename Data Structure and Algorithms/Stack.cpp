#include <stdio.h>

struct NODE
{
	int value;
	NODE *pNext;
};
struct STACK
{
	NODE *pHead;
	NODE *pTail;
};
void CreateStack(STACK &S)
{
	S.pHead=S.pTail=NULL;
}
int isEmpty(STACK S)
{
	if (S.pHead==NULL)
		return 1;
	return 0;
}
NODE* CreateNode(int value)
{
	NODE *p=new NODE;
	p->value=value;
	p->pNext=NULL;
	return p;
}
void Push(STACK &S, int value)
{
	NODE *p=CreateNode(value);
	if (isEmpty(S))
	{
		S.pHead=S.pTail=p;
	}
	else
	{
		p->pNext=S.pHead;
		S.pHead=p;
	}
}
int Pop(STACK &S)
{
	if (isEmpty(S))
		return NULL;
	NODE *p; 
	p=S.pHead;
	int data=S.pHead->value;
	S.pHead=S.pHead->pNext;
	delete p;
	if (S.pHead==NULL)
		S.pTail=NULL;
	return data;
}
int Top(STACK S)
{
	if (isEmpty(S))
		return NULL;
	return S.pHead->value;
}
int main()
{
	STACK S;
	CreateStack(S);
	for (int i=1;i<=10;i++)
		Push(S,i);
	printf("\n%d\n",Top(S));
	while (!isEmpty(S))
	{
		printf(" >> %d",Pop(S));
	}
	return 0;
} 
