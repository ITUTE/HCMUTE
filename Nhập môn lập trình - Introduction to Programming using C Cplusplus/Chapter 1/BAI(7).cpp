//-----Làm tròn xuô'ng-----

#include <stdio.h>
#include <math.h>

void nhap(float &a);
int round(float a);
void xuat(int kq);

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
	return floor(a);
}

void xuat(int kq){
	printf("%d", kq);
}
