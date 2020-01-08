#include <stdio.h>
#define SIZE 100

void nhap(int A[], int &n, int &W);
void xuat(int A[][SIZE], int m, int n);
void balo(int A[], int n, int W, int B[][SIZE]);
void Trace(int A[], int n, int W, int B[][SIZE]);
int max(int x, int y);

int main(){
	int A[SIZE]={0}, B[SIZE][SIZE]={0}, n, W;
	nhap(A,n,W);
	balo(A,n,W,B);
	xuat(B,n,W);
	printf("\n%d\n",B[n][W]);
	Trace(A,n,W,B);
	return 0;
}

void nhap(int A[], int &n, int &W){
	scanf("%d%d",&n,&W);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}
void balo(int A[], int n, int W, int B[][SIZE]){
	for (int i=1;i<=n;i++)
		for (int v=1;v<=W;v++)
			if (v<A[i-1])
				B[i][v]=B[i-1][v];
			else B[k][v]=max(B[k-1][v], B[k-1][v-A[k]]+A[k]);
}
int max(int x, int y){
	if (x>y)
		return x;
	return y;
}
void Trace(int A[], int n, int W, int B[][SIZE]){
	int i=n, v=W;
	int flag[SIZE]={0};
	while (v){
		if (B[i][v]>B[i-1][v]){
			flag[i]=1;
			v=B[i][v]-A[i-1];
		}
		else i--;
	}
	for (i=1;i<=n;i++)
		if (flag[i])
			printf("%d ",A[i-1]);
}
void xuat(int A[][SIZE], int m, int n)
{
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%d\t",A[i][j]);
		printf("\n");
	}
	printf("\n");
}
