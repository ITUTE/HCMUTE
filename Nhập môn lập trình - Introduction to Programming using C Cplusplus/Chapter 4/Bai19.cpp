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

//KT mang A[] co phai mang so "chan" khong
int kiemtra(int A[], int n)
{
	//tim phan tu "le" trong mang A[]
	for (int i=0;i<n;i++)
	
		//Neu tim thay phan tu co gia tri "le" thi thong bao 0 va ket thuc function
		if (A[i]%2==1)
			return 0;
		
	//Duyet het mang A[] va khong thay phan tu "le"
	return 1;
}

void xuat(int kq)
{
	printf("%d",kq);
}
