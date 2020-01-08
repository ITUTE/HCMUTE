#include <stdio.h>
#include <string.h>
#define SIZE 128

double tachSo(char S[], int &pos);
double sum(char S[]);

int main()
{
	char S[SIZE];	gets(S);
	double kq=sum(S);
	printf("%.0lf",kq);
	return 0;
}

double sum(char S[])
{
	int i=0, len=strlen(S);
	double s=0;
	while (i<len)
		s+=tachSo(S,i);
	return s;
}

double tachSo(char S[], int &pos)
{
	while (S[pos]<'0' || S[pos]>'9')
		pos++;
	double num=0;
	while (S[pos]>='0' && S[pos]<='9')
	{
		num=10*num+double(S[pos]-'0');
		pos++;
	}
	return num;
}
