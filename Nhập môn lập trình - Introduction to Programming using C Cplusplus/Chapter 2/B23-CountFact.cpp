//-----So luong uoc so nguyen to-----

#include <stdio.h>
#include <math.h>

void nhap(int &n);
char isPrime(int n);
int count(int n);
void xuat(int kq);

int main()
{
	int n;
	nhap(n);
	int kq=count(n);
	xuat(kq);
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

int count(int n)
{
	int sum=0;
	for (int i=1;i<=n;i++)
		if (isPrime(i)&&(n%i==0)) sum+=1;
	return sum;
}

void xuat(int kq)
{
	printf("%d", kq);
}
