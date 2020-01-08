#include <stdio.h>
#define SIZE 100

int n, sum=0, W, sum_subA=0;
int A[SIZE]={0}, F[SIZE][SIZE]={0};
bool flag[SIZE]={0};

void xuat(int sum, int value);
void chiaKeo();
void trace();
int max(int x, int y);

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		sum+=A[i];
	}
	W=sum/2;
	chiaKeo();
	trace();
	xuat(sum_subA,1);
	xuat(sum-sum_subA,0);
	return 0;
}

void xuat(int sum, int value){
	printf("\nSo keo chia cho nguoi %d la: %d\n",2-value,sum);
	for (int i=1;i<=n;i++)
		if (flag[i]==value)
			printf("%d ",A[i]);
}

void chiaKeo(){
	for (int k=1;k<=n;k++)
		for (int v=1;v<=W;v++)
			if (v<A[k])
				F[k][v]=F[k-1][v];
			else 
				F[k][v]=max(F[k-1][v], F[k-1][v-A[k]]+A[k]);
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
			v=F[k][v]-A[k];
			sum_subA+=A[k];
		}
		k--;
	}
}
