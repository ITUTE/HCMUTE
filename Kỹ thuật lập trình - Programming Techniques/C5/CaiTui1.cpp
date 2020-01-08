#include <stdio.h>
#define SIZE 100

void nhap(int A[], int &n);
void QHD(int A[], int n, int W, int L[][SIZE]);

int main(){
	int n, W, A[SIZE]={0}, L[SIZE][SIZE]={0};
	scanf("%d",&W);
	QHD(A,n,W,L);
	nhap(A,n);
	
	return 0;
}

void nhap(int A[], int &n){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}
void QHD(int A[], int n, int W, int L[][SIZE]){
	int i,j;
	for (i=0;i<n;i++){
		L[i][0]=L[0][i]=0;
	}
}
