#include <stdio.h>
#include <string.h>
#define SIZE 100
int nCk(int n, int k);

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int kq=nCk(n,k);
	printf("%d",kq);
	return 0;
}

int nCk(int n, int k){
	if (n==k || k==0)
		return 1;
	else return nCk(n-1,k-1)+nCk(n-1,k);
}
/*
int nCk(int n, int k){
	if (k==0 || n==k)
		return 1;
	int C[SIZE]={1}, Pre[100]={1};
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++)
			C[j]=Pre[j-1]+Pre[j];
		memcpy(Pre,C,sizeof(C));
	}
	return C[k];
}
*/
/*
int nCk(int n, int k){
	if (k==0 || n==k)
		return 1;
	int C[SIZE][SIZE]={0};
	for (int i=0;i<=n;i++)
		for (int j=0;j<=i;j++)
			if (j==0)
				C[i][j]=1;
			else C[i][j]=C[i-1][j-1]+C[i-1][j];
	return C[n][k];
}
*/
