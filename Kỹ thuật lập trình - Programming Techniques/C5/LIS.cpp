#include <stdio.h>
void nhap(int A[], int &n);
void trace(int i);
void LIS();
int A[100], n;
int L[100]={0}, P[100]={0};

int main(){
	nhap(A,n);
	LIS();
	printf("%d\n",L[n]-1);
	trace(n);
	return 0;
}

void nhap(int A[], int &n){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void LIS(){
	A[n]=100000;
	for (int i=0;i<=n;i++){
		L[i]=1; P[i]=-1;
		for (int j=i-1;j>=0;j--)
			if (A[j]<A[i] && L[i]<L[j]+1){
				L[i]=L[j]+1;
				P[i]=j;
			}
	}
}

void trace(int i){
	if (P[i]<0)
		return;
	trace(P[i]);
	printf("%d ",A[P[i]]);
}
