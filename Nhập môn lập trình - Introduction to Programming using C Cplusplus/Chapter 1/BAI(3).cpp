//-----Chu vi HCN-----

#include <stdio.h>

void nhap(float &a, float &b);
float tinh(float a, float b);
void xuat(float a);

int main(){
	float a,b;
	nhap(a,b);
	float chuvi=tinh(a,b);
	xuat(chuvi);
	return 0;
}

void nhap(float &a, float &b){
	scanf("%f%f", &a, &b);
}

float tinh(float a, float b){
	return 2*(a+b);
}

void xuat(float a){
	printf("%.2f", a);
}
