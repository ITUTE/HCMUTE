#include <stdio.h>
#include <math.h>

void nhapMang(int *&A, int &n);
int GCD(int x, int y);
int UCLN(int *A, int n);

int main()
{
	int *A;	int n;
	nhapMang(A,n);
	int kq=UCLN(A,n);
	printf("%d",kq);
	delete[] A;
	return 0;
}

void nhapMang(int *&A, int &n)
{
	scanf("%d",&n);
	A=new int[n];
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

int UCLN(int *A, int n)
{
	if (n==0)
		return A[n];
	else
		return GCD(UCLN(A,n-1),A[n-1]);
}

int GCD(int x, int y)
{
	x=abs(x);	y=abs(y);
	while (x*y!=0)
		if (x>y)	x%=y;
		else y%=x;
	return x+y;
}
