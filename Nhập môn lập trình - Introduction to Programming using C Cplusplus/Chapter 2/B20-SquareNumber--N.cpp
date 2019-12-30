//-----List Square Number-----

#include <stdio.h>
#include <math.h>

void nhap(long int &n);
char SqNum(int n);
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

char SqNum(int n)
{
	int sqrtN=sqrt(n);
	if (n==sqrtN*sqrtN) return 1;
	else return 0;
}

void list(int n)
{
	for (int i=0; i<=n; i++)
		if (SqNum(i)) printf("%d ", i);
}
