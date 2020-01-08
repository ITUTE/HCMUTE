//-----So Hoan Hao-----

#include <stdio.h>

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
	int sum=0;
	for (int i=1; i<n; i++)
		if (n%i==0) sum+=i;
	if (sum==n)
		return 1;
	else return 0;
}

void xuat(bool kq){
	if (kq)
		printf("So hoan hao.");
	else printf("Khong phai so hoan hao.");
}
