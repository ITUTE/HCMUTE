#include <stdio.h>
#include <math.h>

struct NGAY
{
	int day;
	int month;
	int year;
};

void nhapNGAY(NGAY &dmy);
void xuatNGAY(NGAY dmy);
void xuat(NGAY dmy, int k);
int namNhuan(int year);
int soNgay_year(int year);
int soNgay_month(int month, int year);
int stt_thisYear(NGAY dmy);
double stt(NGAY dmy);
double khoangCach(NGAY dmy1, NGAY dmy2);
NGAY after(NGAY dmy, int k);
NGAY before(NGAY dmy, int k);

int main()
{
	NGAY dmy1, dmy2;
	nhapNGAY(dmy1);
	nhapNGAY(dmy2);
	int k;
	scanf("%d",&k);
	printf("\n");
	xuat(dmy1,k);
	printf("\n---------------------------------\n");
	xuat(dmy2,k);
	double k_cach=khoangCach(dmy1,dmy2);
	printf("\n Khoang cach 2 ngay: %.0lf",fabs(k_cach));
	if (k_cach>0)
		printf("\n dmy2 --> dmy1");
	else if (k_cach==0)
		printf("\n dmy1==dmy2");
	else printf("\n dmy1 --> dmy2");
}

void nhapNGAY(NGAY &dmy)
{
	scanf("%d",&dmy.day);
	scanf("%d",&dmy.month);
	scanf("%d",&dmy.year);
}

void xuatNGAY(NGAY dmy)
{
	printf("%d %d %d",dmy.day,dmy.month,dmy.year);
}

void xuat(NGAY dmy, int k)
{
	xuatNGAY(dmy);
	if (namNhuan(dmy.year))
		printf("\n Nam NHUAN");
	else printf("\n Khong nhuan");
	printf("\n STT trong nam: %d",stt_thisYear(dmy));
	printf("\n STT: %.0lf",stt(dmy));
	printf("\n");
	xuatNGAY(after(dmy,k));
	printf("\n");
	xuatNGAY(before(dmy,k));
}

int soNgay_year(int year)
{
	if (namNhuan(year))
		return 366;
	return 365;
}

int namNhuan(int year)
{
	if (year%400==0||(year%4==0&&year%100!=0))
		return 1;
	return 0;
}

int soNgay_month(int month, int year)
{
	int m[13]={31,31,28,31,30,31,30,31,31,30,31,30,31};
	if (namNhuan(year))
		if (month==2) return 29;
	return m[month];
}

int stt_thisYear(NGAY dmy)
{
	int count=0;
	for (int i=1;i<dmy.month;i++)
		count+=soNgay_month(i,dmy.year);
	return count+dmy.day;
}

double stt(NGAY dmy)
{
	double count=0;
	for (int i=1;i<dmy.year;i++)
		count+=soNgay_year(i);
	return count+stt_thisYear(dmy);
}

double khoangCach(NGAY dmy1, NGAY dmy2)
{
	return (stt(dmy1)-stt(dmy2));
}

NGAY after(NGAY dmy, int k)
{
	int tmp;
	tmp=soNgay_year(dmy.year)-stt_thisYear(dmy);
	if (k>tmp)
	{
		dmy.day=1;
		dmy.month=1;
		dmy.year++;
		k=k-tmp-1;
	}
	else if (k==tmp)
	{
		dmy.day=31;
		dmy.month=12;
		k=0;
	}
	while (k>(tmp=soNgay_year(dmy.year)))
	{
		k-=tmp;
		dmy.year++;
	}
	while (k>(tmp=soNgay_month(dmy.month,dmy.year)))
	{
		k-=tmp;
		dmy.month++;
	}
	if (k>0)
	{
		tmp-=dmy.day;
		if (k>tmp)
		{
			dmy.day=k-tmp;
			dmy.month++;
			if (dmy.month==13)
				dmy.month=1;
		}
		else
			dmy.day+=k;
	}
	return dmy;
}

NGAY before(NGAY dmy, int k)
{
	int tmp;
	tmp=stt_thisYear(dmy);
	if (k>tmp)
	{
		dmy.day=31;
		dmy.month=12;
		dmy.year--;
		k-=tmp;
	}
	else if (k==tmp)
	{
		dmy.day=1;
		dmy.month=1;
		k=0;
	}
	while (k>(tmp=soNgay_year(dmy.year-1)))
	{
		k-=tmp;
		dmy.year--;
	}
	while (k>(tmp=soNgay_month(dmy.month-1,dmy.year)))
	{
		k-=tmp;
		dmy.month--;
		if (dmy.month==0)
			dmy.month=12;
	}
	if (k>0)
	{
		if (k>=dmy.day)
		{
			dmy.month--;
			dmy.day=soNgay_month(dmy.month,dmy.year)-k+dmy.day;
		}
		else
			dmy.day-=k;
	}
	return dmy;
}
