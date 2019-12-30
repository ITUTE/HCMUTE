#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &n);
int kiemtra(int A[], int n);
void xuat(int kq);

int main()
{
	int A[size],B[size];
	int n;
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

/*
	Kiem tra xem mang A[] co dang "song" hay khong?
	Mang A[] dang "song" neu A[i] > hoac < 2 phan tu xung quanh
*/
int kiemtra(int A[], int n)
{
	
	for (int i=1;i<n-1;i++)
	{
		int DK=( ((A[i]>A[i-1])&&(A[i]>A[i+1])) || ((A[i]<A[i-1])&&(A[i]<A[i+1])) );
		if (!DK)	//Dung !() de phu dinh DK de cho
			return 0;
	}
	return 1;
}
void xuat(int kq)
{
	printf("%d",kq);
}
