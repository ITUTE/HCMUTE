#include <stdio.h>
#define SIZE 100
#define INF 100000

int n, M;
int A[SIZE];
int F[SIZE][SIZE]={0}, X[SIZE][SIZE]={0};
void nhap();
void DoiTien();
void trace();

int main(){
	nhap();
	DoiTien();
	trace();
	return 0;
}

void nhap(){
	scanf("%d%d",&n,&M);
	for (int i=1;i<=n;i++)
		scanf("%d",&A[i]);
}

void DoiTien(){
	for (int j=1;j<=M;j++)
		if (j%A[1])
			F[1][j]=INF;
		else{
			F[1][j]=j/A[1];
			X[1][j]=j/A[1];
		}
	for (int k=2;k<=n;k++)
		for (int m=1;m<=M;m++){
			F[k][m]=INF;
			for (int x=0;x<=m/A[k];x++){
				int tmp=F[k-1][m-x*A[k]]+x;
				if (tmp<F[k][m]){
					F[k][m]=tmp;
					X[k][m]=x;
				}
			}
		}
}

void trace(){
	if (F[n][M]==INF)
		printf("KHONG DOI DUOC!");
	else{
		int T[SIZE]={0};
		int m=M, k=n;
		while (m){
			while (X[k][m]==0) k--;
			T[k]=X[k][m];
			m-=A[k]*X[k][m];
		}
		printf("%d\n",F[n][M]);
		for (int i=1;i<=n;i++)
			if (T[i])
				printf("%d: %d x %d\n",i,A[i],T[i]);
	}
}
