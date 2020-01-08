#include <stdio.h>

void xuat(int *A, int n);
void init(int *&A, int &n);
void bin(int n);

int main()
{
	int *A;	int n;
	init(A,n);
	xuat(A,n);
	delete[] A;
	return 0;
}

void bin(int n)
{
	for (int i=8*sizeof(n)-1;i>=0;i--)
	{
		printf("%d",(n>>i) & 0x1);
		if (i%4==0)
			printf(" ");
	}
	printf("\n");
}

void init(int *&A, int &n)
{
	scanf("%d",&n);
	A=new int[n];
	A[0]=0;	A[1]=1;
	for (int i=2;i<n;i++)
		if (i%2)
			A[i]=A[i/2]+A[i/2+1];
		else A[i]=A[i/2];
}

void xuat(int *A, int n)
{
	for (int i=0;i<n;i++)
	{
		printf("%d ",A[i]);
		bin(A[i]);
	}
}
