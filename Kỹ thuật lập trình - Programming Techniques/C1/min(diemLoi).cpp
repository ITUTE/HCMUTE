#include <stdio.h>
#include <stdlib.h>
#define PATH2 "array_2.txt"
#define SIZE 100
#define MIN_VALUE -9999999

void scanArray_2(float A[][SIZE], int &m, int &n);
void printArray_2(float A[][SIZE], int m, int n);
int find(float A[][SIZE], int m, int n, int &row, int &column);
int check(float A[][SIZE], int i, int j);

int main()
{
	float A[SIZE][SIZE];
	int m,n;
	scanArray_2(A,m,n);
	//printArray_2(A,m,n);
	int row, column;
	int kq=find(A,m,n,row,column);
	if (kq)
		printf("%d %d",row,column);	
	else printf("%d",-1);		
	return 0;
}

void scanArray_2(float A[][SIZE], int &m, int &n)
{
	FILE *fo=fopen(PATH2,"rt");
	if (fo==NULL)
		exit(0);
	else
	{
		fscanf(fo,"%d%d",&m,&n);
		m+=2;n+=2;
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
			{
				if (i==0||i==m-1||j==0||j==n-1)
					A[i][j]=MIN_VALUE;
				else fscanf(fo,"%f",&A[i][j]);
			}
		fclose(fo);
	}
}

int find(float A[][SIZE], int m, int n, int &row, int &column)
{
	row=-1;
	column=-1;
	int found=0;
	int min;
	{
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
				if (check(A,i,j)==1 && (A[i][j]<min || found==0))
				{
					row=i;
					column=j;
					min=A[i][j];
					found=1;
				}
	}
	return found;
}

int check(float A[][SIZE], int i, int j)
{
	if (A[i][j]>A[i+1][j] && A[i][j]>A[i-1][j] && A[i][j]>A[i][j+1] && A[i][j]>A[i][j-1])
		return 1;
	return 0;
}

void printArray_2(float A[][SIZE], int m, int n)
{
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
			printf("%.0f\t",A[i][j]);
		printf("\n");
	}
}
