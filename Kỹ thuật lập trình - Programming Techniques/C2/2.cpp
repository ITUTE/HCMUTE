#include <stdio.h>
#include <string.h>
#define SIZE 128

void nhapMang(int *&A, int &n);
void xuatMang(int *A, int n);
void quickSort(int *A, int left , int right);
void insert(int *&A, int &n, int pos, int k);
void sort(int *&A, int &n, int k);

int main()
{
	int n;
	int *A;
	nhapMang(A,n);
	int k;	scanf("%d",&k);
	sort(A,n,k);
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
		printf("%d  ",A[i]);
}

void quickSort(int *A, int left , int right)
{
	if (left<=right)
	{
		int i=left, j=right, key=A[(left+right)/2];
		while (A[i]>key)	i++;
		while (A[j]<key)	j--;
		if (i<=j)
		{
			int tmp=A[i];A[i]=A[j];A[j]=tmp;
			i++;j--;
		}
		if (left<j)		quickSort(A,left,j);
		if (i<right)	quickSort(A,i,right);
	}
}

void sort(int *&A, int &n, int k)
{
	quickSort(A,0,n-1);
	int i=n-1;
	while (A[i]<k && i>=0)	i--;
	insert(A,n,i+1,k);	
}

void insert(int *&A, int &n, int pos, int k)
{
	for (int i=n;i>pos;i--)
		A[i]=A[i-1];
	A[pos]=k;
	n++;
}
