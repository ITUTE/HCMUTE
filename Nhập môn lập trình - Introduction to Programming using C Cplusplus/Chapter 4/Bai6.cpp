#include <stdio.h>
#define size 32000

void nhapMang(float A[], int m);
void xuatMang(float A[], float C[], int m);
void xuly(float A[], float B[], float C[], int m);

int main()
{
	float A[size],B[size],C[size];
	int m;
	scanf("%d", &m);
	nhapMang(A,m);
	nhapMang(B,m);
	xuly(A,B,C,m);
	xuatMang(A,C,m);
	return 0;
}

void nhapMang(float A[], int m)
{
	for (int i=0;i<m;i++)
		scanf("%f",&A[i]);
}

void xuatMang(float A[], float C[], int m)
{
	int i;
	//Nhung phan tu chi thuoc A[]
	for (i=0;i<m;i++)
		if (C[i]==1)
			printf("%f\t",A[i]);
	printf("\n");
	//Nhung phan tu thuoc A[] va B[]
	for (i=0;i<m;i++)
		if (C[i]==2)
			printf("%f\t",A[i]);
}

void xuly(float A[], float B[], float C[], int m)
{
	int i,j;
	//Khoi tao mang C[]
	for (i=0;i<m;i++)
		C[i]=1;
	//Loai bo nhung phan tu trung nhau	
	for (i=0;i<m;i++)
		for (j=i+1;j<m;j++)
			if (A[j]==A[i])
				C[j]=-1;
	//Kiem tra phan tu co thuoc A[] va B[]
	for (i=0;i<m;i++)
		for (j=0;j<m;j++)
			if ((B[j]==A[i])&&C[i]!=-1)
				C[i]=2;
}
