#include <stdio.h>
#define SIZE 100

void nhapMatrix(int A[][SIZE], int &m, int &n);
void xuatMatrix(int A[][SIZE], int m, int n);
void convertToArray(int A[][SIZE], int m, int n, int B[SIZE], int &sizeB);
void convertToMatrix(int B[], int sizeB, int A[][SIZE], int m, int n);
void sortMatrix(int A[][SIZE], int m, int n);
void swap(int &x, int &y);
void sort(int A[], int n);

int main()
{
	int A[SIZE][SIZE];
	int m,n;
	nhapMatrix(A,m,n);
	sortMatrix(A,m,n);
	xuatMatrix(A,m,n);
	return 0;
}

void nhapMatrix(int A[][SIZE], int &m, int &n)
{
	scanf("%d%d",&m,&n);
	for (int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&A[i][j]);
}

void convertToArray(int A[][SIZE], int m, int n, int B[SIZE], int &sizeB)
{
	sizeB=0;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			B[sizeB++]=A[i][j];
}

void convertToMatrix(int B[], int sizeB, int A[][SIZE], int m, int n)
{
	int nB=0;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			A[i][j]=B[nB++];
}
void swap(int &x, int &y)
{
	int t=x;
	x=y;
	y=t;
}

void sort(int A[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (A[i]>A[j])
				swap(A[i],A[j]);
}

void sortMatrix(int A[][SIZE], int m, int n)
{
	int B[SIZE], nB;
	convertToArray(A,m,n,B,nB);
	sort(B,nB);
	convertToMatrix(B,nB,A,m,n);
}

void xuatMatrix(int A[][SIZE], int m, int n)
{
	for (int i=0;i<m;i++)
	{
		//for (int j=0;j<n;j++)
			printf("%d\t",A[i]);
		printf("\n");
	}
}
