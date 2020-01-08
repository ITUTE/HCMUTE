#include <stdio.h>
#define SIZE 20
void n_Combinations(int C[][SIZE], int n);
void xuat(int A[][SIZE], int n);

int main()
{
	int C[SIZE][SIZE]={0}, n;
	scanf("%d",&n);
	n_Combinations(C,n);
	xuat(C,n);
	return 0;
}

void n_Combinations(int C[][SIZE], int n){
	int i,j;
	for (i=0;i<=n;i++)
		C[i][0]=1;
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
}

void xuat(int A[][SIZE], int n){
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
			if (A[i][j])	printf("  %d  ",A[i][j]);
		printf("\n");
	}
}
