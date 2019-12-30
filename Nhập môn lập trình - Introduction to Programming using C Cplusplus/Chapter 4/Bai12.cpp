#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &n);
int tongCucTri(int A[], int n);
void xuat(int kq);

int main()
{
	int A[size],B[size];
	int n;
	nhapMang(A,n);
	int sum=tongCucTri(A,n);
	xuat(sum);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

int tongCucTri(int A[], int n)
{
	int tong;
	/*
	Trong C/C++ khong ton tai A[-1] va A[n] la phan tu rac. Nen phai kiem tra rieng le A[0] va A[n-1] bang ham If
	*/
	
	//KT A[0]
	if (A[0]==A[1])
		tong=0;
	else tong=A[0];
	
	//KT A[i], 0<i<n-1
	for (int i=1;i<n-1;i++)
		if ( ((A[i]>A[i-1])&&(A[i]>A[i+1])) || ((A[i]<A[i-1])&&(A[i]<A[i+1])) )
			tong+=A[i];
	
	//KT A[n-1]
	if (A[n-2]!=A[n-1])
		tong+=A[n-1];
	return tong;
}
void xuat(int kq)
{
	printf("%d",kq);
}
