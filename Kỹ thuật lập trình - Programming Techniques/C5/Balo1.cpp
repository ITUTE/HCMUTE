#include <stdio.h>
#define SIZE 100

int A[SIZE]={0}, F[SIZE][SIZE]={0};
int n, W;
void balo1();
void trace();
int max(int x, int y);

int main(){
	scanf("%d%d",&n,&W);
	for (int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	balo1();
	printf("\n%d\n",F[n][W]);
	trace();
	return 0;
}

void balo1(){
	for (int k=1;k<=n;k++)
		for (int v=1;v<=W;v++)
			if (v<A[k])
				F[k][v]=F[k-1][v];
			else F[k][v]=max(F[k-1][v], F[k-1][v-A[k]]+A[k]);
}

int max(int x, int y){
	if (x>y)
		return x;
	return y;
}

void trace(){
	bool flag[SIZE]={0};
	int k=n, v=W;
	while (k){
		if (F[k][v]!=F[k-1][v]){
			flag[k]=1;
			v=F[k][v]-A[k];
		}
		k--;
	}
	for (k=1;k<=n;k++)
		if (flag[k])
			printf("%d ",A[k]);
}
