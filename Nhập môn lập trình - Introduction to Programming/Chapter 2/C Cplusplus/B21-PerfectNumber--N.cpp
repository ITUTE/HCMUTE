//-----List Perfect Number -----

#include <stdio.h>
#include <math.h>

void nhap(long int &n);
char isPerfectNumber(int n);
void list(int n);

int main()
{
	long int n;
	nhap(n);
	list(n);
	return 0;
}

void nhap(long int &n)
{
	scanf("%d", &n);
}

char isPerfectNumber(int n)
{
	int sum=0;
	for (int i=1;i<n;i++)
		if (n%i==0) sum+=i;
	if (n==sum) return 1;
	else return 0;
}

void list(int n)
{
	for (int i=1;i<=n;i++)
		if (isPerfectNumber(i)) printf("%d ", i);
}
