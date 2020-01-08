//-----Tinh S=1!+2!+...+n!

#include <stdio.h>

void nhap(int &n);
int giaithua(int n);
int result(int n);
void xuat(int kq);

int main(){
	int n;
	nhap(n);
	int kq=result(n);
	xuat(kq);
	return 0;
}

void nhap(int &n){
	scanf("%d", &n);
}

void xuat(int kq){
	printf("%d", kq);
}

int giaithua(int n){
	int gt=1;
	for (int i=1; i<=n; i++)
		gt*=i;
	return gt;
}

int result(int n){
	int kq;
	for (int i=1; i<=n; i++)
		kq+=giaithua(i);
	return kq;
}
