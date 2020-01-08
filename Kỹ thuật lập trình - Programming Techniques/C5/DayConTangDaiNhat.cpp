#include <stdio.h>
#define SIZE 100
#define oo 100000
void nhap(int A[], int &n);
void QHD(int A[], int n, int L[], int P[]);
void TruyVet(int A[], int L[], int P[], int pos);

int main(){
	int A[SIZE]={0}, n;
	int L[SIZE]={0}, P[SIZE]={0};
	nhap(A,n);
	QHD(A,n,L,P);
	int kq=L[n]-1;
	printf("%d\n",kq);
	TruyVet(A,L,P,P[n]);
	return 0;
}

void nhap(int A[], int &n){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void QHD(int A[], int n, int L[], int P[]){
	A[n]=oo;
	for (int i=0;i<=n;i++){
		L[i]=1;
		for (int j=0;j<i;j++)
			if (A[j]<=A[i] && L[i]<L[j]){
				L[i]=L[j]+1;
				P[i]=j;
			}
	}
	for (int i=0;i<=n;i++)printf("%d ",P[i]);printf("\n");
}

void TruyVet(int A[], int L[], int P[], int pos){
	if (L[pos]==1){
		printf("%d ",A[pos]);
		return;
	}
	TruyVet(A,L,P,P[pos]);
	printf("%d ",A[pos]);
}
