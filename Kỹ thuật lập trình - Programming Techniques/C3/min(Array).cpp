#include <stdio.h>
#define SIZE 128

void nhapMang(double *&A, int &n);
double min(double* A, int n);

int main()
{
	double *A;	int n;
	nhapMang(A,n);
	double kq=min(A,n);
	printf("%.15lf",kq);
	delete[] A;
	return 0;
}

void nhapMang(double *&A, int &n)
{
	scanf("%d",&n);
	A=new double[n];
	for (int i=0;i<n;i++)
		scanf("%lf",&A[i]);
}

double min(double* A, int n)
{
	double m;
	if (n<=1)
		return A[0];
	else
	{
		m=min(A,n-1);
		if (A[n-1]<m)	m=A[n-1];
	}
	return m;
}

