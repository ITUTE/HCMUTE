
#include <stdio.h>

void nhap(int &a, int &b, int &n);
int sum(int a, int b, int n);
void xuat(int kq);

int main(){
	int a,b,n;
	nhap(a,b,n);
	int kq=sum(a,b,n);
	xuat(kq);
}

void nhap(int &a, int &b, int &n){
	scanf("%d%d%d", &a, &b, &n);
}

int sum(int a, int b, int n){
	int tong=0;
	for (int i=1; i<=n; i++)
		if ( (i%a==0)&&(i%b!=0) ) tong+=i;
	return tong;
}

void xuat(int kq){
	printf("%d", kq);
}
