//Dem "yen ngua": so lon nhat tren dong, nho nhat tren cot

#include <stdio.h>
#define SIZE 100

void nhapMaTran(int A[][SIZE], int &m, int &n);
int max_Row(int A[][SIZE], int row, int n, int posCol);
int min_Col(int A[][SIZE], int m, int col, int posRow);
int countYenNgua(int A[][SIZE], int m, int n);

int main()
{
	int A[SIZE][SIZE];
	int m,n;
	nhapMaTran(A,m,n);
	int kq=countYenNgua(A,m,n);
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

int min_Col(int A[][SIZE], int m, int col, int posRow)
{
	for (int i=0;i<m;i++)
		if (A[i][col]<A[posRow][col]&&i!=posRow)
			return 0;
	return 1;
}

int countYenNgua(int A[][SIZE], int m, int n)
{
	//Yen ngua: so lon nhat tren dong, nho nhat tren cot
	int count=0;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (max_Row(A,i,n,j)&&min_Col(A,m,j,i))
				count++;
	return count;
}
