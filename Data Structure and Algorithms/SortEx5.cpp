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
		{5,0,1,7}
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
			if (A[i%row][i/row]>A[j%row][j/row])
				swap(A[i%row][i/row],A[j%row][j/row]);
		}
	for (int i=0;i<row/2;i++)
		for (int j=1;j<col;j+=2)
			swap(A[i][j],A[row-1-i][j]);
}

void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
