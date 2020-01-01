#include <stdio.h>
#define SIZE 100
void Create(int A[][SIZE]);
void Xuat(int A[][SIZE]);

int row=3;
int col=6;
int main()
{
	int A[SIZE][SIZE]={0};
	Create(A);
	Xuat(A);
	return 0;
}

void Create(int A[][SIZE])
{
	int count=0;
	int i=0, j=0;
	while (count<row*col-1)
	{
		while (A[i][j+1]==0 && j+1<col)
			A[i][j++]=++count;
		while (A[i+1][j]==0 && i+1<row)
			A[i++][j]=++count;
		while (A[i][j-1]==0 && j-1>=0)
			A[i][j--]=++count;
		while (A[i-1][j]==0)		
			A[i--][j]=++count;
	}
	A[i][j]=++count;
}

void Xuat(int A[][SIZE])
{
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
			printf("%d\t",A[i][j]);
		printf("\n");
	}
}
