#include <stdio.h>
#define SIZE 20

void sinh_HoanVi(int n);
void xuat(int A[], int n);
void swap(int &x, int &y);

int main()
{
	int n;	scanf("%d",&n);
	sinh_HoanVi(n);
	return 0;
}

void sinh_HoanVi(int n)
{
	int A[SIZE];
	for (int i=0;i<n;i++)
		A[i]=i;
	while (1){
		xuat(A,n);
		int i=n-2;
		while (A[i]>A[i+1] && i>=0)	i--;
		if (i<0)
			return;
		int j=n-1;
		while (A[j]<A[i])	j--;
		swap(A[i],A[j]);
		int d=i+1, c=n-1;
		while (d<c)
			swap(A[d++],A[c--]);
	}
}

void swap(int &x, int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}

void xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
}
