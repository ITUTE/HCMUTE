#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 300000

void compress(char plainText[], char compressedText[], int freq[],int &length);

int main()
{
	char plainText[size], compressedText[size];
	int freq[size],n;
	gets(plainText);
	compress(plainText,compressedText,freq,n);
	for (int i=0;i<n;i++)
		printf("%d%c",freq[i],compressedText[i]);
	return 0;
}

void compress(char plainText[], char compressedText[], int freq[], int &length)
{
	int i=0;
	length=0;
	while (i<strlen(plainText))
	{
		int count=1,j=i+1;
		while (plainText[i]==plainText[j])
		{
			count++;
			j++;
		}
		freq[length]=count;
		compressedText[length++]=plainText[i];
		i=j;
	}
}
