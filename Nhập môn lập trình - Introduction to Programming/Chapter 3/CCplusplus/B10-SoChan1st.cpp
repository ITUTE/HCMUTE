//-----Phan tu A[i]%2==0 dau tien-----

#include <stdio.h>
#define max 32000

void nhap(int A[], int &n);
void xuat(int A[], int pos);
int find(int A[], int n);

int main()
{
	int n;
	int A[max];
	nhap(A,n);
	int pos=find(A,n);
	xuat(A,pos);
	return 0;
}

void nhap(int A[], int &n)
{
	scanf("%d", &n);
	for (int i=0;i<n;i++)
		scanf("%d", &A[i]);
}

void xuat(int A[], int pos)
{
	if (pos==-1) printf("%d",pos);//ko thay
	else printf("%d", A[pos]);
}

int find(int A[], int n)
{
	for (int i=0; i<n;i++)
		if (A[i]%2==0) return i;
	//Ko tim thay
	return -1;
}
