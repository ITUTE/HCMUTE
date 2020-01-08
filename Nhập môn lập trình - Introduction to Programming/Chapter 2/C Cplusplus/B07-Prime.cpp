//-----kq So Nguyen To-----

#include <stdio.h>
#include <math.h>

void nhap(int &n);
int isPrime(int n);
void xuat(int kq);

int main(){
	int n;
	nhap(n);
	int kq=isPrime(n);
	xuat(kq);
	return 0;
}

void nhap(int &n){
	scanf("%d", &n);
}

int isPrime(int n){
	if (n==0||n==2||n==3)
		return 1;
	else 
		if (n==1||(n%2==0))
			return 0;
		else
		{
			for (int i=3;i<=int(sqrt(n));i+=2)
				if (n%i==0)
					return 0;
			return 1;
		}
}

void xuat(int kq){
	printf("%d",kq);
}
