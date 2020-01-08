#include <stdio.h>

double sum(int n, double &kq);		//return sum(n)=1+2+...+n

int main()
{
	int n;	scanf("%d",&n);
	double kq=0,s=0;
	s=sum(n,kq);
	printf("%.15lf",kq);
	return 0;
}

double sum(int n, double &kq)
{
	double s;
	if (n==1)
	{
		kq=1;
		return 1;
	}
	else
	{
		s=n+sum(n-1,kq);
		kq+=1/s;
	}
	return s;
}
