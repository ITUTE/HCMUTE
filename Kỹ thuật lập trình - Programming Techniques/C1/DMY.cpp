#include <stdio.h>
struct DMY
{
	int day;
	int month;
	int year;
};

void nhapDMY(DMY &d);
int namNhuan(int year);
int check(DMY today);
int songay(DMY today);
DMY nextDay(DMY today);
void xuatDMY(DMY d);

int main()
{
	DMY today;
	nhapDMY(today);
	int kq=check(today);
	if (kq)
	{
		DMY tomorrow=nextDay(today);
		xuatDMY(tomorrow);
	}
	else	printf("%d",kq);
	return 0;
}

void xuatDMY(DMY d)
{
	printf("%d %d %d",d.day,d.month,d.year);
}

void nhapDMY(DMY &d)
{
	scanf("%d%d%d",&d.day,&d.month,&d.year);
}

int namNhuan(int year)
{
	if ((year%400==0)||(year%4==0 && year%100!=0))
		return 1;
	return 0;
}

int songay(DMY today)
{
	int tmp[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (today.month!=2)
		return tmp[today.month];
	else if (namNhuan(today.year))
		return 29;
	else return 28;
}
int check(DMY today)
{
	
	if (today.day<1 || today.month <1 || today.month>12)
		return 0;
	if (today.day>songay(today))
		return 0;
	return 1;
}

DMY nextDay(DMY today)
{
	DMY d=today;
	if (today.month==12 && today.day==31)
	{
		d.day=1;
		d.month=1;
		d.year++;	
	}
	else if (today.day+1>songay(today))
	{
		d.day=1;
		d.month++;
	}
	else d.day++;
	return d;
}
