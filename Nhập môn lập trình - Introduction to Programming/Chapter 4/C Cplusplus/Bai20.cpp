//Kiem tra mang doi xung

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

//KT mang A[] co doi xung khong
int kiemtra(int A[], int n)
{
	//tim phan tu khong doi xung trong mang A[]
	for (int i=0;i<n/2;i++)
	
		//Neu tim thay phan tu khong doi xung thi thong bao 0 va ket thuc function
		if (A[i]!=A[n-i-1])
			return 0;
		
	//Duyet het mang A[]
	return 1;
}

void xuat(int kq)
{
	printf("%d",kq);
}
