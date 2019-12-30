#include <stdio.h>
#include <math.h>
#define max 32000

void nhap(int A[], int &n);
int isPrime(int x);
int first(int A[], int n);
int find(int A[], int n);
void xuat(int A[], int pos);

int main()
{
	int n, A[max];
	nhap(A,n);
	int pos=find(A,n);
	printf("%d",pos);
	//xuat(A,pos);
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

int first(int A[], int n)
{
	for (int i=0;i<n;i++)
		if (isPrime(A[i])) return i;
	//ko thay
	return -1;
}

int find(int A[], int n)
{
	int f=0;
//	int f=first(A,n);
//	if (f==n-1||f==-1) return -1;
//	else
	{
		for (int i=f+1;i<n;i++)
			if ((isPrime(A[i])&&A[i]>A[f])||(f=-1)) f=i;
		return f;
	}
}
void xuat(int A[], int pos)
{
	if (pos==-1) printf("%d",0);
	else
		printf("%d ", A[pos]);
}
