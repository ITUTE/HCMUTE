//-----Xoa space-----

#include <stdio.h>
#include <string.h>
#define size 10000

void DelSpace(char S[]);
void DelElement(char S[], int k);
void xoaDau(char S[]);
void xoaGiua(char S[]);
void xoaCuoi(char S[]);

int main()
{
	char S[size];
	gets(S);
	DelSpace(S);
	printf("%s",S);
	//printf("\n%d",strlen(S));
	return 0;
}

void DelSpace(char S[])
{
	xoaDau(S);
	xoaGiua(S);
	xoaCuoi(S);
}

void xoaDau(char S[])
{
	while (S[0]==' ')
		DelElement(S,0);
}

void xoaCuoi(char S[])
{
	while (S[strlen(S)-1]==' ')
		S[strlen(S)-1]='\0';
}

void xoaGiua(char S[])
{
	int i=0,n=strlen(S);
	while (i<n)
	{
		if (S[i]==' '&&S[i+1]==' ')
			DelElement(S,i+1);
		else i++;
	}
}

void DelElement(char S[], int k)
{
	int i,n=strlen(S);
	for (i=k;i<n-1;i++)
		S[i]=S[i+1];
	S[n-1]='\0';
}
