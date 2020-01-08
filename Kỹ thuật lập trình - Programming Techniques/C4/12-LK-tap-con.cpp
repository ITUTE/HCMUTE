#include <stdio.h>
#define SIZE 128

void xuat(int A[], int n);
void SinhTapCon(int n);

int main()
{
	int n;	scanf("%d",&n);
	SinhTapCon(n);
	return 0;
}

void SinhTapCon(int n)
{
	int A[SIZE]={0};
	xuat(A,0);
	int k=1;
	while (1)
	{
		xuat(A,k);
		if (A[k-1]<n)
		{
			A[k]=A[k-1]+1;
			k++;
		}
		else
		{
			k--;
			if (k==0)	return;
			A[k-1]++;
		}
	}
}

void xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
}
