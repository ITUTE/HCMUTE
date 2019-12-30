//-----Dao nguoc so-----

#include <stdio.h>

void nhap(int &n);
int daonguoc(int n);
void xuat(int kq);

int main(){
	int n;
	nhap(n);
	int kq=daonguoc(n);
	xuat(kq);
	return 0;
}

void nhap(int &n){
	scanf("%d", &n);
}

int daonguoc(int n){
	int x=0;
	while (n>0){
		x=(10*x)+(n%10);
		n=n/10;
	}
	return x;
}

void xuat(int kq){
	printf("%d", kq);
}
