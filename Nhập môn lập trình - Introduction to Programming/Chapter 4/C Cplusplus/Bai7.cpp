#include <stdio.h>
#define size 32000

void nhapMang(float A[], int &n);
void nhap(float &x, float &y);
void xuly(float A[], float C[], int n,float x, float y);
void xuatMang(float A[], float flag[],int n);

int main()
{
	float A[size],flag[size],x,y;
	int n;
	nhapMang(A,n);
	nhap(x,y);
	xuly(A,flag,n,x,y);
	xuatMang(A,flag,n);
	return 0;
}

void nhapMang(float A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%f",&A[i]);
}

void nhap(float &x, float &y)
{
	scanf("%f%f",&x,&y);
}
void xuly(float A[], float flag[], int n, float x, float y)
{
	for (int i=0;i<n;i++)
		if ((A[i]>=x)&&(A[i]<=y))
			flag[i]=1;	
}

void xuatMang(float A[], float flag[], int n)
{
	for (int i=0;i<n;i++)
		if (flag[i]==1)
			printf("%f\t",A[i]);
}
