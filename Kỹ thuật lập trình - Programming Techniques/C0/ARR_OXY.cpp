#include <stdio.h>
#include <math.h>
#define SIZE 1000

struct OXY
{
	float x;
	float y;
};

void nhapOXY(OXY &a);
void nhap(OXY A[], int &n);
int x_duong(OXY A[], int n);
void x_increase(OXY A[], int n);
void swapOXY(OXY &a, OXY &b);
int diem_phanBiet(OXY A[], int n);
void xuat(OXY A[], int n);
int khacNhau(OXY a, OXY b);
float k_cach(OXY a);
int pos_ganNhat(OXY A[], int n);

int main()
{
	OXY A[SIZE];
	int n;
	nhap(A,n);
	xuat(A,n);
	return 0;
}

void nhapOXY(OXY &a)
{
	float tmp;
	scanf("%f",&tmp);
	a.x=tmp;
	scanf("%f",&tmp);
	a.y=tmp;
}

void nhap(OXY A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		nhapOXY(A[i]);
}

int x_duong(OXY A[], int n)
{
	int count=0;
	for (int i=0;i<n;i++)
		if (A[i].x>0)
			count++;
	return count;
}

int diem_phanBiet(OXY A[], int n)
{
	x_increase(A,n);
	int count=0;
	int i=0;
	while (i<n)
	{
		count++;
		int j=i;
		while (khacNhau(A[i],A[j])) j++;
		i=j;
	}
	return count;	
}

int khacNhau(OXY a, OXY b)
{
	if (a.x==b.x&&a.y==b.y)
		return 1;
	return 0;
}
void x_increase(OXY A[], int n)
{
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (A[i].x>A[j].x)
				swapOXY(A[i],A[j]);
}

void swapOXY(OXY &a, OXY &b)
{
	OXY tmp=a;
	a=b;
	b=tmp;
}

void xuat(OXY A[], int n)
{
	x_increase(A,n);
	for (int i=0;i<n;i++)
		printf("%.2f %.2f \t",A[i].x,A[i].y);
	printf("\n\n So diem phan biet: %d",diem_phanBiet(A,n));
	printf("\n So diem co x>0: %d",x_duong(A,n));
	printf("\n Diem co x_max: %.2f %.2f",A[n-1].x,A[n-1].y);
	printf("\n Diem co x_min: %.2f %.2f",A[0].x,A[0].y);
	int pos=pos_ganNhat(A,n);
	printf("\n Diem gan O nhat: %.2f %.2f",A[pos].x,A[pos].y);
}

float k_cach(OXY a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}

int pos_ganNhat(OXY A[], int n)
{
	float d=k_cach(A[0]);
	int pos=0;
	for (int i=0;i<n;i++)
		if (d>k_cach(A[i]))
		{
			pos=i;
			d=k_cach(A[i]);
		}
	return pos;
}
