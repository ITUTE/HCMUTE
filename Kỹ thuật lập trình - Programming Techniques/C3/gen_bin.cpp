#include <stdio.h>
#define SIZE 20

void xuat(int A[], int n);
void generate(int n);

int main()
{
	int n;	scanf("%d",&n);
	generate(n);
	return 0;
}

void generate(int n)
{
	int A[SIZE]={0};
	while (1){
		xuat(A,n);	printf("\n");
		int i=n-1;
		while (A[i]==1 && i>=0){
			A[i]=0;
			i--;
		}
		if (i<0)
			return;
		A[i]=1;
	}
}

void xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}
