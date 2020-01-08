#include <stdio.h>
#define max 32000

void nhap(float A[], int &n, float &x);
int find(float A[], int n, float x);
void xuat(float A[], int pos);

int main()
{
	int n;
	float A[max],x;
	nhap(A,n,x);
	int pos=find(A,n,x);
	xuat(A,pos);
	return 0;
}

void nhap(float A[], int &n, float &x)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%f", &A[i]);
	scanf("%f",&x);
}

int find(float A[], int n, float x)
{
	if (x>=0) return -1;
	else
		for (int i=n-1;i>=0;i--)
			if (A[i]<0&&A[i]>x) return i;
	return -1;
}

void xuat(float A[], int pos)
{
	if (pos==-1) printf("%d",0);
	else printf("%f",A[pos]);
}


