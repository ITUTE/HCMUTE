//-----Kiem tra bo 3 so tam giac-----

#include <stdio.h>
#include <math.h>

void nhap(float &a, float &b, float &c);
bool kiemtra(float a, float b, float c);
void xuat(bool a);

int main(){
	float a,b,c;
	nhap(a,b,c);
	bool kq=kiemtra(a,b,c);
	xuat(kq);
	return 0;
}

void nhap(float &a, float &b, float &c){
	scanf("%f%f%f", &a, &b, &c);
}

bool kiemtra(float a, float b, float c){
	return ((a+b>c)&&(abs(a-b)<c) && (a+c>b)&&(abs(a-c)<b) && (b+c>a)&&(abs(b-c)<a) && (a>0) && (b>0) &&(c>0));
}

void xuat(bool a){
	if (a)
		printf("Do la 1 tam giac.");
	else
		printf("Khong phai tam giac.");
}
