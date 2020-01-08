#include <stdio.h>
#include <math.h>
#define SIZE 100

void nhapMaTran(int A[][SIZE], int &m, int &n);
int isPrime(int x);
int posFirstPrime(int A[][SIZE], int m, int n, int &iPos, int &jPos);

int main()
{
	int A[SIZE][SIZE];
	int m,n;
	nhapMaTran(A,m,n);
	int iPos,jPos;
	int kq=posFirstPrime(A,m,n,iPos,jPos);
	if (kq)
		printf("A[%d][%d]",iPos,jPos);
	else
		printf("-1");
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

int isPrime(int x)
{
	if (x<2) return 0;
	if (x==2) return 1;
	if (x%2==0) return 0;
	int sqrtX=sqrt(x);
	for (int i=2;i<=sqrtX;i++)
		if (x%i==0) return 0;
	return 1;
}

int posFirstPrime(int A[][SIZE], int m, int n, int &iPos, int &jPos)
{
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (isPrime(A[i][j]))
			{
				iPos=i;
				jPos=j;
				return 1;
			}
	return 0;
}
