//-----Giai phuong trinh ax+b=0 -----

#include <stdio.h>

void nhap(float &a, float &b);
int solve(float a, float b);
void xuat(int kt);

int main(){
	float a,b,x;
	nhap(a,b);
	int kt=solve(a,b);
	xuat(kt);
	return 0;
}

void nhap(float &a, float &b){
	scanf("%f%f", &a, &b);
}

int solve(float a, float b){
	//VN
	if (a==0&&b!=0)
		return 0;
	//VSN
	else if (a==0&&b==0)
			return 2;
		else {
			// 1 nghiem
			return 1;
		}
}
void xuat(int kt){
	if (kt==0) printf("0");
	else if (kt==1) printf("1");
		else printf("2");
}
