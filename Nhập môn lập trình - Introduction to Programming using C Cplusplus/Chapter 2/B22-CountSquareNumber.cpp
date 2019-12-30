//-----So luong Square Number-----

#include <stdio.h>
#include <math.h>

void nhap(long int &n);
char SqNum(int n);
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

char SqNum(int n)
{
	int sqrtN=sqrt(n);
	if (n==sqrtN*sqrtN) return 1;
	else return 0;
}

int count(int n)
{
	int sum=0;
	for (int i=0; i<=n; i++)
		if (SqNum(i)) sum+=1;
	return sum;
}

void xuat(int kq)
{
	printf("%d", kq);
}
