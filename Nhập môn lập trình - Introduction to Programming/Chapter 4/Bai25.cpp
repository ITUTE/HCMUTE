/*
	Xoa nhung phan tu max trong A[]
*/
#include <stdio.h>
#define size 32000

void nhapMang(float A[], int &n);
float maxArr(float A[],int n);
void del_element(float A[], int &n, int k);
void del_max(float A[], int &n);
void xuatMang(float A[], int n);

int main()
{
	float A[size];
	int n;
	nhapMang(A,n);
	del_max(A,n);
	xuatMang(A,n);
	return 0;
}

void nhapMang(float A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%f",&A[i]);
}

void xuatMang(float A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%f\t",A[i]);
}

//Tim kiem gia tri max trong A[]
float maxArr(float A[],int n)
{
	float result=A[0];
	for (int i=1;i<n;i++)
		if (A[i]>result)
			result=A[i];
	return result;
}

//Xoa 1 phan tu trong A[]
void del_element(float A[], int &n, int k)
{
	for (int i=k;i<n-1;i++)
		A[i]=A[i+1];
	n--;
}

//Xoa cac phan tu thoa DK trong A[]
void del_max(float A[], int &n)
{
	float max=maxArr(A,n);
	int i=0;
	while (i<n)
	{
		if (A[i]==max)
			del_element(A,n,i);	/*Khong co i++ vi sau khi xoa 1 phan tu o vi tri i, thi A[i] da thay doi gia tri, ta phai kiem tra lai A[i]*/
		else
			i++;
	}
}
