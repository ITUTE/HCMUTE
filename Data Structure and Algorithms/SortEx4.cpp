#include <stdio.h>
void Xuat(int A[][4], int row, int col);
void Sort(int A[][4], int row, int col);
void swap(int &a, int &b);

int main()
{
	int A[4][4]=
	{
		{7,4,0,4},
		{3,8,1,5},
		{9,2,6,3},
		{1,0,3,7}
	};
	int row=4;
	int col=4;
	//Xuat(A,row,col);
	Sort(A,row,col);
	Xuat(A,row,col);
	return 0;
}

void Xuat(int A[][4], int row, int col)
{
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<col;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
		
}

void Sort(int A[][4], int row, int col)
{
	for (int i=0;i<row*col-1;i++)
		for (int j=i+1;j<row*col;j++)
		{
			if (A[i/col][i%col]>A[j/col][j%col])
				swap(A[i/col][i%col],A[j/col][j%col]);
		}
	for (int i=1;i<row;i+=2)
		for (int j=0;j<col/2;j++)
			swap(A[i][j],A[i][col-j-1]);
}

void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
