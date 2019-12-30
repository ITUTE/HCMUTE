#include <stdio.h>
#define SIZE 100

void nhapMaTran(int A[][SIZE], int &m, int &n);
int isDecrease(int A[][SIZE],int m, int n, int k);

int main()
{
	int A[SIZE][SIZE];
	int m, n;
	nhapMaTran(A,m,n);
	int k;
	scanf("%d",&k);
	int kq=isDecrease(A,m,n,k);
	printf("%d",kq);
	return 0;
}

void nhapMaTran(int A[][SIZE], int &m, int &n)
{
	scanf("%d%d",&m,&n);
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			scanf("%d",&A[i][j]);
}

int isDecrease(int A[][SIZE],int m, int n, int k)
{
	for (int j=0;j<n-1;j++)
		if (A[k][j]<A[k][j+1]) return 0;
	return 1;
}
