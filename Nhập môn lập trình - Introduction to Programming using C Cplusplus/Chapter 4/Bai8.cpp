#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &n);
void nhap(int &x, int &y);
void xuly(int A[], int B[], int n,int x, int y);
void xuatMang(int A[], int B[],int n);

int main()
{
	int A[size],B[size],x,y;
	int n;
	nhapMang(A,n);
	nhap(x,y);
	xuly(A,B,n,x,y);
	xuatMang(A,B,n);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void nhap(int &x, int &y)
{
	scanf("%d%d",&x,&y);
}

//so chan trong mang A[] thuoc doan [x;y]
void xuly(int A[], int B[], int n, int x, int y)
{
	for (int i=0;i<n;i++)
		if ((A[i]>=x)&&(A[i]<=y)&&(A[i]%2==0))
			B[i]=1;
}

void xuatMang(int A[], int B[], int n)
{
	for (int i=0;i<n;i++)
		if (B[i]==1)
			printf("%d ",A[i]);
}
