#include <stdio.h>
struct NODE
{
	int value;
	NODE* pNext;
};
struct LIST
{
	NODE *pHead;
	NODE *pTail;
};
void ShowList(LIST DS)
{
	NODE *p=DS.pHead;
	while (p!=NULL)
	{
		printf(">> %d : %x\n",p->value,p->pNext);
		p=p->pNext;
	}
}
int isEmpty(LIST DS)
{
	if (DS.pHead==NULL)
		return 1;
	return 0;
}
NODE* CreateNode(int value)
{
	NODE *p =new NODE;
	p->value=value;
	p->pNext=NULL;
	return p;
}
NODE* GetNode(LIST DS, int value)
{
	if (!isEmpty(DS))
	{
		NODE *p=DS.pHead;
		while (p->pNext!=NULL && p->value!=value)
			p=p->pNext;
		if (p->value==value)
			return p;
	}
	return NULL;
}
void AddHead(LIST &DS, NODE *p)
{
	if (isEmpty(DS))
	{
		DS.pHead=DS.pTail=p;
	}
	else
	{
		p->pNext=DS.pHead;
		DS.pHead=p;
	}
}
NODE* AddHeadData(LIST &DS, int value)
{
	NODE *p=CreateNode(value);
	if (p==NULL)
		return NULL;
	if (isEmpty(DS))
	{
		DS.pHead=DS.pTail=p;
	}
	else
	{
		p->pNext=DS.pHead;
		DS.pHead=p;
	}
	return p;
}
void AddTail(LIST &DS, NODE *p)
{
	if (isEmpty(DS))
	{
		DS.pHead=DS.pTail=p;
	}
	else
	{
		DS.pTail->pNext=p;
		DS.pTail=p;
	}
}
NODE* AddTailData(LIST &DS, int value)
{
	NODE *p=CreateNode(value);
	if (p==NULL)
		return NULL;
	if (isEmpty(DS))
	{
		DS.pHead=DS.pTail=p;
	}
	else
	{
		DS.pTail->pNext=p;
		DS.pTail=p;
	}
	return p;
}
void AddAfter(LIST &DS, NODE *p, NODE *pNew)
{
	if (p!=NULL)
	{
		pNew->pNext=p->pNext;
		p->pNext=pNew;
		if (p==DS.pTail)
			DS.pTail=pNew;
	}
	else
		AddHead(DS,pNew);
}
void AddAfter(LIST &DS, NODE *p, int value)
{
	if (!isEmpty(DS))
	{
		if (DS.pTail->value==value)
		{
			AddTailData(DS,value);
			return;
		}
		NODE *i=DS.pHead;
		while (i!=DS.pTail && i->value!=value)
			i=i->pNext;
		if (i->value==value)
		{
			p->pNext=i->pNext;
			i->pNext=p;
		}
	}
}
int DelHead(LIST &DS)
{
	NODE *p; 
	int data=NULL;
	if (!isEmpty(DS))
	{
		p=DS.pHead;
		data=DS.pHead->value;
		DS.pHead=DS.pHead->pNext;
		delete p;
		if (DS.pHead==NULL)
			DS.pTail=NULL;
	}
	return data;
}
int DelTail(LIST &DS)
{
	NODE *p;
	int data=NULL;
	if (!isEmpty(DS))
	{
		if (DS.pHead==DS.pTail)
		{
			p=DS.pHead;
			data=DS.pHead->value;
			//delete p;
			DS.pHead=DS.pTail=NULL;
		}
		else
		{
			NODE *i=DS.pHead;
			while ((i->pNext)->pNext!=NULL)
			{
				i=i->pNext;
			}
			p=DS.pTail;
			data = DS.pTail->value;
			i->pNext=NULL;
			DS.pTail=i;
			delete p;
		}
	}
	return data;
}
int DelAfter(LIST &DS, NODE *ptr)
{
	if (ptr!=NULL && ptr!=DS.pTail)
	{
		NODE *p=ptr->pNext;
		int data=p->value;
		ptr->pNext=p->pNext;
		if (p==DS.pTail)
			DS.pTail=ptr;
		return data;
	}
	else
		return NULL;
}
void NodeInfo(NODE* p)
{
	if (p==NULL)
		printf(" >> NULL");
	else printf(" >> %d : %x",p->value,p->pNext);
}
int main()
{
	LIST DS;
	DS.pHead=NULL;
	DS.pTail=NULL;
	for (int i=1;i<=10;i++)
		AddTail(DS,CreateNode(i));
	ShowList(DS);
	//AddAfter(DS,CreateNode(7),10);
	//printf("\n%d\n",DelHead(DS));
	//printf("\n%d\n",DelTail(DS));
	//printf("\n%d\n",DelAfter(DS,GetNode(DS,9)));
	//NodeInfo(DS.pTail);
	printf("%d ",DelTail(DS));
	printf("%d ",DelTail(DS));
	printf("%d ",DelTail(DS));
	printf("\n");
	ShowList(DS);
	return 0;	
}
