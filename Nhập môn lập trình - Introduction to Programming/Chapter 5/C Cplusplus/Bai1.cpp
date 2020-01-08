#include <stdio.h>
#include <string.h>
#include <math.h>
#define size 30

long HexToDec(char hex[]);

int main()
{
	char dec[size], hex[size];
	gets(hex);
	long kq=HexToDec(hex);
	printf("%ld",kq);
	return 0;
}

long HexToDec(char hex[])
{
	long kq=0;
	for (int i=0;i<strlen(hex);i++)
		if (hex[i]>='0'&&hex[i]<='9')
			kq+=(hex[i]-'0')*pow(16,strlen(hex)-1-i);
		else
			kq+=(hex[i]-55)*pow(16,strlen(hex)-1-i);
	return kq;
}


