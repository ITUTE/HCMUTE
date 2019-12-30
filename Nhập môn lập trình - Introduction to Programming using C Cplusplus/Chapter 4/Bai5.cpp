//Nhap va Sap xep Tang dan

#include <stdio.h>
#define size 32000

void nhapSapXepMang(int A[], int &n);
void insertElement(int A[], int &n, int k, int value);
void xuatMang(int A[], int n);

int main()
{
	int A[size],n;
	nhapSapXepMang(A,n);
	xuatMang(A,n);
	return 0;
}

void nhapSapXepMang(int A[], int &n)
{
	int value,j;
	scanf("%d",&n);
	scanf("%d",&A[0]);
	
	for (int i=1;i<n;i++)
	{
		scanf("%d",&value);
		
		//------Tim vi tri dat t-----
		j=0;
		// Sap xep tang dan
		while ((value>=A[j])&&(j<=i))
			j++;
		/*
		Sap xep giam dan
		while ((value<=A[j])&&(j<=i))
			j++;
		*/
		
		//vi tri insert: j
		if (j<=i)
			insertElement(A,i,j,value);
		//Phan tu vua nhap la max, insert vao vi tri i
		else
			A[i]=value;
		//------xong lan nhap thu i+1-----
	}
	
}

void insertElement(int A[], int &n, int k, int value)
{
	//n++; vi for da tang i++ roi
	for (int i=n+1;i>k;i--)
		A[i]=A[i-1];
	A[k]=value;
}
void xuatMang(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}
