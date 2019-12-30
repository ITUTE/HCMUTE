#include <stdio.h>
#define SIZE 100

void nhapMaTran(int A[][SIZE], int &n);
void swap(int &x, int &y);
void sort(int A[], int n);
void copyDuongCheo(int A[][SIZE], int n, int D[]);
void sortDuongCheo(int A[][SIZE], int n);
void copyRow(int A[][SIZE], int rowA, int n, int B[][SIZE], int rowB);
void sortDuongCheo(int A[][SIZE], int n);
void ganMaTran(int A[][SIZE], int n, int B[][SIZE]);
void xuatMaTran(int A[][SIZE], int n);

int main()
{
	int A[SIZE][SIZE];
	int n;
	nhapMaTran(A,n);
	sortDuongCheo(A,n);
	xuatMaTran(A,n);
	return 0;
}

void nhapMaTran(int A[][SIZE], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			scanf("%d",&A[i][j]);
}

void swap(int &x, int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}

void sort(int A[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (A[i]>A[j])
				swap(A[i],A[j]);
}

void copyRow(int A[][SIZE], int rowA, int n, int B[][SIZE], int rowB)
{
	for (int i=0;i<n;i++)
		B[rowB][i]=A[rowA][i];
}

void copyDuongCheo(int A[][SIZE], int n, int D[])
{
	for (int i=0;i<n;i++)
		D[i]=A[i][i];
}

void ganMaTran(int A[][SIZE], int n, int B[][SIZE])
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			A[i][j]=B[i][j];
}

void sortDuongCheo(int A[][SIZE], int n)
{
	int B[SIZE][SIZE];
	int D[SIZE];
	copyDuongCheo(A,n,D);
	sort(D,n);
	
	int nB=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (A[j][j]==D[i])
			{
				copyRow(A,j,n,B,nB);
				nB++;
			}
	
	ganMaTran(A,n,B);
}

void xuatMaTran(int A[][SIZE], int n)
{
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			printf("%d\t",A[i][j]);
		printf("\n");
	}
}
