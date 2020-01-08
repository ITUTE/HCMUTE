//-----Tinh S=1 + 1/2 + ... + 1/n-----

#include <stdio.h>

void nhap(int &n);
float sum(int n);
void xuat(float kq);

int main(){
	int n;
	nhap(n);
	float kq=sum(n);
	xuat(kq);
	return 0;
}

void nhap(int &n){
	scanf("%d", &n);
}

void xuat(float kq){
	printf("%.5f", kq);
}

float sum(int n){
	float tong;
	for (int i=1; i<=n; i++)
		tong+=1/float(i);
	return tong;
}
