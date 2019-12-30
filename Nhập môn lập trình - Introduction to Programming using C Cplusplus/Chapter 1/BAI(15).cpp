//-----Kiem tra tam giac-----

#include <stdio.h>
#include <cstdlib>

void nhap(float &a, float &b, float &c);
int kiemtra(float a, float b, float c);
void xuat(int kt);

int main(){
	float a,b,c;
	nhap(a,b,c);
	int kt=kiemtra(a,b,c);
	xuat(kt);
	return 0;
}

void nhap(float &a, float &b, float &c){
	scanf("%f%f%f", &a, &b, &c);
}

bool tgdeu(float a, float b, float c){
	return ((a==b)&&(a==c));
}

bool tgvuong(float a, float b, float c){
	return ((a*a==b*b+c*c)||(b*b==a*a+c*c)||(c*c==a*a+b*b));
}

bool tgcan(float a, float b, float c){
	return ( ((a==b)&&(a!=c)) || ((b==a)&&(b!=c)) || ((c==a)&&(c!=b)) );
}

int kiemtra(float a, float b, float c){
	if ((a<=0) || (b<=0) && (c<=0))
		return 0;
	else if ( (a+b>c) && (abs(a-b)<c) && (a+c>b) && (abs(a-c)<b) && (b+c>a) && (abs(b-c)<a) )		//BDT tam giac
			if (tgdeu(a,b,c))
				return 1;
			else if (tgvuong(a,b,c)&&tgcan(a,b,c))
					return 2;
				else if (tgvuong(a,b,c))
						return 3;
					else if (tgcan(a,b,c))
								return 4;
						else	return 5;
		else	return 0;
}

void xuat(int kt){
	switch (kt)
	{
		case 0:	printf("Khong phai tam giac.");	break;
		case 1:	printf("Tam giac deu.");		break;
		case 2:	printf("Tam giac vuong can.");	break;
		case 3:	printf("Tam giac vuong.");		break;
		case 4:	printf("Tam giac can.");		break;
		case 5:	printf("Tam giac thuong.");
	}
}
