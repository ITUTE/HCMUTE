#include <stdio.h>
#define SIZE 1000

void nhapMaTran(int A[][SIZE], int &m, int &n);
int findMax(int A[][SIZE], int m, int n);
void posMax(int A[][SIZE], int m, int n);

int main()
{
	int A[SIZE][SIZE];
	int m,n;
	nhapMaTran(A,m,n);
	//posMax(A,m,n);
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

int findMax(int A[][SIZE], int m, int n)
{
	int max=A[0][0];
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (A[i][j]>max)
				max=A[i][j];
	return max;
}

void posMax(int A[][SIZE], int m, int n)
{
	int max=findMax(A,m,n);
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (A[i][j]==max)
				printf("A[%d][%d]\t",i,j);
}
