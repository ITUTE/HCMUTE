#include <stdio.h>
#define SIZE 100
#define PATH2 "array_2.txt"

void create(int A[][SIZE], int tmp[][SIZE], int n);
void pre(int A[][SIZE], int n);
void fill(int A[][SIZE], int n);
void taoMaPhuong(int A[][SIZE], int tmp[][SIZE], int n);
void printArray_2(int A[][SIZE], int m, int n);

int main()
{
	int A[SIZE][SIZE]={0};
	int tmp[SIZE][SIZE]={0};
	int n;
	scanf("%d",&n);
	create(A,tmp,n);
	//printArray_2(tmp,2*n,2*n);
	printArray_2(A,n,n);
	return 0;
}

void create(int A[][SIZE], int tmp[][SIZE], int n)
{
	pre(tmp,n);
	fill(tmp,n);
	taoMaPhuong(A,tmp,n);
}

void fill(int A[][SIZE], int n)
{
	int i,j;
	//TOP
	for (i=0;i<n/2;i++)
		for (j=0;j<2*n-1;j++)
			if (A[i][j]>0)
				A[n+i][j]=A[i][j];
	//BOTTOM
	for (i=n+n/2;i<2*n-1;i++)
		for (j=0;j<2*n-1;j++)
			if (A[i][j]>0)
				A[i-n][j]=A[i][j];
	//LEFT
	for (i=n/2+1;i<n+n/2;i++)
		for (j=0;j<n/2;j++)
			if (A[i][j]>0)
				A[i][n+j]=A[i][j];	
	//RIGHT
	for (i=n/2+1;i<n+n/2;i++)
		for (j=n+n/2;j<2*n-1;j++)
			if (A[i][j]>0)
				A[i][j-n]=A[i][j];
}

void pre(int A[][SIZE], int n)
{
	int count=1;
	int i=n-1;
	while (count<=n*n)
	{
		int row=i;
		int col=i-n+1;
		for (int k=0;k<n;k++)
			A[row--][col++]=count++;
		i++;
	}
}

void taoMaPhuong(int A[][SIZE], int tmp[][SIZE], int n)
{
	for (int i=n/2;i<n+n/2;i++)
	{
		for (int j=n/2;j<n+n/2;j++)
			A[i-n/2][j-n/2]=tmp[i][j];
		//printf("\n");
	}
}

void printArray_2(int A[][SIZE], int m, int n)
{
	FILE *fi=fopen(PATH2,"wt");
	if (fi!=NULL)
	{
		for (int i=0;i<m;i++)
		{
			for (int j=0;j<n;j++)
				fprintf(fi,"%d\t",A[i][j]);
			fprintf(fi,"\n");
		}
		fclose(fi);
	}
}
