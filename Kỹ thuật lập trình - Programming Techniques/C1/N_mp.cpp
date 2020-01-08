#include <stdio.h>

#define SIZE 100
void input(int A[][SIZE], int &n);
void maPhuong(int A[][SIZE], int n);
void output(int A[][SIZE], int n);

int main()
{
	int A[SIZE][SIZE] = { 0 };
	int n;
	input(A, n);
	maPhuong(A, n);
	output(A, n);
	
	return 0;
}
void output(int A[][SIZE], int n)
{
	for (int i = 0; i < (2 * n) - 1; i++)
	{
		for (int j = 0; j < (2 * n) - 1; j++)
			printf("%d\t", A[i][j]);
		printf("\n");
	}
}
void maPhuong(int A[][SIZE], int n)
{
	int t = 0;
	int c=n;
	int dem=0;
	while (dem < n * n)
	{
		for (int i = t; i < c; i++)
		{
			int x = c - 1 - i;
			A[x][i] = ++dem;
		}	
		++t;
		++c;
	}
}
void input(int A[][SIZE], int &n)
{
	printf("NHAP N: ");
	scanf("%d", &n);
	if (n % 2 == 0)
	{
		printf("NHAP LAI N, N LA SO LE: ");
		scanf("%d", &n);
	}
}

