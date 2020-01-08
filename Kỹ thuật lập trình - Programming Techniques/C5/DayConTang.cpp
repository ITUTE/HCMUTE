#include <stdio.h>
#define SIZE 100
#define oo	100000

void nhap(int A[], int &n);
void QHD(int A[], int n, int L[], int T[]);
void TruyVet(int A[], int n, int L[], int T[]);

int main(){
	int A[SIZE]={0}, L[SIZE]={0}, T[SIZE]={0}, n;
	nhap(A,n);
	QHD(A,n,L,T);
	printf("%d\n",L[0]);
	TruyVet(A,n,L,T);
	return 0;
}

void nhap(int A[], int &n){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&A[i]);
}

void QHD(int A[], int n, int L[], int T[]){
	L[n]=1;		A[0]= -oo;
	for (int i=n-1;i>=0;i--){
		int j,jmax=i;
		for (j=i+1;j<=n;j++)
			if (A[j]>A[i] && L[j]>L[jmax])	jmax=j;
		L[i]=L[jmax]+1;
		T[i]=jmax;
	}
}

void TruyVet(int A[], int n, int L[], int T[]){
	int i=T[0];
	while (i<n){
		printf("%d  ",A[i]);
		i=T[i];
	}
}
