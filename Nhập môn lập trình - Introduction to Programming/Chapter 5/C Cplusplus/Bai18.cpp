#include <stdio.h>
#define SIZE 100

void nhapMaTran(int A[][SIZE], int &m, int &n);
int count(int A[][SIZE], int m, int n);

int main()
{
	int A[SIZE][SIZE];
	int m,n;
	nhapMaTran(A,m,n);
	int kq=count(A,m,n);
	printf("%d",kq);
	return 0;
}

void nhapMaTran(int A[][SIZE], int &m, int &n)
{
	scanf("%d%d",&m,&n);
	int i,j;
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			scanf("%d",&A[i][j]);	
}

int count(int A[][SIZE], int m, int n)
{
	//Dem so chan tren biên cua A[][]
	int d=0,i,j;
	for (j=0;j<n;j++)
	{
		if (A[0][j]%2==0) d++;
		if (A[m-1][j]%2==0) d++;
	}
	for (i=1;i<m-1;i++)
	{
		if (A[i][0]%2==0) d++;
		if (A[i][n-1]%2==0) d++;
	}
	return d;
}
