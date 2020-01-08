#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &m);
void xuat(int kq);
int solve(int A[], int B[], int m, int n);

int main()
{
	int A[size],B[size],m,n;
	nhapMang(A,m);
	nhapMang(B,n);
	int kq=solve(A,B,m,n);
	xuat(kq);
	return 0;
}

void nhapMang(int A[], int &m)
{
	scanf("%d",&m);
	for (int i=0;i<m;i++)
		scanf("%d",&A[i]);
}

void xuat(int kq)
{
	printf("%d",kq);
}

int solve(int A[], int B[], int m, int n)
{
	int count=m;				//Gia su m phan tu A[] hoan toan khac cac phan tu B[]
	for (int i=0;i<m;i++)
	{
		int remind=1;			//Neu remind=0, B[j] da ton tai trong A[], nen se khong tang count
		for (int j=0;j<n;j++)
			if (B[j]==A[i])		//B[j] trung A[i] 1 lan, nen count--
			{
				count--;	
				remind=0;		//Ghi nho B[j] da ton tai trong A[]
			}
		if (remind==1) count++;	//B[j] khong ton tai trong A[], nen so phan tu khac nhau tang them 1
	}
	return count;
	/*
	//Dem so gia tri trung nhau
	int C[size];
	int count;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if ((B[j]==A[i])&&(C[i]==0))
			{
				count++;
				C[i]=1;
			}
	*/
}
