#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 1024

struct SNL{
	int sign;
	char value[SIZE];
};

double sum(double n);
void convert(SNL &num, double value);
void sumSNL(SNL num1, SNL num2, SNL &result);
void prepare(SNL &num1, SNL &num2);
void insert(char S[], int pos, int n, char ch);
void xuatSNL(SNL num);

int main()
{
	double n;	scanf("%lf",&n);
	double a=(n * (n + 1) * (2 * n + 4)) / 12.0; 
	double kq=sum(n);
	printf("%.0lf",kq);
	/*if (n<1000000){
		kq=sum(n);
		printf("%.0lf",kq);
	}else{
		SNL num;
		convert(num,kq);
		printf("%.0lf",n-1000000);
	}
	*/
	return 0;
}

double sum(double n)
{
	double s=0;
	for (double i=1;i<=n;i++)
		s+=(n-i+1)*i;
	return s;
}

void convert(SNL &num, double value)
{
	if (value<0.0){
		num.sign=-1;
		value=-value;
	}else num.sign=1;
	int len=0;
	while (long(value)){
		num.value[len++]=fmod(value,10)+'0';
		value/=10;
	}
	num.value[len]='\0';
}

void sumSNL(SNL num1, SNL num2, SNL &result)
{
	prepare(num1,num2);								//num1, num2 are reversed, result.value="".
	int n=strlen(num1.value), remind=0, tmp, i;
	for (i=0;i<n;i++)
	{
		tmp=num1.value[i]+num2.value[i]+remind-96;
		result.value[i]=tmp%10+'0';
		remind=tmp/10;
	}
	if (remind==1)	result.value[i++]='1';
	result.value[i]='\0';
}

void prepare(SNL &num1, SNL &num2)
{
	int len1=strlen(num1.value),	len2=strlen(num2.value);
	if (len1>len2)
		insert(num2.value,len2,len1-len2,'0');
	else if (len1<len2)
		insert(num1.value,len1,len2-len1,'0');
}

void insert(char S[], int pos, int n, char ch)
{
	int i;
	for (i=pos;i<pos+n;i++)
		S[i]=ch;
	S[i]='\0';
}

void xuatSNL(SNL num)
{
	if (num.sign==-1)
		printf("-");
	strrev(num.value);
	printf("%s",num.value);
	strrev(num.value);
}
