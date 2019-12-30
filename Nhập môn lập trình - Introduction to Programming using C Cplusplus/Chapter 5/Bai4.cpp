//-----Dem so tu (word) trong chuoi S[] da chuan hoa-----

#include <stdio.h>
#include <string.h>
#define size 10000

int count(char S[]);

int main()
{
	char S[size];
	gets(S);
	int kq=count(S);
	printf("%d",kq);
	return 0;
}

int count(char S[])
{
	int sum=0;
	for (int i=0;i<strlen(S)-1;i++)
		if (S[i]!=' '&&S[i+1]==' ')
			sum++;
	return sum+1;
}
