#include <stdio.h>
#include <string.h>
#define SIZE 100
#define oo	1000000

void nhap(int A[][SIZE], int &m, int &n);
int row_max(int A[][SIZE], int start, int end, int col);
int greedy(int A[][SIZE], int m, int n, int path[]);
int backtracking(int A[][SIZE], int m, int n, int path[]);

int main(){
	int A[SIZE][SIZE]={0}, m, n, path[SIZE];
	nhap(A,m,n);
	//int kq=greedy(A,m,n,path);
	int kq=backtracking(A,m,n,path);
	printf("%d\n",kq);
	for (int i=1;i<=n;i++)
		printf("%d\t",path[i]);
	return 0;
}

void nhap(int A[][SIZE], int &m, int &n){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&A[i][j]);
	for (int i=0;i<=m;i++)
		A[i][0]=A[i][n+1]=-oo;
	for (int j=0;j<=n;j++)
		A[0][j]=A[m+1][j]=-oo;
}

int greedy(int A[][SIZE], int m, int n, int path[]){
	int row=-1, col=1;
	row=row_max(A,1,m,col);
	path[col]=A[row][col];
	int count=A[row][col];
	for (col=2;col<=n;col++){
		row=row_max(A,row-1,row+1,col);
		path[col]=A[row][col];
		count+=A[row][col];
	}
	return count;
}

int row_max(int A[][SIZE], int start, int end, int col){
	int max=A[start][col], pos=start;
	for (int i=start+1;i<=end;i++)
		if (A[i][col]>max){
			max=A[i][col];
			pos=i;
		}
	return pos;
}

int backtracking(int A[][SIZE], int m, int n, int path[]){
	int max=-oo, count=0;
	int p[SIZE]={0};
	for (int i=1;i<=m;i++){
		int col=1, row=i;
		count+=A[row][col];
		p[col]=A[row][col];
		for (col=2;col<=n;col++){
			row=row_max(A,row-1,row+1,col);
			p[col]=A[row][col];
			count+=A[row][col];
		}
		if (count>max){
			max=count;
			memcpy(path,p,sizeof(p));
		}
		count=0;
	}
	return max;
}
