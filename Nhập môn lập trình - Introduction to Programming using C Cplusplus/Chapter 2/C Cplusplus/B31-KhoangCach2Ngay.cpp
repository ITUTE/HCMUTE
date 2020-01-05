//-----Khoang cach giua d1/m1/y1 và d2/m2/y2

#include <stdio.h>

void nhap(int &d1, int &m1, int &y1,int &d2, int &m2, int &y2);
int count(int d1, int m1, int y1, int d2, int m2, int y2);
int SoNgayTrongThang(int m, int y);
int namNhuan(int y);
void xuat(int kq);
int ConLai(int d, int m, int y);
int stt(int d, int m, int y);

int main()
{
	int d1,m1,y1,d2,m2,y2;
	nhap(d1,m1,y1,d2,m2,y2);
	int kq=count(d1,m1,y1,d2,m2,y2);
	xuat(kq);
	return 0;
}

void nhap(int &d1, int &m1, int &y1,int &d2, int &m2, int &y2)
{
	scanf("%d%d%d%d%d%d", &d1,&m1,&y1, &d2,&m2,&y2);
}

int namNhuan(int y)
{
	if (y%400==0||(y%4==0&&y%100!=0))
		return 1;
	else return 0;
}

void xuat(int kq)
{
	printf("%d", kq);
}

int SoNgayTrongThang(int m, int y)
{
	switch (m)
	{
		case 4: case 6: case 9: case 11:
			return 30; break;
		case 2:
			if (namNhuan(y))	return 29;
			else				return 28;
			break;
		default: return 31;
	}
}

//So ngay tu 1/1/yyyy den dd/mm/yyyy
int stt(int d, int m, int y)
{
	int SoNgay=d;
	for (int i=m-1;i>0;i--)
		SoNgay+=SoNgayTrongThang(i,y);
	return SoNgay;
}

//So ngay tu dd/mm/yyyy den 31/12/yyyy
int ConLai(int d, int m, int y)
{
	int SoNgay=SoNgayTrongThang(m,y)-d;
	for (int i=m+1;i<=12;i++)
		SoNgay+=SoNgayTrongThang(i,y);
	return SoNgay;
}

int count(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int sign,SoNgay;
	if (y1==y2)
	{
		SoNgay=stt(d1,m1,y1)-stt(d2,m2,y2);
		if (SoNgay<0)	return -SoNgay;
		else			return SoNgay;
	}
	else if (y1<y2)
		{
			SoNgay=stt(d2,m2,y2)+ConLai(d1,m1,y1);
			sign=1;
		}
		else
		{
			SoNgay=ConLai(d2,m2,y2)+stt(d1,m1,y1);
			sign=-1;
		}
		
	//Tru ra so ngay StartYear
	if (namNhuan(y1)) SoNgay-=366;
	else			SoNgay-=365;
	while (y1!=y2)
	{
		if (namNhuan(y1))	SoNgay+=366;
		else				SoNgay+=365;
		y1=y1+sign;
	}
	return SoNgay;
}


/*
int count(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int SoNgay=0,StartYear=0,EndYear=0;
	if (y1<y2)
	{
		SoNgay=stt(d2,m2,y2)+ConLai(d1,m1,y1);
		StartYear=y1;
		EndYear=y2;
	}
	else if (y1>y2)
		{
			SoNgay=ConLai(d2,m2,y2)+stt(d1,m1,y1);
			StartYear=y2;
			EndYear=y1;
		}
		else
		{
			SoNgay=stt(d1,m1,y1)-stt(d2,m2,y2);
			if (SoNgay<0) SoNgay=-SoNgay;
		}
	for (int i=StartYear+1;i<EndYear;i++)
		if (namNhuan(i))	SoNgay+=366;
		else				SoNgay+=365;
	return SoNgay;
}
/*
#include <stdio.h>
void nhap(int &d1, int &m1, int &y1,int &d2, int &m2, int &y2);
int count(int d1, int m1, int y1, int d2, int m2, int y2);
void xuat(int kq);
int namNhuan(int y);
int soNamNhuan(int start, int end);
int stt(int d, int m, int y);

int main()
{
	int d1,m1,y1,d2,m2,y2;
	nhap(d1,m1,y1,d2,m2,y2);
	int kq=count(d1,m1,y1,d2,m2,y2);
	xuat(kq);
	return 0;
}

void nhap(int &d1, int &m1, int &y1,int &d2, int &m2, int &y2)
{
	scanf("%d%d%d%d%d%d", &d1,&m1,&y1, &d2,&m2,&y2);
}

void xuat(int kq)
{
	printf("%d", kq);
}

int namNhuan(int y)
{
	if (y%400==0||(y%4==0&&y%100!=0))
		return 1;
	else return 0;
}

int soNamNhuan(int start, int end)
{
	int sum=0;
	//So nam nhuan trong khoang (start;end)
	for (int i=start+1;i<end;i++)
		if (namNhuan(i)) sum+=1;
	return sum;
}

//dd/mm/yyyy la ngay thu may trong nam
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

int count(int d1, int m1, int y1, int d2, int m2, int y2)
{
	int start,end,distance,kq=0;
	if (y1>y2)
	{
		start=y2;
		end=y1;
		distance=y1-y2;
	}
	else 
	{
		start=y1;
		end=y2;
		distance=y2-y1;
	}
	kq=stt(d1,m1,y1)-stt(d2,m2,y2);
	if (kq<0) kq=-kq;
	if (distance==0)
		return kq;
	else
	{
		int nhuan=soNamNhuan(start,end);
		kq+=nhuan*366+(distance-nhuan)*365;
		return kq;
	}
}
*/
