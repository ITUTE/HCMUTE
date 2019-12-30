#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &n);
int kiemtra(int A[], int n);
void xuat(int kq);

int main()
{
	int A[size],n;
	nhapMang(A,n);
	int kq=kiemtra(A,n);
	xuat(kq);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

//KT tinh chan-le cua mang A[]
int kiemtra(int A[], int n)
{
	for (int i=0;i<n-1;i++)
	
		//Neu A[i] va A[i+1] ko thoa DK thi thong bao 0 va ket thuc function
		if ( (A[i]+A[i+1]) %2 ==0 )
			if ((A[i-1]==0)||(A[i+1]==0))
				return 0;
		
	//Duyet het mang A[]
	return 1;
}

void xuat(int kq)
{
	printf("%d",kq);
}
