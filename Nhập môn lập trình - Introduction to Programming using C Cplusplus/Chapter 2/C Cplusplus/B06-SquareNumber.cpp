//-----Kiem tra so Chinh phuong-----

#include <stdio.h>
#include <math.h>

void nhap(int &n);
bool kt(int n);
void xuat(bool kq);

int main(){
	int n;
	nhap(n);
	bool kq=kt(n);
	xuat(kq);
	return 0;
}

void nhap(int &n){
	scanf("%d", &n);
}

bool kt(int n){
	int sqrtN=sqrt(n);
	if (sqrtN*sqrtN==n)
			return 1;
	else	return 0;
}

void xuat(bool kq){
	if (kq) printf("So chinh phuong.");
	else	printf("Khong phai so chinh phuong.");
}

