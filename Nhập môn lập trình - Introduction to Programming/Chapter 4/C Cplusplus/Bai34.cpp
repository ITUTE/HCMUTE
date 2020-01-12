//DN SupArray theo de bai: A[i]...A[i+x]
#include <stdio.h>
#define size 100

void nhapMang(int A[], int &n);
void xuatDoanMang(int A[], int start, int end);//xuat 1 doan trong mang
void listSupArray(int A[], int n);
int increase_Array(int A[], int start, int end);

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

int increase_Array(int A[], int start, int end)
{
	for (int i=start;i<end;i++)
		if (A[i]>=A[i+1])
			return 0;
	return 1;
}

void listSupArray(int A[], int n)
{
	int i=0;
	while (i<n)
	{
		int j=i+1;
		while (j<n)
		{
			if (increase_Array(A,i,j))
			{
				xuatDoanMang(A,i,j);
				printf("\n");
			}
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
