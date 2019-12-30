#include <stdio.h>

void nhap(int &n);
float solve(int n);
void xuat(float kq);

int main()
{
	int n;
	nhap(n);
	float kq=solve(n);
	xuat(kq);
	return 0;
}

void nhap(int &n)
{
	scanf("%d", &n);
}

void xuat(float kq)
{
	printf("%f", kq);
}

float solve(int n)
{
	float sum=0, gt=1, result=0;
	for (int i=1;i<=n;i++)
	{
		sum+=i;
		gt*=i;
		result+=float(sum)/gt;
	}
	return result;
}
