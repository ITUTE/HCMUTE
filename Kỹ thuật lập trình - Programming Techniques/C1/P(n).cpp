#include <stdio.h>
#define SIZE 128

void nhapMang(double *&A, int &n);
double solve(double* A, int n, double x);

int main()
{
	int n;
	double* A;
	nhapMang(A,n);
	double x;		scanf("%lf",&x);
	double kq=solve(A,n,x);
	printf("%.14lf",kq);
	delete[] A;
	return 0;
}

double solve(double* A, int n, double x)
{
	double S=A[n];
	for (int i=n-1;i>=0;i--)
		S=S*x+A[i];
	return S;
}

void nhapMang(double *&A, int &n)
{
	scanf("%d",&n);
	A=new double[n+1];		//Array gom n+1 phan tu
	for (int i=0;i<=n;i++)
		scanf("%lf",&A[i]);
}

