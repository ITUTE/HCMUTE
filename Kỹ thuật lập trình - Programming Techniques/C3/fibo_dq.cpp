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
	if (n==0||n==1)
		return n;
	else return fibo(n-1)+fibo(n-2);
}
