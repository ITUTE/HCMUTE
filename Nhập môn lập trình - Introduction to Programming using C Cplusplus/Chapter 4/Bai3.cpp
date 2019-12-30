/*
Tim phan tu lon thu 2
*/

#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &n);
void xuat(int kq);
int find(int A[], int n);

int main()
{
	int A[size],n;
	nhapMang(A,n);
	int kq=find(A,n);
	xuat(kq);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void xuat(int kq)
{
	printf("%d",kq);
}

int find(int A[], int n)
{
	int max=A[0];
	int result=A[0];
	for (int i=1;i<n;i++)
		if (A[i]>max)
		{
			//Luu y thu tu phep toan
			result=max;
			max=A[i];
		}
	return result;
}
