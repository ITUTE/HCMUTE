//-----Chu so lon nhat trong N=n1n2..nN-----

#include <stdio.h>

void nhap(int &n);
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

int result(int n){
	int max=(n%10);
	while (n>0){
		n=n/10;
		if (max<(n%10))
			max=n%10;
	}
	return max;
}

void xuat(int kq){
	printf("%d", kq);
}
