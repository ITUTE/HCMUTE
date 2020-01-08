#include <stdio.h>
#include <math.h>

void xuat(int n);
void bin(int n, int k);

int main()
{
	int n;	scanf("%d",&n);
	xuat(n);
	return 0;
}

void xuat(int n)
{
	int value=pow(2,n);
	for (int i=0;i<value;i++)
		bin(n,i);	
}

void bin(int n, int k)
{
	for (int i=n-1;i>=0;i--)
		printf("%d",(k>>i) & 0x1);
	printf("\n");
}
