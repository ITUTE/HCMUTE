#include <stdio.h>
#include <stdlib.h>
#define SIZE 200
#define PATH2 "array_2.txt"

void draw(int A[][SIZE], int n);
void printArray_2(int A[][SIZE], int m, int n);

int main()
{
	int A[SIZE][SIZE];
	int n;			//n la so LE
	scanf("%d",&n);
	draw(A,n);
	printArray_2(A,n,n);
	return 0;
}

void draw(int A[][SIZE], int n)
{
	int i=n/2;
	int j=n/2+1;
	int count=1;
	while (count<=n*n)
	{
		while (A[i][j]==0 && i>=0 && i<n && j>=0 && j<n)
			A[i--][j++]=count++;
		
		if (j>=n)
			j=0;
		else if (j<0)
		 	j=n-1;
		if (i>=n)
			i=0;
		else if (i<0)
			i=n-1;
		if (A[i][j]!=0)
		{
			j++;
			i++;
		}
	}
}

void printArray_2(int A[][SIZE], int m, int n)
{
	FILE *fi=fopen(PATH2,"wt");
	if (fi!=NULL)
		for (int i=0;i<m;i++)
		{
			for (int j=0;j<n;j++)
				fprintf(fi,"%d\t",A[i][j]);
			fprintf(fi,"\n");
		}
	else exit(0);
	fclose(fi);
}
