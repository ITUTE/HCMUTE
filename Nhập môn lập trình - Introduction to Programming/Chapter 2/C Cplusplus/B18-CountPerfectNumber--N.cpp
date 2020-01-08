//-----Dem so luong Perfect Number -----

#include <stdio.h>
#include <math.h>

void nhap(long int &n);
char isPerfectNumber(int n);
int count(int n);
void xuat(int kq);

int main()
{
	long int n;
	nhap(n);
	int kq=count(n);
	xuat(kq);
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

int count(int n)
{
	int sum=0;
	for (int i=1;i<=n;i++)
		if (isPerfectNumber(i)) sum+=1;
	return sum;
}

void xuat(int kq)
{
	printf("%d", kq);
}
