/*
	Xoa nhung phan tu SquareNum trong A[]
*/
#include <stdio.h>
#include <math.h>
#define size 32000

void nhapMang(int A[], int &n);
int squareNum(int x);
void del_element(int A[], int &n, int k);
void del_squareNum(int A[], int &n);
void xuatMang(int A[], int n);

int main()
{
	int A[size];
	int n;
	nhapMang(A,n);
	del_squareNum(A,n);
	xuatMang(A,n);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void xuatMang(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

//KT x co phai so Chinh phuong hay khong
int squareNum(int x)
{
	if (x<0)
		return 0;
	int sqrtX=sqrt(x);
	if (x==sqrtX*sqrtX)
		return 1;
	return 0;
}

//Xoa 1 phan tu trong A[]
void del_element(int A[], int &n, int k)
{
	for (int i=k;i<n-1;i++)
		A[i]=A[i+1];
	n--;
}

//Xoa cac phan tu thoa DK trong A[]
void del_squareNum(int A[], int &n)
{
	int i=0;
	while (i<n)
	{
		if (squareNum(A[i]))
			del_element(A,n,i);	/*Khong co i++ vi sau khi xoa 1 phan tu o vi tri i, thi A[i] da thay doi gia tri, ta phai kiem tra lai A[i]*/
		else
			i++;
	}
}
