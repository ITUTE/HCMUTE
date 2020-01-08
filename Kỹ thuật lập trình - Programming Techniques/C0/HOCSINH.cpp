#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE		50
#define size_MSHS	6
#define size_hoten	31
#define size_diachi	51
#define size_phai	4
#define PATH		"HOCSINH.txt"

struct DATE{
	int dd, mm, yyyy;
};

struct HOCSINH{
	char MSHS[size_MSHS], hoten[size_hoten], diachi[size_diachi], phai[size_phai];
	DATE ngaysinh;
	double dtb;
};

char* fgetline(FILE *fp, char *str, int maxSIZE);
void getStudent(FILE *fp, HOCSINH &x);
void getAllStudents(HOCSINH HS[], int &n);
void xuat(HOCSINH HS[], int n);
int count_LenLop(HOCSINH HS[], int n);

int main()
{
	HOCSINH HS[SIZE];
	int n;
	getAllStudents(HS,n);
	xuat(HS,n);
	printf("%d",count_LenLop(HS,n));
	return 0;
}

int count_LenLop(HOCSINH HS[], int n)
{
	int count=0;
	for (int i=0;i<n;i++)
		if (HS[i].dtb>=5)
			count++;
	return count;
}

void xuat(HOCSINH HS[], int n)
{
	for (int i=0;i<n;i++)
	{
		puts(HS[i].MSHS);
		puts(HS[i].hoten);
		printf("%d %d %d\n",HS[i].ngaysinh.dd,HS[i].ngaysinh.mm,HS[i].ngaysinh.yyyy);
		puts(HS[i].diachi);
		puts(HS[i].phai);
		printf("%.2lf",HS[i].dtb);
		printf("\n\n");
	}
}

void getAllStudents(HOCSINH HS[], int &n)
{
	FILE *fp=fopen(PATH,"r");
	if (fp==NULL)
		exit(0);
	fscanf(fp,"%d",&n);
	char ch=fgetc(fp);
	for (int i=0;i<n;i++)
		getStudent(fp,HS[i]);
	fclose(fp);
}

void getStudent(FILE *fp, HOCSINH &x)
{
	char ch;	double tmp;
	fgetline(fp,x.MSHS,size_MSHS);
	fgetline(fp,x.hoten,size_hoten);
	fscanf(fp,"%d%d%d", &x.ngaysinh.dd, &x.ngaysinh.mm, &x.ngaysinh.yyyy);	ch=fgetc(fp);
	fgetline(fp,x.diachi,size_diachi);
	fgetline(fp,x.phai,size_phai);
	fscanf(fp,"%lf",&tmp);	ch=fgetc(fp);
	x.dtb=tmp;
}

char* fgetline(FILE *fp, char *str, int maxSIZE)
{
	int ch, len;
	if (feof(fp))
		return NULL;
	len=0;
	do{
		ch=fgetc(fp);
		if (ch=='\n' || ch==EOF)
			break;
		if (len<maxSIZE-1)
			str[len++]=ch;
	} while (1);
	str[len]=0;
	return str;
}
