/*
Dem so lan xuat hien cua cac tu trong xau S2 trong xau S1

VD:
INPUT
S1=hello hi good morning bye good afternoon hi hello! bye
S2=hi hello good bye

OUTPUT
hi      2
hello   1
good    2
bye     2
*/
#include <stdio.h>
#include <string.h>
#define SIZE 100

void nhap_string(char S[]);
void tach_string(char S[], char subS[], int start);
int count_substring(char S[], char subS[]);
void freq_substring(char S1[], char S2[]);

int main()
{
	char S1[SIZE],S2[SIZE];
	nhap_string(S1);
	nhap_string(S2);
	freq_substring(S1,S2);
	return 0;
}

void nhap_string(char S[])
{
	fflush(stdin);
	gets(S);
}
int count_substring(char S[], char subS[])
{
	int d=0,i=0;
	int n=strlen(S);
	while (i<n)
	{
		while (S[i]==32&&i<n)
			i++;
		char tmp[SIZE];
		int len=0;
		while (S[i]!=32&&i<n)
			tmp[len++]=S[i++];
		tmp[len]='\0';
		if (strcmp(subS,tmp)==0)
			d++;
	}
	return d;
}

void tach_string(char S[], char subS[], int start)
{
	int i=start;
	int n=strlen(S);
	subS[0]='\0';
	int len=0;
	while (S[i]==32&&i<n)
		i++;
	while (S[i]!=32&&i<n)
		subS[len++]=S[i++];
	subS[len]='\0';
}

void freq_substring(char S1[], char S2[])
{
	int i=0;
	int n=strlen(S2);
	while (i<n)
	{
		char tmp[SIZE];
		tach_string(S2,tmp,i);
		int count=count_substring(S1,tmp);
		printf("%s\t%d\n",tmp,count);
		i+=strlen(tmp)+1;
	}
}
