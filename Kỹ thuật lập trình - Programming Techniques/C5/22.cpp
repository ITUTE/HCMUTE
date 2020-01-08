#include <stdio.h>
#define SIZE 200
int A[SIZE]={0}, B[SIZE]={0};
int F[SIZE][SIZE]={0};
int nA, nB;
void nhap(int A[], int &n);
void LCS();
void trace();
int max(int x, int y);

int main(){
	nhap(A,nA);
	nhap(B,nB);
	LCS();
	printf("%d\n",F[nA][nB]);
	trace();
	return 0;
}

void nhap(int A[], int &n){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&A[i]);
}
void LCS(){
	for (int i=1;i<=nA;i++)
		for (int j=1;j<=nB;j++)
			if (A[i]==B[j])
				F[i][j]=F[i-1][j-1]+1;
			else
				F[i][j]=max(F[i-1][j], F[i][j-1]);
}

int max(int x, int y){
	if (x>y)
		return x;
	return y;
}

void trace(){
	int T[SIZE]={0};
	int i=nA, j=nB;
	while (F[i][j]){
		if (A[i]==B[j]){
			T[F[i][j]]=A[i];
			i--;	j--;
		}
		else
			 if (F[i][j-1]==max(F[i][j-1], F[i-1][j]))
			 	j--;
			else i--;
	}
	for (i=1;i<=F[nA][nB];i++)
		printf("%d ",T[i]);
}
