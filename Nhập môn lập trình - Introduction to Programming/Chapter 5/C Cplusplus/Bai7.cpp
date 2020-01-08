#include <stdio.h>
#include <string.h>
#define SIZE 100

int sum(char S[]);
int tachSo(char S[], int &pos);

int main()
{
	char S[SIZE];
	gets(S);
	char S1[SIZE];
	memcpy(S1,S,strlen(S)+1);
	//int kq=sum(S);
	printf("%d",S1);
}

int sum(char S[])
{
	int d=0;
	int n=strlen(S);
	for (int i=0;i<n;i++)
		if (S[i]>='0'&&S[i]<='9')
			d+=tachSo(S,i);
	return d;
}

int tachSo(char S[], int &pos)
{
	int num=0;
	int i=pos;
	while (S[i]>='0'&&S[i]<='9')
	{
		int x=S[i]-48;
		num=10*num+x;
		i++;
	}
	if (S[pos-1]=='-'&&pos-1>=0)
		num=-num;
	pos=i;
	return num;
}
