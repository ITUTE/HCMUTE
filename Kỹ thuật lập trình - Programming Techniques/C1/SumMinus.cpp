#include <stdio.h>
#include <string.h>
#define SIZE 100

void sum(char num1[], char num2[], char result[]);
void sumAB(char num1[], char num2[], char result[]);
void minus(char num1[], char num2[], char result[]);
void minusAB(char num1[], char num2[], char result[]);
void pre(char num1[], char num2[]);
void chen(char S[], int n);
int soSanh(char num1[], char num2[]);

int main()
{
	char num1[SIZE], num2[SIZE], result[SIZE];
	gets(num1);
	gets(num2);
	sum(num1,num2,result);
	puts(result);
	minus(num1,num2,result);
	puts(result);
	return 0;
}

void pre(char num1[], char num2[])
{
	strrev(num1);	strrev(num2);
	int len1=strlen(num1);
	int len2=strlen(num2);
	int n=len1-len2;
	if (len1<len2)
		chen(num1,-n);
	else if (len2<len1)
		chen(num2,n);
	
}

void chen(char S[], int n)
{
	int i;
	int len=strlen(S);
	for (i=0;i<n;i++)
		S[len+i]='0';
	S[len+i]='\0';
}
void sumAB(char num1[], char num2[], char result[])
{
	int remind=0;
	int i=0, t;
	int len=strlen(num1);
	while (i<len)
	{
		t=num1[i]-'0'+num2[i]-'0'+remind;
		result[i]=t%10+'0';
		remind=t/10;
		i++;
	}
	if (remind==1)
	{
		result[i]='1';
		result[i+1]='\0';
	}else
		result[i]='\0';
}

void sum(char n1[], char n2[], char result[])
{
	char num1[SIZE], num2[SIZE];
	strcpy(num1,n1);	strcpy(num2,n2);
	if (num1[0]=='-'&&num2[0]=='-')
	{
		pre(num1,num2);
		sumAB(num1,num2,result);
		strcat(result,"-");
		strrev(result);
	} else if (num2[0]=='-')
		minus(num1,num2,result);
}

void minusAB(char num1[], char num2[], char result[])
{
	int remind=0, t,i;
	int len=strlen(num1);
	for (i=0;i<len;i++)
	{
		if	(num1[i]>=num2[i]+remind)
		{
			t=num1[i]-num2[i]-remind;
			remind=0;
		}
		else
		{
			t=num1[i]+10-num2[i]-remind;
			remind=1;
		}
		result[i]=t+'0';	
	}
	
	i--;
	while (result[i]=='0')
		result[i--]='\0';
}

void minus(char n1[], char n2[], char result[])
{
	char num1[SIZE], num2[SIZE];
	strcpy(num1,n1);	strcpy(num2,n2);
	int kq=soSanh(num1,num2);
	pre(num1,num2);
	if (kq>0)
		minusAB(num1,num2,result);
	else if (kq<0)
	{
		minusAB(num2,num1,result);
		strcat(result,"-");
	}
	else strcpy(result,"0");
	strrev(result);
}

int soSanh(char num1[], char num2[])
{
	if (strlen(num1)>strlen(num2))
		return 1;
	else if (strlen(num2)>strlen(num1))
		return -1;
	return strcmp(num1,num2);
	
}
