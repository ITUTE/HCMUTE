#include <stdio.h>
#include <string.h>
#define size 10000


#include <stdio.h>
#include <string.h>
#define SIZE 100

void daoXauTheoTu(char S[], char KQ[]);

int main()
{
	char S[SIZE],KQ[SIZE];
	gets(S);
	daoXauTheoTu(S,KQ);
	printf("%s",KQ);
	return 0;
}

void daoXauTheoTu(char S[], char KQ[])
{
	int i=strlen(S)-1;
	KQ[0]='\0';
	while (i>=0)
	{
		while ((S[i]==' ')&&(i>=0))
		{
			strcat(KQ," ");
			i--;
		}
		char tmp[100]="";
		int len=0;
		while (S[i]!=' '&&i>=0)
		{
			tmp[len++]=S[i];
			i--;
		}
		tmp[len]='\0';
		strrev(tmp);
		strcat(KQ,tmp);
	}

}

/*------------------------------------------------------------------
//C2
void revString(char S[]);
void copyString(char from[], char to[], int pos, int n);

int main()
{
	char S[size];
	gets(S);
	revString(S);
	printf("%s",S);
	//char t[size];
	//copyString(S,t,3,3);
	//printf("%s",t);
	return 0;
}

void copyString(char from[], char to[], int pos, int k)
{
	int len=strlen(to);
	int n=pos+k;
	for (int i=pos;i<n;i++)
		to[len++]=from[i];
	to[len]='\0';
}
void revString(char S[])
{
	char tmp[size]="";
	int i=strlen(S)-1;
	while (i>=0)
	{
		int count=0;
		while (S[i]!=' '&&i>=0)
		{
			i--;
			count++;
		}
		copyString(S,tmp,i+1,count);
		strcat(tmp," ");
		i--;
	}
	tmp[strlen(tmp)]='\0';
	strcpy(S,tmp);
}*/
