//-----List prime(i)<=n-----

#include <stdio.h>
#include <math.h>

void nhap(int &n);
char isPrime(int x);
void list(int n);

int main()
{
	int n;
	nhap(n);
	list(n);
	return 0;
}

void nhap(int &n)
{
	scanf("%d", &n);
}

char isPrime(int n)
{
	if ((n==2)||(n==3)) return 1;
	if ((n==1)||(n<0)) return 0;
	for (int i=2; i<=int(sqrt(n)); i++)
		if (n%i==0) return 0;
	return 1;
}

void list(int n)
{
	for (int i=1;i<=n;i++)
		if (isPrime(i)) printf("%d ", i);
}
