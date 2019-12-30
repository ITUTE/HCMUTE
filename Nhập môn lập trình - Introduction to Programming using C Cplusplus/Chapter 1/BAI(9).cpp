//-----Kiem tra nam nhuan-----

#include <stdio.h>

void nhap(int &year);
bool kiemtra(int year);
void xuat(int kq);

int main(){
	int year;
	nhap(year);
	int kq=kiemtra(year);
	xuat(kq);
	return 0;
}

void nhap(int &year){
	scanf("%d", &year);
}

bool kiemtra(int year){
	return ((year % 400==0)||(((year % 4==0&&year % 100!=0))));
}

void xuat(int kq){
	if (kq)
		printf("Nam nhuan");
	else
		printf("Ko nhuan");
	
}
