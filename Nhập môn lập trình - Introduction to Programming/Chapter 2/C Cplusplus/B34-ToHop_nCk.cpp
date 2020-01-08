#include <stdio.h>
void nhap(int &n, int &k);
double giaithua(int n);
double solve(int n, int k);
void xuat(double kq);

int main()
{
	int n,k;
	nhap(n,k);
	double kq=solve(n,k);
	xuat(kq);
	return 0;
}

void nhap(int &n, int &k)
{
	scanf("%d%d", &n, &k);
}

double giaithua(int n)
{
	if (n==1) return 1;
	else return n*giaithua(n-1);
}

double solve(int n, int k)
{
	//return giaithua(n)/(giaithua(k)*giaithua(n-k));
	double t=1;
	double m;
	int start,end;
	if (n==k) return 1;
	else 
		if (k==1) return n;
		else
		{
			//Rut gon thuat toan dua tren ly thuyet Toan hoc
			if (k>n-k)
			{
				start=n;
				end=k+1;
				m=giaithua(n-k);
			}
			else
			{
				start=n;
				end=n-k+1;
				m=giaithua(k);
			}
			//Neu dung i-- se sai thuat toan
			for (int i=start;i>=end;--i)
					t*=i;
			return t/m;
		}
}
void xuat(double kq)
{
	printf("%.0f",kq);
}
