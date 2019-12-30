#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &n);
int kiemtra(int A[], int B[], int m, int n);
void xuat(int kq);

int main()
{
	int A[size],B[size];
	int m,n;
	nhapMang(A,m);
	nhapMang(B,n);
	int kq=kiemtra(A,B,m,n);
	xuat(kq);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void xuat(int kq)
{
	printf("%d",kq);
}

int kiemtra(int A[], int B[], int m, int n)
{
	int flag;
	if (m>n)
		return 0;
	else
	{
		/*
		So sanh tung gia tri A[] voi tung gia tri cua B[]
		Neu cac gia tri cua A[] deu thuoc B[] thi A[]<=B[]
		
		Luu y: Thu tu vong lap
		*/
		for (int i=0;i<m;i++)
		{
			flag=0;					//Gia su A[i] khong thuoc B[]
			for (int j=0;j<n;j++)	//Vong lap de xem xet Ai] co trong B[] hay khong, dung de thay doi gia tri flag neu co ton tai
				if (A[i]==B[j])		//Neu A[i] ton tai trong B[]
				{
					flag=1;
					break;
				}
			if (flag==0)			//Duyet het mang B[], nhung khong thay ton tai B[j]==A[i], nen flag khong doi gia tri
				return 0;			//Neu co phan tu A[i] nao khong thoa DK thi ket thuc function
		}
		return 1;
	}
}
