#include <stdio.h>

struct PHANSO
{
	int tuso;
	int mauso;	
};

void nhapPS(PHANSO &a);
void xuatPS(PHANSO a);
void xuat(PHANSO a);
int UCLN(int x, int y);
int BCNN(int x, int y);
int daRutGon(PHANSO a);
PHANSO rutGon(PHANSO a);
void quyDong(PHANSO &a, PHANSO &b);
PHANSO cong(PHANSO a, PHANSO b);
PHANSO tru(PHANSO a, PHANSO b);
PHANSO nhan(PHANSO a, PHANSO b);
PHANSO chia(PHANSO a, PHANSO b);
void chuanHoa(PHANSO &a);
int kiemTra(PHANSO a);
int soSanh(PHANSO a, PHANSO b);
void xuly(PHANSO a, PHANSO b);

int main()
{
	PHANSO a,b;
	nhapPS(a);
	nhapPS(b);
	xuat(a);
	xuat(b);
	xuly(a,b);
	return 0;
}

void nhapPS(PHANSO &a)
{
	scanf("%d",&a.tuso);
	scanf("%d",&a.mauso);
}

void xuatPS(PHANSO a)
{
	chuanHoa(a);
	printf("%d %d",a.tuso,a.mauso);
}

void xuat(PHANSO a)
{
	printf("\nPhan so da cho: %d %d",a.tuso,a.mauso);
	if (UCLN(a.tuso,a.mauso)==1)
		printf("\nPhan so da duoc rut gon.");
	else
	{
		printf("\nPhan so sau khi rut gon:");
		xuatPS(a);
	}
	if (kiemTra(a)==1)
		printf("\nPhan so duong (ps>=0)");
	else if (kiemTra(a)==-1)
		printf("\nPhan so am (ps<0)");
}

void xuly(PHANSO a, PHANSO b)
{
	printf("\nQuy dong:");
	quyDong(a,b);
	printf("%d %d; %d %d",a.tuso,a.mauso,b.tuso,b.mauso);
	if (soSanh(a,b)==1)
		printf("\nPS 1 lon hon PS 2");
	else if (soSanh(a,b)==0)
		printf("\nPS 1 bang PS 2");
	else printf("\nPS 1 be hon PS 2");
	printf("\nCong: ");		xuatPS(cong(a,b));
	printf("\nTru: ");		xuatPS(tru(a,b));
	printf("\nNhan: ");		xuatPS(nhan(a,b));
	printf("\nChia: ");		xuatPS(chia(a,b));
}
int UCLN(int x, int y)
{
	if (x*y==0)
		return 1;
	if (x<0) x=-x;
	if (y<0) y=-y;
	while (x*y!=0)
		if (x>y)
			x%=y;
		else
			y%=x;
	return x+y;
}

PHANSO rutGon(PHANSO a)
{
	int term=UCLN(a.tuso,a.mauso);
	if (term!=1)
	{
		a.tuso/=term;
		a.mauso/=term;
	}
	return a;
}

PHANSO cong(PHANSO a, PHANSO b)
{
	PHANSO t;
	t.tuso=a.tuso*b.mauso+a.mauso*b.tuso;
	t.mauso=a.mauso*b.mauso;
	return t;
}

PHANSO tru(PHANSO a, PHANSO b)
{
	b.tuso=-b.tuso;
	return cong(a,b);
}

PHANSO nhan(PHANSO a, PHANSO b)
{
	PHANSO t;
	t.tuso=a.tuso*b.tuso;
	t.mauso=a.mauso*b.mauso;
	return t;
}

PHANSO chia(PHANSO a, PHANSO b)
{
	PHANSO t;
	t.tuso=a.tuso*b.mauso;
	t.mauso=a.mauso*b.tuso;
	return (t);
}

void chuanHoa(PHANSO &a)
{
	a=rutGon(a);
	if (a.mauso<0)
	{
		a.tuso*=-1;
		a.mauso*=-1;
	}
}

int daRutGon(PHANSO a)
{
	int x=UCLN(a.tuso,a.mauso);
	if (x==1)
		return 1;
	return 0;
}

int BCNN(int x, int y)
{
	return x*(y/UCLN(x,y));
}

void quyDong(PHANSO &a, PHANSO &b)
{
	int bcnn=BCNN(a.mauso,b.mauso);
	a.tuso*=bcnn/a.mauso;
	b.tuso*=bcnn/b.mauso;
	a.mauso=bcnn;
	b.mauso=bcnn;
}

int kiemTra(PHANSO a)				//Kiem tra phan so am/duong
{
	int dau=a.tuso*a.mauso;
	if (dau<0)
		return -1; //am
	return 1;		//duong
}

int soSanh(PHANSO a, PHANSO b)
{
	quyDong(a,b);
	if (a.tuso>a.mauso)
		return 1;		//a>b
	else if (a.tuso==a.mauso)
		return 0;		//a==b
	return -1;			//a<b
}
