//R^2 to R

#include <stdio.h>
#include <stdlib.h>
#define PATH "array.txt"
#define PATH2 "array_2.txt"
#define SIZE 100

void scanArray(int A[], int &n);
void chuyenDoi(int A1[], int n1, int A2[][SIZE], int m, int n);
void printArray_2(int A[][SIZE], int m, int n);

int main()
{
	int A2[SIZE][SIZE],A1[SIZE*SIZE],m,n,n1;
	scanArray(A1,n1);
	scanf("%d%d",&m,&n);
	chuyenDoi(A1,n1,A2,m,n);
	printArray_2(A2,m,n);
	return 0;
}

void scanArray(int A[], int &n)
{
	FILE *fo=fopen(PATH,"rt");
	if (fo==NULL)
		exit(0);
	fscanf(fo,"%d",&n);
	for (int i=0;i<n;i++)
		fscanf(fo,"%d",&A[i]);
	fclose(fo);
}

void chuyenDoi(int A1[], int n1, int A2[][SIZE], int m, int n)
{
	n1=0;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			A2[i][j]=A1[n1++];	
}

void printArray_2(int A[][SIZE], int m, int n)
{
	FILE *fi=fopen(PATH2,"wt");
	if (fi==NULL)
		exit(0);
	fprintf(fi,"%d %d\n",m,n);
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
			fprintf(fi,"%d ",A[i][j]);
		fprintf(fi,"\n");
	}
	fclose(fi);
}
