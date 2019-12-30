#include <stdio.h>

void nhap(long int &n);
int solve(long int &n, long int x);
void xuat(long int n);

int main()
{
	long int n;
	nhap(n);
	xuat(n);
	return 0;
}

void nhap(long int &n)
{
	scanf("%d",&n);
}

int solve(long int &n, long int x)
{
	int sum=0;
	if (n>=x)
	{
		sum+=n/x;
		n%=x;
	}
	return sum;
}

void xuat(long int n)
{
	printf("%d ", solve(n,100000));
	printf("%d ", solve(n,50000));
	printf("%d ", solve(n,20000));
	printf("%d", solve(n,10000));
}
