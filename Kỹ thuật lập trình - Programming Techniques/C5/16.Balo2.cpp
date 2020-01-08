#include <stdio.h>
#define SIZE 100
void Nhap(int A[], int C[], int &n, int &W);
void Balo2(int A[], int C[], int F[][SIZE], int n, int W);
void Trace(int A[], int C[], int F[][SIZE], int flag[], int n, int W, int &value);
void Xuat(int A[], int C[], int flag[], int n, int value);

int main()
{
	int A[SIZE]={0}, C[SIZE]={0}, F[SIZE][SIZE]={0}, flag[SIZE]={0};
	int n, W, value=0;
	Nhap(A,C,n,W);
	Balo2(A,C,F,n,W);
	Trace(A,C,F,flag,n,W,value);
	Xuat(A,C,flag,n,value);
	return 0;
}

void Xuat(int A[], int C[], int flag[], int n, int value){
	printf("%d\n",value);
	for (int i=1;i<=n;i++)
		if (flag[i])
			printf("%d(%d,%d)\n",i,A[i-1],C[i-1]);
}
void Balo2(int A[], int C[], int F[][SIZE], int n, int W){
	for (int i=1;i<=n;i++)
		for (int v=1;v<=W;v++)
			if (v<A[i-1])
				F[i][v]=F[i-1][v];
			else
				if (F[i-1][v]>F[i-1][v-A[i-1]]+C[i-1])
					F[i][v]=F[i-1][v];
				else F[i][v]=F[i-1][v-A[i-1]]+C[i-1];
}
void Trace(int A[], int C[], int F[][SIZE], int flag[], int n, int W, int &value){
	int i=n, v=W;
	value=F[i][v];
	while (i*v){
		if (F[i][v]>F[i-1][v]){
			flag[i]=1;
			v-=A[i-1];
		}
		else i--;
	}
}
void Nhap(int A[], int C[], int &n, int &W){
	scanf("%d%d",&n,&W);
	for (int i=0;i<n;i++)
		scanf("%d%d",&A[i],&C[i]);
}
