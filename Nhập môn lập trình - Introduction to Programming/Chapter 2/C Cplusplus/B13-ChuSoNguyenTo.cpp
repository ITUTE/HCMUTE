//-----Dem xem N=n1n2...nN co bao nhieu chu so la So Nguyen To-----

#include <stdio.h>
#include <math.h>

void nhap(int &n);
bool isPrime(int n);
int count(int n);
void xuat(int kq);

int main(){
	int n;
	nhap(n);
	int kq=count(n);
	xuat(kq);
	return 0;
}

void nhap(int &n){
	scanf("%d", &n);
}

int count(int n){
	int sum=0;
	if (n<0) n=-n;
	while (n>0){
		if (isPrime(n%10))
			sum+=1;
		n=n/10;
	}
	return sum;
}

bool isPrime(int n){
	if (n==0||n==2||n==3) return 1;
	else if (n==1||(n%2==0)) return 0;
		else{
			for (int i=2;i<=int(sqrt(n));i++)
				if (n%i==0) {return 0;break;}
			return 1;
		}
}

/*
bool isPrime(int n){
	switch (n){
		case 0:case 2:case 3:case 5:case 7: return 1;break;
		case 1:case 4:case 6:case 8:case 9: return 0;
	}
}
*/


void xuat(int kq){
	printf("%d", kq);
}
