#include <stdio.h>

void nhapMang(double *&A, int &n);
double Pn(double *A, int n, double x);

int main()
{
	int n;
	double *A;
	nhapMang(A,n);
	double x;	scanf("%lf",&x);
	double kq=Pn(A,n,x);
	printf("%.15lf",kq);
	return 0;
}

double Pn(double *A, int n, double x)
{
	double s=A[n];
	for (int i=n-1;i>=0;i--)
		s=s*x+A[i];
	return s;
}

void nhapMang(double *&A, int &n)
{
	scanf("%d",&n);
	A=new double[n+1];
	for (int i=0;i<=n;i++)
		scanf("%lf",&A[i]);
}
