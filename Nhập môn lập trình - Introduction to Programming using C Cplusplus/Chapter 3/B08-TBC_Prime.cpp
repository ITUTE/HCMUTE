#include <stdio.h>
#include <math.h>
#define max 32000

void nhap(int A[], int &n);
int isPrime(int x);
float TBCprime(int A[], int n);
void xuat(float kq);

int main()
{
	int n, A[max];
	nhap(A,n);
	float kq=TBCprime(A,n);
	xuat(kq);
	return 0;
}

void nhap(int A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &A[i]);
}

int isPrime(int x)
{
	if (x==2||x==3) return 1;
	else if (x<2||x%2==0||x%3==0) return 0;
		else
		{
			int end=(int) sqrt(x);
			for (int i=2;i<=end;i++)
				if (x%i==0) return 0;
			return 1;
		}
}

float TBCprime(int A[], int n)
{
	float sum=0,count=0;
	for (int i=0;i<n;i++)
		if (isPrime(A[i])) 
		{
			sum+=A[i];
			count+=1;
		}
	return sum/count;
}
void xuat(float kq)
{
	printf("%f ", kq);
}
