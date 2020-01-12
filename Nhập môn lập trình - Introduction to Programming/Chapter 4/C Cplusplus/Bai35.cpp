//DN SupArray theo de bai: A[i]...A[i+x]
#include <stdio.h>
#define size 100

void nhapMang(float A[], int &n);
void xuatDoanMang(float A[], int start, int end);//xuat 1 doan trong mang
void listSupArray(float A[], int n);
int increase_Array(float A[], int start, int end);
float sumArray(float A[], int start, int end);

int main()
{
	float A[size];
	int n;
	nhapMang(A,n);
	listSupArray(A,n);
	return 0;
}

void nhapMang(float A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%f",&A[i]);
}

int increase_Array(float A[], int start, int end)
{
	for (int i=start;i<end;i++)
		if (A[i]>=A[i+1])
			return 0;
	return 1;
}

float sumArray(float A[], int start, int end)
{
	int sum=0;
	for (int i=start;i<=end;i++)
		sum+=A[i];
	return sum;
}

void listSupArray(float A[], int n)
{
	int i=0;
	float sum=0;
	while (i<n)
	{
		int j=i+1;
		while (j<n)
		{
			if (increase_Array(A,i,j))
				sum+=sumArray(A,i,j);
			j++;
		}
		i++;
	}
	printf("%f",sum);
}
