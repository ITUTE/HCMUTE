#include <stdio.h>

void Xuat(int A[][4], int row, int col);
void Sort(int A[][4], int row, int col);

int main()
{
	int A[][4]=
	{
		{1,5,2,7},
		{2,5,9,6},
		{8,7,4,0},
		{3,6,4,0}
	};
	int row=4, col=4; 
	Sort(A,row,col);
	Xuat(A,row,col);
	return 0;
} 

void Sort(int A[][4], int row, int col)
{
	int count=0;
	int top=0, left=0;
	int max=row*col;
	while (count<max)
	{
		for (int k=left;k<col;k++)
			A[top][k]=count++;
		top++;
		for (int k=top;k<row;k++)
			A[k][col-1]=count++;
		col--;
		for (int k=col-1;k>=left;k--)
			A[row-1][k]=count++;
		row--;
		for (int k=row-1;k>=top;k--)
			A[k][left]=count++;
		left++;
	}
}

void Xuat(int A[][4], int row, int col)
{
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
			printf("%5d",A[i][j]);
		printf("\n");
	}
}
