#include <stdio.h>

void nhap(int &n, float &x);
float solve(int n, float x);
void xuat(float kq);

int main()
{
	int n;
	float x;
	nhap(n,x);
	float kq=solve(n,x);
	xuat(kq);
	return 0;
}

void nhap(int &n, float &x)
{
	scanf("%d%f", &n, &x);
}

float solve(int n, float x)
{
	if (n==0) return 1;
	else {
		float s=1, pow=1, gt=1;
		for (int i=1;i<=n;i++)
		{
			pow*=x;
			gt*=i;
			s+=float(pow)/gt;
		}
		return s;
	}
}

void xuat(float kq)
{
	printf("%f", kq);
}
