#include <stdio.h>
#include <string.h>
#define size 30

void nhap(char S[]);
void reverseString(char S[]);

int main()
{
	char S[size];
	nhap(S);
	//strrev(S);
	reverseString(S);
	printf("%s",S);
	return 0;
}

void nhap(char S[])
{
	gets(S);
}

void reverseString(char S[])
{
	char reS[size];
	int x=strlen(S);
	for (int i=0;i<x;i++)
		reS[x-1-i]=S[i];
	for (int i=0;i<x;i++)
		S[i]=reS[i];
	
}
