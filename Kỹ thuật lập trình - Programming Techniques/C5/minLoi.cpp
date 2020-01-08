#include <stdio.h>
#define SIZE 100
#define oo	100000

void nhap(int A[][SIZE], int &m, int &n);
int diemloi(int A[][SIZE], int row, int col);
void solve(int A[][SIZE], int m, int n, int &row, int &col);

int main(){
	int A[SIZE][SIZE]={0}, m,n, row=-1, col=-1;
	nhap(A,m,n);
	solve(A,m,n,row,col);
	if (row+col<0)
		printf("-1");
	else printf("%d %d",row,col);
	return 0;
}

void nhap(int A[][SIZE], int &m, int &n){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&A[i][j]);
}

void solve(int A[][SIZE], int m, int n, int &row, int &col){
	int i,j;
	int min=oo;
	for (i=0;i<=n+1;i++)
		A[0][i]=A[m+1][i]=A[i][0]=A[i][n+1]=oo;
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
			if (diemloi(A,i,j) && A[i][j]<min){
				min=A[i][j];
				row=i-1;	col=j-1;
			}
	
}

int diemloi(int A[][SIZE], int row, int col){
	if (A[row][col]>A[row+1][col] && A[row][col]>A[row-1][col] && A[row][col]>A[row][col+1] && A[row][col]>A[row][col-1])
		return 1;
	return 0;
}
