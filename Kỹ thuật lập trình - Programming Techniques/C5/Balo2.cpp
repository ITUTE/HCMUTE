#include <stdio.h>
#define SIZE 100

int n, W;
int A[SIZE]={0}, C[SIZE]={0};
int F[SIZE][SIZE]={0}, flag[SIZE]={0};
void nhap();
int max(int x, int y);
void balo2();
void trace();
void xuat();

int main(){
	nhap();
	balo2();
	trace();
	xuat();
	return 0;
}

void nhap(){
	scanf("%d%d",&n,&W);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&A[i],&C[i]);
}

void balo2(){
	for (int k=1;k<=n;k++)
		for (int v=1;v<=W;v++)
			if (v<A[k])
				F[k][v]=F[k-1][v];
			else
				F[k][v]=max(F[k-1][v], F[k-1][v-A[k]]+C[k]);
}

int max(int x, int y){
	if (x>y)
		return x;
	return y;
}

void trace(){
	int k=n, v=W;
	while (k){
		if (F[k][v]!=F[k-1][v]){
			flag[k]=1;
			v-=A[k];				//notice
		}
		k--;
	}
}

void xuat(){
	printf("Value= %d\n",F[n][W]);
	for (int k=1;k<=n;k++)
		if (flag[k])
			printf("%d(%d,%d)\n",k,A[k],C[k]);
}
