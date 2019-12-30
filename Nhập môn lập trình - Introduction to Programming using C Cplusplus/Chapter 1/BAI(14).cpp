//-----Min_2nd(a,b,c)-----

#include <stdio.h>

void nhap(int &a, int &b, int &c);
void sapxep(int &a, int &b);
int func(int a, int b, int c);
void xuat(int a);

int main(){
	int a,b,c;
	nhap(a,b,c);
	int min_2nd=func(a,b,c);
	xuat(min_2nd);
	return 0;
}

void nhap(int &a, int &b, int &c){
	scanf("%d%d%d", &a, &b, &c);
}

void sapxep(int &a, int &b){
	int t;
	if (a>b){
		t=a;
		a=b;
		b=t;
	}
}

int func(int a, int b, int c){
	sapxep(a,b);
	if (c<=a)
		return a;
	else if ((c>a)&&(c<=b))
			return c;
		else return b;
}
void xuat(int a){
	printf("%d", a);
}

