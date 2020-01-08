#include <stdio.h>
#define max 32000

void nhap(int A[], int &n);
int test(int x);
int find(int A[], int n);
void xuat(int A[], int pos);

int main()
{
	int n,A[max];
	nhap(A,n);
	int pos=find(A,n);
	xuat(A,pos);
	return 0;
}

void nhap(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

//kiem tra x dang (a1a2...an) thoa (a1)%2!=0
int test(int x)
{
	int result;
	if (x<0) x=-x;
	while (x>0)
	{
		result=x%10;
		x/=10;
	}
	if (result%2!=0) return 1;
	else return 0;
}

int find(int A[], int n)
{
	for (int i=0;i<n;i++)
		if (test(A[i])) return i;
	return -1;
}

void xuat(int A[], int pos)
{
	if (pos==0) printf("%d",0);
	else printf("%d",A[pos]);
}
