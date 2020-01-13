#include <stdio.h>
#include <math.h>
#define max 32000

void nhap(int A[], int &n);
int isPrime(int x);
int find(int A[], int n);
void xuat(int kq);

int main()
{
	int n, A[max];
	nhap(A,n);
	int kq=find(A,n);
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
	if (x<2||x%2==0||x%3==0) return 0;
	int end=(int) sqrt(x);
	for (int i=2;i<=end;i++)
		if (x%i==0) return 0;
	return 1;
}

int find(int A[], int n)
{
	int maxPrime = 0;
	for (int i=0;i<n;i++)
		if (isPrime(A[i]) && A[i]>maxPrime)
			maxPrime=A[i];
	return maxPrime; 
}
void xuat(int kq)
{
	print("%d",kq);
}
