//-----So doi xung-----

#include <stdio.h>

void nhap(int &n);
int daonguoc(int n);
bool kiemtra(int n, int kq);
void xuat(int kq);

int main(){
	int n;
	nhap(n);
	int kq=daonguoc(n);
	bool kt=kiemtra(n,kq);
	xuat(kt);
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

bool kiemtra(int n, int kq){
	if (n==kq)
		return 1;
	else return 0;
}
void xuat(int kt){
	if (kt)
		printf("So doi xung.");
	else printf("Khong phai so doi xung.");
}
