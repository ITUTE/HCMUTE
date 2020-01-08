#include <stdio.h>

double nCk(int n, int k);

int main()
{
	int n, k;	scanf("%d%d",&n,&k);
	double kq=nCk(n,k);
	printf("%.0f",kq);
	return 0;
}

double nCk(int n, int k)
{
	if (k==0||k==n)
		return 1;
	else return nCk(n-1,k)+nCk(n-1,k-1);
}
