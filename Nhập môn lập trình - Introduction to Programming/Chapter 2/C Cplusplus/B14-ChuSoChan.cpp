//-----N=n1n2...nN gom toan chu so chan?-----

#include <stdio.h>
#include <math.h>

void nhap(int &n);
bool kiemtra(int n);
void xuat(bool kq);

int main(){
	int n;
	nhap(n);
	bool kt=kiemtra(n);
	xuat(kt);
	return 0;
}

void nhap(int &n){
	scanf("%d", &n);
}

bool kiemtra(int n){
	int sum=0;
	int x;
	while (n>0){
		x=n%10;
		if (x%2!=0) sum+=1;
		n=n/10;
	}
	if (sum==0) return 1;
	else return 0;
}

void xuat(bool kq){
	if (kq)
		printf("OK");
	else printf("NO");
}
