#include <stdio.h>
#define SIZE 128

void nhapMang(double *&A, int &n);
double sum(double *A, int n);

int main()
{
	double *A;	int n;
	nhapMang(A,n);
	double kq=0;
	kq=sum(A,n-1);
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

double sum(double *A, int n)
{
	if (n<=0)
		return A[0];
	else return A[n]+sum(A,n-1);
}
