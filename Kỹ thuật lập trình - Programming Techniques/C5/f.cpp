#include <stdio.h>
#define SIZE 100

void nhap(int A[], int &n);

int main(){
	int A[SIZE]={0}, n;
	int L[SIZE]={0};
	nhap(A,n);
	return 0;
}

void nhap(int A[], int &n){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&A[i]);
}

void QHD(int A[], int n, int L[]){
	int i=0;
	
}
