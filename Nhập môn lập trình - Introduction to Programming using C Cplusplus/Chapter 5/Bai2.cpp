#include <stdio.h>
#include <string.h>
#define size 100

void DecToBin(long int dec, char bin[]);
void DecToOct(long int dec, char oct[]);
void DecToHex(long int dec, char hex[]);
void swap(char &x, char &y);
void daoMang(char A[], int n);

int main()
{
	long int dec;
	char bin[size], oct[size], hex[size];
	scanf("%ld",&dec);
	DecToBin(dec,bin);
	printf("%s\n",bin);
	DecToOct(dec,oct);
	printf("%s\n",oct);
	DecToHex(dec,hex);
	printf("%s\n",hex);
	return 0;
}

void swap(char &x, char &y)
{
	char t=x;
	x=y;
	y=t;
}

void daoMang(char A[], int n)
{
	int i;
	for (i=0;i<n/2;i++)
		swap(A[i],A[n-1-i]);
}

void DecToBin(long int dec, char bin[])
{
	int i=0;
	while (dec>0)
	{
		bin[i++]=dec%2+'0';
		dec/=2;
	}
	bin[i]='\0';
	daoMang(bin,i);
}

void DecToOct(long int dec, char oct[])
{
	int i=0;
	while (dec>0)
	{
		oct[i++]=dec%8+'0';
		dec/=8;
	}
	oct[i]='\0';
	daoMang(oct,i);
}

void DecToHex(long int dec, char hex[])
{
	int i=0;
	while (dec>0)
	{
		if (dec%16+'0'<='9')
			hex[i++]=dec%16+'0';
		else
			hex[i++]=dec%16-10+'A';
		dec/=16;
	}
	hex[i]='\0';
	daoMang(hex,i);
}
