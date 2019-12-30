//-----Làm tròn-----

#include <stdio.h>
#include <math.h>

void nhap(float &a);
int round(float a);
void xuat(int a);

int main(){
	float a;
	nhap(a);
	int kq=round(a);
	xuat(kq);
	return 0;
}

void nhap(float &a){
	scanf("%f", &a);
}

int round(float a){	
	return roundf(a);
}

void xuat(int a){
	printf("%d", a);
}
