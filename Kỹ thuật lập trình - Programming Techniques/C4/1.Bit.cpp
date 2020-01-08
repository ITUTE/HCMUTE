#include <stdio.h>

int getbit(int n, int k);
void onbit(int &n, int k);
void offbit(int &n, int k);
void bin(int n);			//xuat duoi dang bieu dien nhi phan (bit)
void xuatNP(int n);			//xuat cac so nhi phan tu -n  den n

int main()
{
	int n;	scanf("%d",&n);
	//xuatNP(n);
	printf("%d",getbit(n,0));
	return 0;
}
//xuat nhi phan tu 0 den n
void xuatNP(int n)
{
	for (int i=-n;i<=n;i++)
	{
		printf("%d\t",i);
		bin(i);	printf("\n");
	}
}

int getbit(int n, int k)
{
	return (n>>k) & 0x1;
}

void onbit(int &n, int k)
{
	n=(0x1<<k)|n;
}

void offbit(int &n, int k)
{
	n= ~(0x1<<k) & n;
}

void bin(int n)
{
	for (int i=8*sizeof(n)-1;i>=0;i--)
	{
		printf("%d",(n>>i) & 0x1);
		if (i%4==0)
			printf(" ");
	}
}
