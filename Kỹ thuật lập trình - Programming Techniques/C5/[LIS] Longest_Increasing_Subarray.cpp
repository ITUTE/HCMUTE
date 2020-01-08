#include <stdio.h>
#include <limits.h>
#define SIZE 100

void nhap(int A[], int &n)
{
	scanf("%d",&n);
	A[0]=-INT_MAX;//	A[n+1]=INT_MAX;
	for (int i=1;i<=n;i++)
		scanf("%d",&A[i]);
}

void Len_Longest_Inc_Subarray(int A[], int n, int L[]){
	for (int i=n;i>=0;i--){
		L[i]=1;
		for (int j=i+1;j<=n+1;j++)
			if (A[j]>A[i] && L[i]<L[j]+1)
				L[i]=L[j]+1;
	}
}

void Trace(int A[], int n, int L[]){
	int i=0;
	while (L[i]>1){
		int j;
		for (j=i+1;j<=n;j++)
			if (L[j]==L[i]-1){
				printf("%d ",A[j]);
				break;
			}
		i=j;
	}
}

int main()
{
	int A[SIZE]={0}, L[SIZE]={0};
	int n;
	nhap(A,n);
	Len_Longest_Inc_Subarray(A,n,L);
	Trace(A,n,L);
	return 0;
}
