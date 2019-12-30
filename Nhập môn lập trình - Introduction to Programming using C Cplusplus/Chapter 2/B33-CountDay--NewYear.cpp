#include <stdio.h>

void nhap(int& d, int& m, int& y);
void xuat(int kq);
int solve(int d, int m, int y);
int namNhuan(int y);
int SoNgayTrongThang(int m, int y);
int kiemtra(int d, int m, int y);

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

int solve(int d, int m, int y)
{
	if (kiemtra(d,m,y))
	{
		int SoNgay=SoNgayTrongThang(m,y)-d;
		for (int i=m+1;i<=12;i++)
			SoNgay+=SoNgayTrongThang(i,y);
		return SoNgay;
	}
	else return -1;
}

void xuat(int kq)
{
	printf("%d",kq);
}

/*
//My Code
#include <stdio.h>

void nhap(int& d, int& m, int& y);
int stt(int d, int m, int y);
int solve(int d, int m, int y);
void xuat(int kq);
int namNhuan(int y);

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

int stt(int d, int m, int y)
{
	int count=0;
	if (m==1) return d;
	else if (m==2) return 31+d;
		else
		{
			switch (m)
			{
				case 3: count=59+d;
				case 4: count=90+d;
				case 5: count=120+d;
				case 6: count=151+d;
				case 7: count=181+d;
				case 8: count=212+d;
				case 9: count=243+d;
				case 10: count=273+d;
				case 11: count=304+d;
				case 12: count=334+d;
			}
			if (namNhuan(y)) count+=1;
		}
	return count;
}

int solve(int d, int m, int y)
{
	//VD: 30/12/2003 den 1/1/2004 co 2 ngay
	if (namNhuan(y))
		return (366-stt(d,m,y)+1);
	else
		return (365-stt(d,m,y)+1);
}
void xuat(int kq)
{
	printf("%d",kq);
}
*/
