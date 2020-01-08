//-----Uoc so le lon nhat-----

#include <stdio.h>

void nhap(long int &n);
long int solve(long int n);
void xuat(long int kq);

int main()
{
	long int n;
	nhap(n);
	long int kq=solve(n);
	xuat(kq);
	return 0;
}

void nhap(long int &n)
{
	scanf("%d", &n);
}

long int solve(long int n)
{
	//Neu n la so LE, thi uoc so LE lon nhat, chinh la n
	if (n%2==1) return n;
	else
		for (int i=n-1; i>0;i--)
			if ((n%i==0)&&(i%2==1)) return i;
}

void xuat(long int kq)
{
	printf("%d", kq);
}
