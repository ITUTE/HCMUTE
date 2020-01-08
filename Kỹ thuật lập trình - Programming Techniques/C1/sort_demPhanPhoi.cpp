#include <stdio.h>
#define SIZE 128

void nhapMang(int *&A, int &n);
void xuatMang(int *A, int n);
void sort(int *&A, int n);

int main()
{
	int *A;
	int n;
	nhapMang(A,n);
	sort(A,n);
	xuatMang(A,n);
	delete[] A;
	return 0;
}

void nhapMang(int *&A, int &n)
{
	scanf("%d",&n);
	A=new int[n];
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void xuatMang(int *A, int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void sort(int *&A, int n)
{
	int B[4]={0}, nA=0;
	for (int i=0;i<n;i++)
		B[A[i]]++;
	for (int i=1;i<=3;i++)
		for (int j=0;j<B[i];j++)
			A[nA++]=i;
}
