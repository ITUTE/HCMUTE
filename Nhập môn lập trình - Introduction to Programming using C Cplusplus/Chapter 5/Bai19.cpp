//Dem Queen: so lon nhat tren dong, cot, 2 duong cheo

#include <stdio.h>
#define SIZE 100

void nhapMaTran(int A[][SIZE], int &m, int &n);
int max_Row(int A[][SIZE], int row, int n, int posCol);
int max_Col(int A[][SIZE], int m, int col, int posRow);
int max_CheoChinh(int A[][SIZE], int m, int n, int x, int y);
int max_CheoPhu(int A[][SIZE], int m, int n, int x, int y);
int countQueen(int A[][SIZE], int m, int n);

int main()
{
	int A[SIZE][SIZE];
	int m,n;
	nhapMaTran(A,m,n);
	int kq=countQueen(A,m,n);
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

int max_Row(int A[][SIZE], int row, int n, int posCol)
{
	for (int j=0;j<n;j++)
		if (A[row][j]>A[row][posCol]&&j!=posCol)
			return 0;
	return 1;
}

int max_Col(int A[][SIZE], int m, int col, int posRow)
{
	for (int i=0;i<m;i++)
		if (A[i][col]>A[posRow][col]&&i!=posRow)
			return 0;
	return 1;
}

int max_CheoChinh(int A[][SIZE], int m, int n, int x, int y)
{
	int i=x-1,j=y-1;
	while (i>=0&&j>=0)
	{
		if (A[i][j]>A[x][y]) return 0;
		else
		{
			i--;
			j--;
		}
	}
	i=x+1;j=y+1;
	while (i<m&&j<n)
	{
		if (A[i][j]>A[x][y]) return 0;
		else
		{
			i++;
			j++;
		}
	}
	return 1;
}

int max_CheoPhu(int A[][SIZE], int m, int n, int x, int y)
{
	int i=x-1,j=y+1;
	while (i>=0&&j<n)
	{
		if (A[i][j]>A[x][y]) return 0;
		else
		{
			i--;
			j++;
		}
	}
	i=x+1,j=y-1;
	while (i<m&&j>=0)
	{
		if (A[i][j]>A[x][y]) return 0;
		else
		{
			i++;
			j--;
		}
	}
	return 1;
}

int countQueen(int A[][SIZE], int m, int n)
{
	//Queen: so lon nhat tran dong, cot, 2 duong cheo
	int count=0;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (max_Row(A,i,n,j)&&max_Col(A,m,j,i)&&max_CheoChinh(A,m,n,i,j)&&max_CheoPhu(A,m,n,i,j))
				count++;
	return count;
}
