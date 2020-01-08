#include <stdio.h>
#include <string.h>
#define SIZE 100

void dec_hex(long int dec, char hex[]);
void dec_bin(long int dec, char bin[]);
void dec_oct(long int dec, char oct[]);

int main()
{
	char result[SIZE];
	long int dec, oct, bin;
	scanf("%ld",&dec);
	dec_oct(dec,result);
	printf("%s",result);
	return 0;
}

void dec_hex(long int dec, char hex[])
{
	char tmp[SIZE]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int i=0;
	while (dec>0)
	{
		hex[i++]=tmp[dec%16];
		dec/=16;
	}
	hex[i]='\0';
	strrev(hex);
}

void dec_bin(long int dec, char bin[])
{
	int i=0;
	while (dec>0)
	{
		bin[i++]=dec%2+'0';
		dec/=2;
	}
	bin[i]='\0';
	strrev(bin);
}

void dec_oct(long int dec, char oct[])
{
	int i=0;
	while (dec>0)
	{
		oct[i++]=dec%8+'0';
		dec/=8;
	}
	oct[i]='\0';
	strrev(oct);
}
