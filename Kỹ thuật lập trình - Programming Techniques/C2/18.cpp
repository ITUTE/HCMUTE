#include <stdio.h>
#include <string.h>
#define SIZE 1024

int count(char S[]);

int main(){
	char S[SIZE];	gets(S);
	int kq=count(S);
	printf("%d",kq);
	return 0;
}

int count(char S[]){
	int d=0, i=0, n=strlen(S);
	while (i<n)	{
		int j=i+1;
		while (S[j]==S[i]) j++;
		if (j-i>d){
			d=j-i;
			i=j;
		}else i++;
	}
	return d+1;
}
