#include <stdio.h>
#include <stdlib.h>
#define PATH "LatinQuare.txt"
#define SIZE 100

int A[SIZE][SIZE]={0}, n;
int feasible(int k, int row, int col);
void LatinSquare(int row, int col);
void xuat();

int main(){
	scanf("%d",&n);
	LatinSquare(0,0);
	return 0;
}

/*
	Matrix[0..n-1][0..n]
*/
void LatinSquare(int row, int col){
	if (col==n){					//o tan cung ben phai
		if (row==n-1){				//o tan cung cua table
			xuat();
		//	exit(0);
		}
		else{
			LatinSquare(row+1,0);
		}
	}
	else{
		//Tim gia tri thich hop cho o (row,col)
		for (int k=1;k<=n;k++)
			if (feasible(k,row,col)){
				A[row][col]=k;
				LatinSquare(row,col+1);	//col+1 nen co the vuot ra khoi bien (border)
				A[row][col]=0;			//Backtrack
			}
	}
}

int feasible(int k, int row, int col){
	int i,j;
	//Kiem tra cot
	for (i=0;i<n;i++)
		if (A[i][col]==k)	return 0;
	//Kiem tra dong
	for (j=0;j<n;j++)
		if (A[row][j]==k)	return 0;
	//Kiem tra khoi 3x3
	int i_start=row/3,	j_start=col/3;
	for (i=3*i_start;i<3*i_start+3;i++)
		for (j=3*j_start;j<3*j_start+3;j++)
			if (A[i][j]==k)	return 0;
	return 1;
}

void xuat()
{
	FILE *f=fopen(PATH,"a");
	if (f==NULL)
		exit(0);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)
			fprintf(f,"%d\t",A[i][j]);
		fprintf(f,"\n");
	}
	fprintf(f,"\n");
	fclose(f);
}
