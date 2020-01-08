#include <stdio.h>
#include <string.h>

void Dec_Bin(double dec, char bin[]);
void Dec_Oct(double dec, char oct[]);

int main()
{
	double dec;
	scanf("%lf",&dec);
	char kq[50];
	Dec_Bin(dec,kq);
	//Dec_Oct(dec,kq);
	puts(kq);
	return 0;
}

void Dec_Bin(double dec, char bin[])
{
	int integral=dec;							//phan nguyen
	double fractional=dec-(double)integral;		//phan thap phan, lay gan dung
	int len=0;
	while (integral){							//while(integral>0)
		bin[len++]=integral%2 + '0';
		integral/=2;
	}
	bin[len]='\0';								//Ket thuc chuoi/xau
	strrev(bin);								//Dao nguoc chuoi/xau
	bin[len++]='.';
	int k;
	printf("Do chinh xac: k=");	scanf("%d",&k);
	while (k){									//while (k>0)
		double tmp=2*fractional;
		bin[len++]=(int) tmp + '0';
		fractional=tmp-(int)tmp;
		k--;
	}
	bin[len]='\0';
}

void Dec_Oct(double dec, char oct[])
{
	int integral=dec;							//phan nguyen
	double fractional=dec-(double)integral;		//phan thap phan, lay gan dung
	int len=0;
	while (integral){							//while(integral>0)
		oct[len++]=integral%8 + '0';
		integral/=8;
	}
	oct[len]='\0';								//Ket thuc chuoi/xau
	strrev(oct);								//Dao nguoc chuoi/xau
	oct[len++]='.';
	int k;
	printf("Do chinh xac: k=");	scanf("%d",&k);
	while (k){									//while (k>0)
		double tmp=8*fractional;
		oct[len++]=(int) tmp + '0';
		fractional=tmp-(int)tmp;
		k--;
	}
	oct[len]='\0';
}
