#include <stdio.h>
#define SIZE 100
int A[SIZE]={0}, C[SIZE]={0};
int F[SIZE][SIZE]={0}, X[SIZE][SIZE]={0};
int flag[SIZE]={0};
int n, W;
void nhap();
void balo3();
void trace();

int main(){
	nhap();
	balo3();
	for (int k=1;k<=n;k++)
	{
		for (int v=1;v<=W;v++)
			printf("(%d;%d)\t",F[k][v],X[k][v]);
			//printf("%-5d",F[k][v]);
		printf("\n");
	}
	trace();
	return 0;
}

void nhap(){
	scanf("%d%d",&n,&W);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&A[i],&C[i]);
}

void balo3(){
	for (int k=1;k<=n;k++){
		for (int v=1;v<=W;v++){
			for (int x=0;x<=v/A[k];x++){
				int tmp=F[k-1][v-x*A[k]]+x*C[k];
				if (F[k][v]<tmp){
					X[k][v]=x;
					F[k][v]=tmp;
				}
			}	
		}
	}
}

void trace(){
	int v=W, k=n, value=F[n][W];
	while (v){
		while (F[k][v]*X[k][v]==0)
			k--;
		flag[k]=X[k][v];
		value=F[k][v];
		v-=A[k]*X[k][v];
	}
	printf("%d\n",F[n][W]);
	for (int i=1;i<=n;i++)
		if (flag[i])
			printf("(%d ; %d) x %d \n",A[i],C[i],flag[i]);
}
