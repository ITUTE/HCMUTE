#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#define SIZE 100
#define PATH2 "array_2.txt"
#define MIN_VALUE -5555

void printArray_2(int A[][SIZE], int m, int n, int value);
void create_mine(int A[][SIZE], int m, int n, int value);
int check(int A[][SIZE], int x, int y);
void taoBaiMin(int A[][SIZE], int m, int n);
void game(int A[][SIZE], int m, int n, int value);

int main()
{
	srand(time(NULL));
	int A[SIZE][SIZE];
	int m,n,value;
	scanf("%d%d%d",&m,&n,&value);
	m+=2;n+=2;
	game(A,m,n,value);
	printArray_2(A,m,n,value);
	return 0;
}

void printArray_2(int A[][SIZE], int m, int n, int value)
{
	FILE *fi=fopen(PATH2,"wt");
	if (fi==NULL)
		exit(0);
	fprintf(fi,"%d %d\n%d\n",m,n,value);
	for (int i=1;i<m-1;i++)
	{
		for (int j=1;j<n-1;j++)
			//if (A[i][j]==1) printf("%d ",A[i][j]);
			//else printf(" ");
			fprintf(fi,"%d\t",A[i][j]);
		fprintf(fi,"\n");
	}
	fclose(fi);
}

void create_Borders(int A[][SIZE], int m, int n)
{
	int i, j;
	for (j=0;j<n;j++)
	{
		A[0][j]=MIN_VALUE;
		A[n-1][j]=MIN_VALUE;
	}
	for (i=1;i<n-1;i++)
	{
		A[i][0]=MIN_VALUE;
		A[i][n-1]=MIN_VALUE;
	}
	
}
void game(int A[][SIZE], int m, int n, int value)
{
	create_Borders(A,m,n);
	create_mine(A,m,n,value);
	taoBaiMin(A,m,n);	
}

//Tao ngau nhien vi tri dat Mi`n
void create_mine(int A[][SIZE], int m, int n, int value)
{
	int count=0;
	int i,j;
	while (count<value)
	{
		i=rand()%m+0;
		j=rand()%n+0;
		if (A[i][j]==0)
		{
			A[i][j]=-1;		//Gia tri -1 cho biet vi tri do co Mi`n
			count++;
		}
	} 
}

int check(int A[][SIZE], int x, int y)	//dem so luong Mi`n xung quanh
{
	int count=0;
	for (int i=x-1;i<=x+1;i++)
		for (int j=y-1;j<=y+1;j++)
			if (A[i][j]==-1)
				count++;
	return count;
}

void taoBaiMin(int A[][SIZE], int m, int n)	//tao bai Mi`n
{
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (A[i][j]!=-1&&A[i][j]!=MIN_VALUE)				//tranh vi tri dat Mi`n
				A[i][j]=check(A,i,j);
}
