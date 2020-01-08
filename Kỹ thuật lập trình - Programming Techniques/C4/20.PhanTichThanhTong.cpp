#include <stdio.h>
#define SIZE 100

int A[SIZE]={0}, T[SIZE]={0};
int n;
void xuat(int A[], int n);
void PhanTich(int i);

int main(){
	scanf("%d",&n);
	A[0]=1;
	PhanTich(1);
	return 0;
}

void PhanTich(int i){
	for (int j=A[i-1];j<=n-T[i-1];j++){
		A[i]=j;
		T[i]=T[i-1]+A[i];
		if (T[i]==n)
			xuat(A,i);
		else PhanTich(i+1);
	}
}

void xuat(int A[], int n){
	for (int i=1;i<=n;i++)
		printf("%d ",A[i]);
	printf("\n");
}
