#include <stdio.h>

double sum(int n, double x);

int main()
{
	double x;	scanf("%lf",&x);
	int n;		scanf("%d",&n);
	double kq=0;
	kq=sum(n,x);
	printf("%.15lf",kq);
	return 0;
}

double sum(int n, double x)
{
	double s=1, tmp=1;
	for (int i=1;i<=n;i++)
	{
		tmp*=x/i;
		s+=tmp;
	}
	return s;
}

