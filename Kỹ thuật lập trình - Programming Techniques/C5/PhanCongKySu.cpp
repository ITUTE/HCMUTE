#include <stdio.h>
#define SIZE 100

int m, n;
int A[SIZE][SIZE]={0};
int F[SIZE][SIZE]={0}, X[SIZE][SIZE]={0}; //X[i][j] cho biet phan cong i nguoi vao phong j
void nhap();
void PhanCongKySu();
void trace(int i, int j);

int main(){
	nhap();
	PhanCongKySu();
	trace(m,n);
	return 0;
}

void nhap(){
	scanf("%d%d",&m,&n);
	for (int i=0;i<=m;i++)
		for (int j=1;j<=n;j++)
			scanf("%d",&A[i][j]);
}

void PhanCongKySu(){
	int i, j;
	for (i=0;i<=m;i++){
		F[i][1]=A[i][1];
		X[i][1]=i;
	}
	for (j=1;j<=n;j++)
		F[0][j]=F[0][j-1]+A[0][j];
	for (i=1;i<=m;i++)
		for (j=2;j<=n;j++){
			int tmp=0;
			F[i][j]=10000;
			for (int k=0;k<=i;k++){
				tmp=F[i-k][j-1]+A[k][j];
				if (tmp<F[i][j]){
					F[i][j]=tmp;
					X[i][j]=k;
				}
			}
		}
	
	for (i=0;i<=m;i++){
		for (j=1;j<=n;j++)
			printf("(%2d;%2d)  ",F[i][j],X[i][j]);
		printf("\n");
	}
}

void trace(int i, int j){
	if (i>0){
		trace(i-X[i][j],j-1);
		printf("%d ",X[i][j]);
	}
}
