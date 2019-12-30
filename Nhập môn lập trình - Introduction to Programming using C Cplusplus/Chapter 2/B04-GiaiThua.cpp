//-----Tinh giai thua-----

#include <stdio.h>

void nhap(int &n);
int giaithua(int n);
void xuat(int kq);

int main(){
	int n;
	nhap(n);
	int kq=giaithua(n);
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
	int result=1;
	for (int i=1; i<=n; i++)
		result*=i;
	return result;
}
