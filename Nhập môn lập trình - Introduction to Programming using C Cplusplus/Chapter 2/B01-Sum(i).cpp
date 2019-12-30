//-----Tinh tong S=1+2+...+n-----

#include <stdio.h>

void nhap(int &n);
int sum(int n);
void xuat(int kq);

int main(){
	int n;
	nhap(n);
	int kq=sum(n);
	xuat(kq);
	return 0;
}

void nhap(int &n){
	scanf("%d", &n);
}

void xuat(int kq){
	printf("%d", kq);
}

int sum(int n){
	int tong;
	for (int i=1; i<=n; i++)
		tong+=i;
	return tong;
}
