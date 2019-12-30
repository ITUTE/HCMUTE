/*
In cac gia tri khac nhau cua A[], B[]
*/

#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &m);
void xuat(int A[], int B[], int reA[], int reB[], int m, int n);
void xuly(int A[], int B[], int reA[], int reB[], int m, int n);

int main()
{
	int A[size],B[size],reA[size],reB[size];
	int m,n;
	nhapMang(A,m);
	nhapMang(B,n);
	xuly(A,B,reA,reB,m,n);
	xuat(A,B,reA,reB,m,n);
	return 0;
}

void nhapMang(int A[], int &m)
{
	scanf("%d",&m);
	for (int i=0;i<m;i++)
		scanf("%d",&A[i]);
}

void xuat(int A[], int B[], int reA[], int reB[], int m, int n)
{
	int i;
	for (i=0;i<m;i++)
		if (reA[i])
			printf("%d ",A[i]);
	for (i=0;i<n;i++)
		if (reB[i])
			printf("%d ",B[i]);
}

void xuly(int A[], int B[], int reA[], int reB[], int m, int n)
{
	int i;
	//Khoi tao reA[], reB[] dung de ghi nho A[], B[] thoa dieu kien (1) hay khong (0)
	for (i=0;i<m;i++)
		reA[i]=1;
	for (i=0;i<n;i++)
		reB[i]=1;
	//Duyet mang tuan tu
	for (i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if ((B[j]==A[i])&&(reA[i]==1))		//reA[i]==1 de biet A[i] chua trung cac phan tu B[] truoc do
			{
				//A[i], B[j] trung nhau nen chung khong thoa DK
				reA[i]=0;
				reB[j]=0;
			}
}
