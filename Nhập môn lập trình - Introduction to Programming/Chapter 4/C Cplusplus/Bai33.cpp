#include <stdio.h>
#define size 100

void nhapMang(int A[], int &n);
void xuatDoanMang(int A[], int start, int end);//xuat 1 doan trong mang
void listSupArray(int A[], int n);

int main()
{
	int A[size],n;
	nhapMang(A,n);
	listSupArray(A,n);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void listSupArray(int A[], int n)
{
	int i=0;
	while (i<n)			//xac dinh start
	{
		int j=i+2;
		while (j<n)		//xac dinh end
		{
			xuatDoanMang(A,i,j);
			printf("\n");
			j++;
		}
		i++;
	}
}

void xuatDoanMang(int A[], int start, int end)
{
	for (int i=start;i<=end;i++)
		printf("%d ",A[i]);
}
