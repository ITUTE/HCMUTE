#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &n);
void xuly(int A[], int B[], int n);
void xuat(int A[], int B[], int n);
void xuly(int A[], int B[], int n);
int ktChuSoDau(int x);

int main()
{
	int A[size],B[size];
	int n;
	nhapMang(A,n);
	xuly(A,B,n);
	xuat(A,B,n);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

//KT chu so dau co phai so chan
int ktChuSoDau(int x)
{
	if (x<0) x=-x;
	while (x>=10) x/=10;
	if (x%2==0)
		return 1;
	return 0;
}

void xuly(int A[], int B[], int n)
{
	for (int i=0;i<n;i++)
		if (ktChuSoDau(A[i]))	//Neu A[i] thoa DK
			B[i]=1;				//Dung mang B[] de danh dau
}

void xuat(int A[],int B[], int n)
{
	for (int i=0;i<n;i++)
		if (B[i]==1)
			printf("%d ",A[i]);
}
