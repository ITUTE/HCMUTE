#include <stdio.h>
#define SIZE 100
void xuly(int i);
void xuat(int A[], int n);
int A[SIZE]={0}, T[SIZE]={0}, n;

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		T[i]=n-i;
	xuly(0);
	return 0;
}

void xuat(int A[], int n){
	for (int i=0;i<=n;i++)
		printf("%d ",A[i]);
	printf("\n");
}
void xuly(int i){
	for (int j=1;j<=T[i];j++){
		A[i]=j;
		if (A[i]==T[i])
			xuat(A,i);
		else xuly(i+1);
	}
}
