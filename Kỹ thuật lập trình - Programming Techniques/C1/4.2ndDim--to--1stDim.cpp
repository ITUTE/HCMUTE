//R^2 to R

#include <stdio.h>
#include <stdlib.h>
#define PATH "array.txt"
#define PATH2 "array_2.txt"
#define SIZE 100

void scanArray_2(int A[][SIZE], int &m, int &n);
void chuyenDoi_2(int A2[][SIZE], int m, int n, int A1[], int &n1);
void printArray(int A[], int n);

int main()
{
	int A2[SIZE][SIZE],A1[SIZE*SIZE],m,n,n1;
	scanArray_2(A2,m,n);
	chuyenDoi_2(A2,m,n,A1,n1);
	printArray(A1,n1);
	return 0;
}

void scanArray_2(int A[][SIZE], int &m, int &n)
{
	FILE *fo=fopen(PATH2,"rt");
	if (fo==NULL)
	{
		printf("Khong the doc File");
		exit(0);
	}
	fscanf(fo,"%d%d",&m,&n);
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			fscanf(fo,"%d",&A[i][j]);
	fclose(fo);
}

void chuyenDoi_2(int A2[][SIZE], int m, int n, int A1[], int &n1)
{
	n1=0;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			A1[n1++]=A2[i][j];	
}

void printArray(int A[], int n)
{
	FILE *fi=fopen(PATH,"wt");
	if (fi==NULL)
		exit(0);
	fprintf(fi,"%d\n",n);
	for (int i=0;i<n;i++)
		fprintf(fi,"%d ",A[i]);
	fclose(fi);
}
