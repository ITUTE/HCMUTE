#include <stdio.h>
struct NODE
{
	int key;
	NODE *pLeft, *pRight;
};
NODE* SearchNode(NODE* Root, int x)
{
	NODE *p=Root;
	while(p!=NULL)
	{
		if (x==p->key)	return p;
		else 
			if (x<p->key)	p=p->pLeft;
			else			p=p->pRight;
	}
	return NULL;
}
int InsertNode(NODE* &T, int x)
{
	if (T)
	{
		if (T->key==x)	return 0;	//Exist
		if (T->key>x)	return InsertNode(T->pLeft,x);
		else			return InsertNode(T->pRight,x);
	}
	T= new NODE;
	if (T==NULL)	return -1;	//Thieu bo nho
	T->key=x;
	T->pLeft=T->pRight=NULL;
	return 1;	//Thanh cong
}
void LNR(NODE* Root)
{
	if (Root!=NULL)
	{
		LNR(Root->pLeft);
		printf(" >> %d ",Root->key);
		LNR(Root->pRight);	
	}
}
void DelTree(NODE* &T)
{
	if (T)
	{
		DelTree(T->pLeft);
		DelTree(T->pRight);
		delete(T);	
		T=NULL;
	}
}
void SearchStandFor(NODE* &p, NODE* &q)
{
	if (q->pLeft)	SearchStandFor(p,q->pLeft);
	else
	{
		p->key=q->key;
		p=q;
		q=q->pRight;
	}
}
int DelNode(NODE* &T, int x)
{
	if (T==NULL)	return 0;
	if (T->key>x)	return DelNode(T->pLeft,x);
	if (T->key<x)	return DelNode(T->pRight,x);
	else
	{
		NODE* p=T;
		if		(T->pLeft==NULL)	T=T->pRight;
		else if (T->pRight==NULL)	T=T->pLeft;
		else
		{
			NODE* q=T->pRight;
			SearchStandFor(p,q);
		}
	}
}
int main()
{
	NODE *T=NULL;
	for (int i=1;i<=10;i++)
		InsertNode(T,i);
	//DelTree(T);
	LNR(T);
	return 0;
}
