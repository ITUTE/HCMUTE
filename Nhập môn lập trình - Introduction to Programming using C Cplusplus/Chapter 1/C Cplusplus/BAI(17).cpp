//https://github.com/Titytus/HCMUTE
//----- Sau 1s -----

#include <stdio.h>

void nhap(int &h, int &m, int &s);
bool hople(int h, int m, int s);
int func(int &h, int &m, int &s);
void xuat(int h, int m, int s);

int main()
{
	int h,m,s;
	nhap(h,m,s);
	if (!hople(h,m,s))
		printf("Du lieu ko hop le.");	
	else
	{
		func(h,m,s);
		xuat(h,m,s);
	}
	return 0;
}

void nhap(int &h, int &m, int &s)
{
	scanf("%d%d%d", &h, &m, &s);
}

void xuat(int h, int m, int s)
{
	printf("Sau 1s la %2d:%2d:%2d", h, m, s);
}

bool hople(int h, int m, int s)
{
	return !( (h<0) || (h>23) || (m<0) || (m>59) || (s<0) || (s>59));
}

int func(int &h, int &m, int &s)
{
	if (s == 59){
		s=0;
		m+=1;
		if (m == 60)
		{
			m=0;
			h+=1;
			if (h == 24) h=0;
		}
	}
	else s++;
}
