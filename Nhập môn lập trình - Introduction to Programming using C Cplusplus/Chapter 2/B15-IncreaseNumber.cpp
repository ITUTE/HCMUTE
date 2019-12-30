//-----Kiem tra cac chu so tang dan

#include <stdio.h>

void nhap(long int &n);
char increase(long int n);
char decrease(long int n);
void xuat(char inc, char dec);

int main()
{
	long int n;
	nhap(n);
	char inc=increase(n);
	char dec=decrease(n);
	xuat(inc,dec);
	return 0;
}

void nhap(long int &n)
{
	scanf("%d", &n);
}

char decrease(long int n)
{
	char result=1;
	char ans;
	char preAns=n%10;
	while (n>10)
	{
		n/=10;
		ans=n%10;
		if (ans<=preAns) result=0;	//
		preAns=ans;
	}
	return result;
}

char increase(long int n)
{	
	char result=1;
	char ans;
	char preAns=n%10;
	while (n>10)
	{
		n/=10;
		ans=n%10;
		if (ans>=preAns) result=0;	//
		preAns=ans;
	}
	return result;
}

void xuat(char inc, char dec)
{
	if (inc==1) printf("Tang dan");
	else
		if (dec==1) printf("Giam dan");
		else printf("Undetermined");
}
