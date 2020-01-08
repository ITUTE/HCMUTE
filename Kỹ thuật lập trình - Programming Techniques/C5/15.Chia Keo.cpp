#include <stdio.h>
#define SIZE 100
void Nhap(int A[], int &n);
int Sum(int A[], int n);
void ChiaKeo(int A[], int P1[], int n, int &value);
void balo(int A[], int n, int W, int B[][SIZE]);
void Trace(int A[], int n, int W, int B[][SIZE], int flag[]);
void xuat(int A[], int n, int P1[], int value);

int main()
{
	int A[SIZE]={0}, P1[SIZE]={0}, n, value=0;
	Nhap(A,n);
	ChiaKeo(A,P1,n,value);
	xuat(A,n,P1,value);
	return 0;
}

void xuat(int A[], int n, int P1[], int value){
	printf("%d\n",value);
	for (int i=0;i<n;i++)
		if (P1[i+1])
			printf("%d ",A[i]);
	printf("\n%d\n",Sum(A,n)-value);
	for (int i=0;i<n;i++)
		if (P1[i+1]==0)
			printf("%d ",A[i]);
}
void ChiaKeo(int A[], int P1[], int n, int &value){
	int B[SIZE][SIZE]={0};
	int W=Sum(A,n)/2;
	balo(A,n,W,B);
	Trace(A,n,W,B,P1);
	value=B[n][W];
}
void balo(int A[], int n, int W, int B[][SIZE]){
	for (int i=1;i<=n;i++)
		for (int v=1;v<=W;v++)
			if (v<A[i-1])
				B[i][v]=B[i-1][v];
			else
				if (B[i-1][v]>B[i-1][v-A[i-1]]+A[i-1])
					B[i][v]=B[i-1][v];
				else B[i][v]=B[i-1][v-A[i-1]]+A[i-1];
}
void Trace(int A[], int n, int W, int B[][SIZE], int flag[]){
	int i=n, v=W;
	while (v){
		if (B[i][v]>B[i-1][v]){
			flag[i]=1;
			v=B[i][v]-A[i-1];
		}
		else i--;
	}
}
int Sum(int A[], int n){
	int s=0;
	for (int i=0;i<n;i++)
		s+=A[i];
	return s;
}
void Nhap(int A[], int &n){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}
