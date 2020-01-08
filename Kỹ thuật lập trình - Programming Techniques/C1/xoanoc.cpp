#include <stdio.h>
#define SIZE 100

void xuatMang(int A[][SIZE], int m, int n);
void draw(int A[][SIZE], int Ndong, int Ncot);

int main()
{
	int A[SIZE][SIZE]={0},n=5;
	draw(A,n,n);
	xuatMang(A,n,n);
	return 0;
}

void xuatMang(int A[][SIZE], int m, int n)
{
	n++;
	for (int i=0;i<m;i++)
	{
		for (int j=1;j<n;j++)
			printf("%d\t",A[i][j]);
		printf("\n");
	}
}

void draw(int A[][SIZE], int m, int n)
{
	n++;
	A[0][0]=-1;	A[0][n]=-1;	A[m-1][0]=-1;	A[m][n-1]=-1;
	int count=1, i=0, j=1;
	while (count<=m*(n-1))
	{
		while (A[i][j]==0)
			A[i][j++]=count++;
		j--;i++;
		while (A[i][j]==0)
			A[i++][j]=count++;
		i--;j--;
		while (A[i][j]==0)
			A[i][j--]=count++;
		j++;i--;
		while (A[i][j]==0)
			A[i--][j]=count++;
		i++;j++;
	}
}
