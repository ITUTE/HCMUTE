#include <stdio.h>
struct NODE
{
	int value;
	NODE *pNext;
};
struct QUEUE
{
	NODE *pHead;
	NODE *pTail;
};
void CreateQueue(QUEUE &Q)
{
	Q.pHead=Q.pTail=NULL;
}
NODE* CreateNode(int value)
{
	NODE *p =new NODE;
	p->value=value;
	p->pNext=NULL;
	return p;
}
int isEmpty(QUEUE Q)
{
	if (Q.pHead==NULL)
		return 1;
	return 0;
}
void Enqueue(QUEUE &Q, int value)
{
	NODE *p=CreateNode(value);
	if (isEmpty(Q))
	{
		Q.pHead=Q.pTail=p;
	}
	else
	{
		Q.pTail->pNext=p;
		Q.pTail=p;
	}
}
int Dequeue(QUEUE &Q)
{
	if (isEmpty(Q))
		return NULL;
	NODE *p; 
	p=Q.pHead;
	int data=Q.pHead->value;
	Q.pHead=Q.pHead->pNext;
	delete p;
	if (Q.pHead==NULL)
		Q.pTail=NULL;
	return data;
}
int Front(QUEUE &Q)
{
	if (isEmpty(Q))
		return NULL;
	return Q.pHead->value;
}
int main()
{
	QUEUE Q;
	CreateQueue(Q);
	for (int i=1;i<=10;i++)
		Enqueue(Q,i);
	printf("\n%d\n",Front(Q));
	while (!isEmpty(Q))
		printf(" >> %d",Dequeue(Q));
	return 0;
}
