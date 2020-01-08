#include <stdio.h>
#define max 32000

void solve(unsigned long int F[], int n);
void xuat(unsigned long int F[], int n);

int main()
{
	int n;
	unsigned long int F[max];
	scanf("%d",&n);
	solve(F,n);
	xuat(F,n);
	return 0;
}

void xuat(unsigned long int F[], int n)
{
	for (int i=1;i<=n;i++)
		printf("%d ", F[i]);
}

void solve(unsigned long int F[], int n)
{
	F[0]=0,F[1]=1;
	for (int i=2;i<=n;i++)
		F[i]=F[i-1]+F[i-2];
}
