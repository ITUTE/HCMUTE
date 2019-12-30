#include <stdio.h>
#define max 32000

void nhapMang(int A[], int &n);
void xuatMang(int A[],int n);
void tronMang(int A[],int B[],int C[], int nA, int nB,int &nC);

int main()
{
	int A[max],B[max],C[max],nA,nB,nC;
	nhapMang(A,nA);
	nhapMang(B,nB);
	tronMang(A,B,C,nA,nB,nC);
	xuatMang(C,nC);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	int i;
	for (i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void xuatMang(int A[],int n)
{
	int i;
	for (i=0;i<n;i++)
		printf("%d ",A[i]);
}

void tronMang(int A[],int B[],int C[], int nA, int nB, int &nC)
{
	int i=0,a=0,b=0;
	
	//So phan tu mang C[]
	nC=nA+nB;
	
	while ((a<nA)&&(b<nB))
	{
		while ((A[a]<=B[b])&&(a<nA))
		{
			C[i]=A[a];
			i++;
			a++;
		}
		while ((B[b]<=A[a])&&(b<nB))
		{
			C[i]=B[b];
			i++;
			b++;
		}
	}
	
	/*
	Sau vong lap while, hoac A[] hoac B[] con phan tu chua duoc them vao C[]
	*/
	
	/*
	Mang A[] con phan tu
	b=nB+1
	A[a] chua co trong C[i]
	*/
	if (a<nA)
		for (int j=i;j<nC;j++)
		{	
			C[j]=A[a];
			a++;
		}
	/*
	Mang B[] con phan tu
	a=nA+1
	B[b] chua co trong C[i]
	*/
	else
		for (int j=i;j<nC;j++)
		{
			C[j]=B[b];
			b++;
		}
}
