#include <stdio.h>

double sum(int n);

int main()
{
	int n;	scanf("%d",&n);
	double kq=0;
	kq=sum(n);
	printf("%.15lf",kq);
	return 0;
}

double sum(int n)
{
	double s=0, tmp=1;
	for (int i=1;i<=n;i++)
	{
		tmp*=i;
		s+=tmp;
	}
	return s;
}

