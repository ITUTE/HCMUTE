//-----Fibonacci(n)-----

#include <stdio.h>

void nhap(int &n);
long int fibo_n(int n);
void xuat(long int kq);

int main()
{
	int n;
	nhap(n);
	long int kq=fibo_n(n);
	xuat(kq);
	return 0;
}

void nhap(int &n)
{
	scanf("%d", &n);
}

//Tim so Fibonaci thu n
long int fibo_n(int n)
{
	int fibo_2=0,fibo_1=1,fibo=1;		//Khoi tao gia tri khoi dau cua day Fibonaci
	if (n<=2) return fibo;
	else
	{
		int i=3;
		while (i<=n)
		{
			fibo_2=fibo_1;
			fibo_1=fibo;
			fibo=fibo_2+fibo_1;
			i++;
		}
		return fibo;
	}
}

void xuat(long int kq)
{
	printf("%d", kq);
}
