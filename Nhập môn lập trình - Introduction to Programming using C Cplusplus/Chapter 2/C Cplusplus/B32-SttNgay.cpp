#include <stdio.h>

void nhap(int& d, int& m, int& y);
int solve(int d, int m, int y);
void xuat(int kq);
int namNhuan(int y);
int kiemtra(int d, int m, int y);
int SoNgayTrongThang(int m, int y);

int main()
{
	int d,m,y;
	nhap(d,m,y);
	int result=solve(d,m,y);
	xuat(result);
	return 0;
}

void nhap(int& d, int& m, int& y)
{
	scanf("%d%d%d",&d,&m,&y);
}

int namNhuan(int y)
{
	if (y%400==0||(y%4==0&&y%100!=0))
		return 1;
	else return 0;
}

int SoNgayTrongThang(int m, int y)
{
	switch (m)
	{
		case 4: case 6: case 9: case 11: 
			return 30; break;
		case 2:
			if (namNhuan(y)) return 29;
			else			return 28;
			break;
		default: return 31;
	}
}

int kiemtra(int d, int m, int y)
{
	if (d<1||d>31||m<1||m>12||y<1)
		return 0;
	else
	{
		int maxD=SoNgayTrongThang(m,y);
		if (d>maxD)	return 0;
		else 		return 1;
	}
}

int solve(int d, int m, int y)
{
	if (kiemtra(d,m,y))
	{
		int SoNgay=d;
		for (int i=m-1;i>0;i--)
			SoNgay+=SoNgayTrongThang(i,y);
		return SoNgay;
	}
	else return -1;
}

void xuat(int kq)
{
	printf("%d",kq);
}
