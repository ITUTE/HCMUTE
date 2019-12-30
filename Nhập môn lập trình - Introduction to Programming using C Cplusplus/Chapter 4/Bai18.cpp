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

//KT trong mang A[] co 2 phan tu co gia tri 0 ke tiep hay khong
int kiemtra(int A[], int n)
{
	for (int i=1;i<n-1;i++)
	
		//Neu tim thay thi thong bao 1 va ket thuc function
		if (A[i]==0)
			if ((A[i-1]==0)||(A[i+1]==0))
				return 1;
		
	//Duyet het mang A[] va khong thay 2 phan tu mang gia tri 0 ke tiep
	return 0;
}

void xuat(int kq)
{
	printf("%d",kq);
}
