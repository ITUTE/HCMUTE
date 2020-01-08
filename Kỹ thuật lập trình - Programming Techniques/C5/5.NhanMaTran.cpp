#include <stdio.h>
#define SIZE 100

void nhap(int A[][SIZE], int &m, int &n);
void xuat(int A[][SIZE], int m, int n);
int nhan(int A[][SIZE], int row, int B[][SIZE], int col, int n);
int nhanMaTran();
int A[SIZE][SIZE]={0}, mA, nA;
int B[SIZE][SIZE]={0}, mB, nB;
int C[SIZE][SIZE]={0}, mC, nC;

int main(){
	nhap(A,mA,nA);
	nhap(B,mB,nB);
	if (nhanMaTran())
		xuat(C,mC,nC);
	else printf("-1");
	return 0;
}

void nhap(int A[][SIZE], int &m, int &n){
	scanf("%d%d",&m,&n);
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			scanf("%d",&A[i][j]);
}

void xuat(int A[][SIZE], int m, int n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++)
			printf("%d\t",A[i][j]);
		printf("\n");
	}
}
int nhanMaTran(){
	if (nA!=mB)
		return 0;
	mC=mA;	nC=nB;
	for (int i=0;i<mC;i++)
		for (int j=0;j<nC;j++)
			C[i][j]=nhan(A,i,B,j,nA);
	return 1;
}

int nhan(int A[][SIZE], int row, int B[][SIZE], int col, int n){
	int sum=0;
	for (int i=0;i<n;i++)
		sum+=A[row][i]*B[i][col];
	return sum;
}
