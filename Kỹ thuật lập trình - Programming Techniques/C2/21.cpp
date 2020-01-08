#include <stdio.h>

double solve(int n);

int main()
{
	int n;	scanf("%d",&n);
	double S=solve(n);
	printf("%.15lf",S);
	return 0;
}

double solve(int n)
{
	double s=1;
	for (int i=1;i<=n;i++)
		s*=1+1/(float)(i*i);
	return s;
}
