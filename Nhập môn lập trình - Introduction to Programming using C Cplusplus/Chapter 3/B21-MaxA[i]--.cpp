//-----Vi tri A[i]<0 lon nhat-----

#include <stdio.h>
#define max 32000

void nhap(float A[], int &n);
int find(float A[], int n);
int first(float A[], int n);
void xuat(int pos);

int main()
{
	int n;
	float A[max];
	nhap(A,n);
	int pos=find(A,n);
	xuat(pos);
	return 0;
}

void nhap(float A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%f", &A[i]);
}

int first(float A[], int n)
{
	for (int i=0;i<n;i++)
		if (A[i]<0) return i;
	return -1;
}
int find(float A[], int n)
{
	int f=first(A,n);
	if (f>0&&f==n-1) return -1;	//A[i] luon >=0; xet i>0 de bo qua TH n=1
	else 
	{
		//Tim A[j]<0 lon nhat
		for (int i=f+1;i<n;i++)
			if (A[i]<0&&A[i]>A[f]) f=i;
		return f;
	}
}

void xuat(int pos)
{
	if (pos==-1) printf("%d",-1);
	else printf("%d",pos);
}
