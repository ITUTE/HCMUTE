#include <stdio.h>

double fibo(int n);

int main()
{
	int n;	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		printf("%.0lf\t",fibo(i));
	return 0;
}

double fibo(int n)
{
	double a=1, b=0, kq=0;
	for (int i=1;i<=n;i++)
	{
		kq=kq+a;
		a=kq-a;
		b=kq-b;
	}
	return kq;
}
