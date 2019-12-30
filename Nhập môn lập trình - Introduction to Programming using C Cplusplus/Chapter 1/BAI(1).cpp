//-----Tra ve gia tri tuyet doi cua so nguyen n, |n|-----

#include <stdio.h>
#include <math.h> 

void nhap(int &n);
int tinh(int n);
void xuat(int kq);

int main(){
	int n;
	nhap(n);
	int giatri=tinh(n);
	xuat(giatri);
	return 0;
}

void nhap(int &n){
	scanf("%d", &n);
}

int tinh(int n){
	return abs(n);
}

void xuat(int kq){
	printf("%d", kq);
}
