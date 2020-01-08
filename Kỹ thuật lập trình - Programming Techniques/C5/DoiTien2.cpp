#include <stdio.h>
#include <string.h>
#define SIZE 100

int n, M;
int A[SIZE];
int F[SIZE]={0}, X[SIZE]={0};

void nhap();
void DoiTien();
void trace();
void sort(int A[]);

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
	sort(A);
	for (int i=1;i<=M;i++)
		F[i]=99;
	for (int m=1;m<=M;m++)
		for (int k=1;k<=n;k++)
			if (m>=A[k]){
				int tmp=F[m-A[k]]+1;
				if (tmp<F[m]){
					F[m]=tmp;
					X[m]=k;
			}
		}
	for (int i=1;i<=M;i++)
		printf("%2d ",F[i]);
	printf("\n");
	for (int i=1;i<=M;i++)	
		printf("%2d ",X[i]);
	printf("\n");
}

void sort(int A[]){
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
			if (A[i]>A[j]){
				int tmp=A[i];
				A[i]=A[j];
				A[j]=tmp;
			}
}

void trace(){
	int m=M;
	while (m>0){
		printf("%d\n",A[X[m]]);
		m-=A[X[m]]*X[m];
	}
}
