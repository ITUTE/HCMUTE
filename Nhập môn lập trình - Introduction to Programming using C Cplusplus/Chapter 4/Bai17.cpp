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

//KT trong mang A[] co phan tu co gia tri 0 hay khong
int kiemtra(int A[], int n)
{
	for (int i=0;i<n;i++)
	
		//Neu tim thay thi thong bao 1 va ket thuc function
		if (A[i]==0) return 1;
		
	//Duyet het mang A[] va khong thay phan tu mang gia tri 0
	return 0;
}

void xuat(int kq)
{
	printf("%d",kq);
}
