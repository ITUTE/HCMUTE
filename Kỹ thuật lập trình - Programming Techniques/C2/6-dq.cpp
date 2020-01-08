#include <stdio.h>

double nhan(int n, double &kq);

int main()
{
	int n;	scanf("%d",&n);
	double s=0, kq=0;
	s=nhan(n,kq);
	printf("%.0lf",kq);
	return 0;
}

double nhan(int n, double &kq)
{
	double s;
	if (n==1)
	{
		kq=1;
		return 1;
	}else
	{
		s=n*nhan(n-1,kq);
		kq+=s;
	}
	return s;
}
