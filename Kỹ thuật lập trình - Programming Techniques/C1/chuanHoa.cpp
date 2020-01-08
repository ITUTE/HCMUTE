#include <stdio.h>
#include <string.h>
#define SIZE 100

void chuanHoa(char S[]);
void xoaViTri(char S[], int pos, int length);
void inHoa(char S[]);
void insertSpace(char S[]);
void insert(char S[], int pos, char ch);
void xoaKhoangTrang(char S[]);

int main()
{
	char S[SIZE];
	gets(S);
	chuanHoa(S);
	puts(S);
	//printf("%d",strlen(S));
	return 0;
}

void chuanHoa(char S[])
{
	xoaKhoangTrang(S);
	insertSpace(S);
	inHoa(S);
}

void xoaViTri(char S[], int pos, int length)
{
	int len=strlen(S);
	int i;
	for (i=pos;i<len-length;i++)
		S[i]=S[i+length];
	S[i]='\0';
}

void xoaKhoangTrang(char S[])
{
	while (S[strlen(S)-1]==' ')
		S[strlen(S)-1]='\0';
	while (S[0]==' ')
		xoaViTri(S,0,1);
		
	int len=strlen(S);
	char tmp[4]=".?!";
	for (int i=0;i<len-1;)
		if (S[i]==' ' && (S[i+1]==' ' || strchr(tmp,S[i+1])!=NULL))		//strchr(char tmp[], char ch) de kiem tra ch co trong xau tmp hay khong, NULL neu ko co
			xoaViTri(S,i,1);
		else i++;
}

void inHoa(char S[])
{
	char tmp[4]=".?!";
	int len=strlen(S);
	if (S[0]>'Z')
		S[0]-=32;
	int i=1;
	while (i<len-2)
	{
		if (strchr(tmp,S[i])!=NULL && S[i+2]>'Z')					//S[i+2]>'Z' tuc la no khong IN HOA
			S[i+2]-=32;												// A = a - 32;
		else i++;
	}	
}

void insertSpace(char S[])
{
	char tmp[4]=".?!";
	int i=0;
	while (i<strlen(S))
	{
		if (strchr(tmp,S[i])!=NULL && S[i+1]>='A' && S[i+1]<='z')	//Kiem tra co dau Space sau dau cau (.?!) hay khong
			insert(S,i+1,' ');
		else i++;
	}
}

void insert(char S[], int pos, char ch)
{
	char tmp[SIZE];
	strncpy(tmp,S,pos);												//copy pos ki tu (tu 0 den pos-1) dau tien trong xau S vao xau tmp
	tmp[pos]=ch;													//chen ki tu ch vao vi tri pos
	int n=strlen(tmp);
	while (S[pos]!='\0')											//chua duyet het xau S
		tmp[n++]=S[pos++];											//copy phan con lai cua xau S sang xau tmp
	tmp[n]='\0';													//ket thuc xau
	strcpy(S,tmp);													//gan du lieu tu tmp ve xau S
}
