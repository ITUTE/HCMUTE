#include <stdio.h>
#include <string.h>
#define SIZE 100


void tachSo(unsigned long x, int A[], int &nA);
void docSo(unsigned long x);

int main()
{
	unsigned long x;
	scanf("%ld",&x);
	char so[10][10]={"khong","mot","hai","ba","bon","nam","sau","bay","tam","chin"};
	docSo(x);
	return 0;
}
/* 	
	0	1	2	.	3	4	5	
	1	7	0	.	9	0	7
	
	0	1	.	2	3	4 
	1	3	.	2	9	2	
*/

void donVi(int A[], int n, int k, char so[10][10], char text[])
{
	char viTri[10][10]={"","muoi","tram"};
	for (int i=3;i>0;i--)
	{
		strcat(text,so[A[i]]);
		strcat(text," ");
		strcat(text,viTri[k-i])
	}
	
}
void docSo(unsigned long x)
{
	int A[SIZE];
	int nA;
	tachSo(x,A,nA);
	for (int a=0;a<nA;a++) printf("%d\t",A[a]);
	
	
	char viTri[10][15]={" "," muoi "," tram "," nghin "," muoi nghin "," tram nghin "," trieu "," muoi trieu "," tram trieu "," ty "};
	
	char boiSo[10][10]={" "," nghin "," trieu "," ty "};
	char text[SIZE]="";
	for (int i=0;i<nA;i++)
	{
		strcat(text,so[A[i]]);
		strcat(text,viTri[(nA-i)%3]);
		
	}
	text[strlen(text)]='\0';
	printf("%s",text);
	
}

void tachSo(unsigned long x, int A[], int &nA)
{
	int B[SIZE];
	nA=0;
	while (x>0)
	{
		B[nA++]=x%10;
		x/=10;
	}
	for (int i=0;i<nA;i++)
		A[i]=B[nA-i-1];
}
