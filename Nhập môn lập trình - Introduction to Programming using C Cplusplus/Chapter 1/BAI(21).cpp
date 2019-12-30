//https://github.com/Titytus/HCMUTE
//----- Giai phuong trinh ax^2 + bx +c =0 -----

#include <stdio.h>
#include <math.h>

void nhap(float &a, float &b, float &c);
int solve(float a, float b, float c, float &x1, float &x2);
void xuat(int kt, float x1, float x2);

int main()
{
	float a,b,c,x1,x2;
	nhap(a,b,c);
	int kt=solve(a,b,c,x1,x2);
	xuat(kt,x1,x2);
	return 0;
}

void nhap(float &a, float &b, float &c)
{
	scanf("%f%f%f", &a, &b, &c);
}

int solve(float a, float b, float c, float &x1, float &x2)
{
	float delta;
	if (a==0)
	{
		if (b==0)
		{
			if (c!=0)	return 0;	//Vo nghiem
			return 1;				//VSN
		}
		else 
		{
			x1= - float(c)/b;
			return 2;				//1 nghiem
		}
	}
	else 
	{
		delta=b*b-4*a*c;
		if (delta<0)
			return 0;				//Vo nghiem
		if (delta==0)
		{
			x1=-float(b)/(2*a);
			return 2;				//1 nghiem
		}
		x1=((-b-sqrt(delta))/(2*a));
		x2=((-b+sqrt(delta))/(2*a));
		return 3;					//2 nghiem
	}
}

void xuat(int kt, float x1, float x2)
{
	switch (kt){
		case 0:
			printf("Phuong trinh vo nghiem.");									break;
		case 1:
			printf("Phuong trinh VSN.");										break;
		case 2:
			printf("Phuong trinh co nghiem: x= %.2f\n", x1);					break;
		case 3:
			printf("Phuong trinh co nghiem: x1= %.2f;\t x2= %.2f\n", x1, x2);	break;
	}
}
