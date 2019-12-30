//----Doi ki tu: CHAR<=>char----

#include <stdio.h>

void nhap(char &ch);
char func(char ch);
void xuat(char ch);

int main(){
	char ch;
	nhap(ch);
	char kq=func(ch);
	xuat(kq);
	return 0;
}

void nhap(char &ch){
	scanf("%c", &ch);
}

char func(char ch){
	if ( (ch >= 'A') && (ch <= 'Z'))
		return ch+32;
	else 
		return ch-32;
}
void xuat(char ch){
	printf("%c", ch);
}
