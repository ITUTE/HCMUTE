#include <stdio.h>
#include <string.h>
#define SIZE 128

void phanLoai(char S[], int count[]);

int main()
{
	char S[SIZE];
	gets(S);
	int count[4]={0};
	phanLoai(S,count);
	for (int i=0;i<4;i++)
		printf("%d ",count[i]);
	return 0;
}

void phanLoai(char S[], int count[])
{
	int n=strlen(S);
	for (int i=0;i<n;i++)
		if (S[i]>=97 && S[i]<=122)
			count[0]++;
		else if (S[i]>=65 && S[i]<=90)
			count[1]++;
		else if (S[i]>=48 && S[i]<=57)
			count[2]++;
		else count[3]++;
}
