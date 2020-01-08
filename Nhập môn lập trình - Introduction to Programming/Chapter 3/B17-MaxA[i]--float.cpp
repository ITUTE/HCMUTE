//-----So A[i]<0 lon nhat-----

#include <stdio.h>
#define max 32000

void nhap(float A[], int &n);
int find(float A[], int n);
void xuat(float A[], int pos);

int main()
{
	int n;
	float A[max];
	nhap(A,n);
	int pos=find(A,n);
	xuat(A,pos);
	return 0;
}

void nhap(float A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%f", &A[i]);
}

int find(float A[], int n)
{
	//Tim vi tri phan tu <0 dau tien
	int i=0;
	while ((A[i]>=0)&&(i<n)) i++;
	if (i>0&&i==n-1) return -1;	//A[i] luon >=0; xet i>0 de bo qua TH n=1
	else 
	{
		//Tim A[j]<0 lon nhat
		for (int j=i+1;j<n;j++)
			if (A[j]<0&&A[j]>A[i]) i=j;
		return i;
	}
}

void xuat(float A[], int pos)
{
	if (pos==-1) printf("%d", 0);
	else printf("%f",A[pos]);
}
