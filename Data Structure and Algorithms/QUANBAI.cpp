#include <stdio.h>
#define SIZE 100

struct QUANBAI
{
	int Name;	/*A=1, J=11, Q=12, K=13*/
	int Type;	/*B=0, Ch=1, R=2, C=3*/
};
void Nhap(QUANBAI A[], int &n);
void Xuat(QUANBAI A[], int n);
void swap(QUANBAI &a, QUANBAI &b);
void Sort(QUANBAI A[], int n);
int main()
{
	QUANBAI A[SIZE];
	int n;
	Nhap(A,n);
	Sort(A,n);
	Xuat(A,n);
	return 0;
}

void Nhap(QUANBAI A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d%d",&A[i].Name, &A[i].Type);
}

void Xuat(QUANBAI A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%4d%4d\n",A[i].Name,A[i].Type);
}

void Sort(QUANBAI A[], int n)
{
	for (int i=0;i<n;i++)
		if (A[i].Name<3)
			A[i].Name+=13;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
		{
			if (A[i].Name>A[j].Name)
				swap(A[i],A[j]);
			else if (A[i].Name==A[j].Name)
				if (A[i].Type>A[j].Type)
					swap(A[i],A[j]);
		}
	for (int i=0;i<n;i++)
		if (A[i].Name>13)
			A[i].Name-=13;
}

void swap(QUANBAI &a, QUANBAI &b)
{
	QUANBAI tmp=a;
	a=b;
	b=tmp;
}
