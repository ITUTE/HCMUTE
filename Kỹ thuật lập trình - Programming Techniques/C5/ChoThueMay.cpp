#include <stdio.h>
#define SIZE 100
#define oo	100000
void nhap(int A[], int B[], int C[], int &n);
void swap(int &x, int &y);
void sapxep(int A[], int B[], int C[], int n);
int QHD(int A[], int B[], int n, int P[]);
void TruyVet(int A[], int B[], int n, int P[]);

int main(){
	int A[SIZE]={0}, B[SIZE]={0}, C[SIZE]={0}, n;
	int P[SIZE]={0};
	nhap(A,B,C,n);
	sapxep(A,B,C,n);
	int kq=QHD(A,B,n,P);
	printf("%d\n",kq);
	TruyVet(A,B,n,P);
	return 0;
}

void nhap(int A[], int B[], int C[], int &n){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&A[i],&B[i],&C[i]);
}

void sapxep(int A[], int B[], int C[], int n){
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (B[i]>B[j]){
				swap(A[i],A[j]);
				swap(B[i],B[j]);
				swap(C[i],C[j]);
			}
}

void swap(int &x, int &y){
	int t=x;
	x=y;
	y=t;
}

int QHD(int A[], int B[], int C[], int n, int P[]){
	//L[i] la so cuoc hop nhieu nhat co the to chuc trong so cac cuoc hop [i,n)
	B[0]=-oo;	A[n+1]=oo;
	int L[SIZE]={0};
	L[n+1]=1;
	for (int i=n;i>=0;i--){
		int j,jmax=i;
		for (j=i+1;j<=n+1;j++)
			if (A[j]>=B[i] && L[j]>L[jmax])	jmax=j;
		L[i]=L[jmax]+1;
		P[i]=jmax;
	}
	for (int i=0;i<=n+1;i++)
		printf("%d ",L[i]);
	printf("\n");
	return L[1]-1;
}

void TruyVet(int A[], int B[], int n, int P[]){
	int i=P[0];
	while (i<=n){
		printf("%d %d \n",A[i],B[i]);
		i=P[i];
	}
}
