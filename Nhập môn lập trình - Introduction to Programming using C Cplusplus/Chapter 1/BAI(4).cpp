//https://github.com/Titytus/HCMUTE
//-----tim so lon hon (a,b)-----

#include <stdio.h>

void nhap(int &a, int &b);
int sosanh(int a, int b);
void xuat(int a);

int main()
{
	int a,b;
	nhap(a,b);
	int kq=sosanh(a,b);
	xuat(kq);
	return 0;
}

void nhap(int &a, int &b)
{
	scanf("%d%d", &a, &b);
}

int sosanh(int a, int b)
{
	if (a>=b)
		return a;
	return b;
}

void xuat(int a){
	printf("%d", a);
}
