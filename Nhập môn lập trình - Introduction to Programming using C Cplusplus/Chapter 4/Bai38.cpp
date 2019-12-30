#include <stdio.h>
#define size 100

void nhapMang(int A[], int &n);
int AinB(int A[], int nA, int B[], int nB);
int check(int A[], int nA, int B[], int nB, int start);

int main()
{
	int A[size],B[size];
	int nA,nB;
	nhapMang(A,nA);
	nhapMang(B,nB);
	int kq=AinB(A,nA,B,nB);
	printf("%d",kq);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

int AinB(int A[], int nA, int B[], int nB)
{
	int count=0;
	if (nA>nB) return 0;
	int i=0;
	while (i<nB)
	{
		//i cho biet vi tri trong B[] bang A[0]
		while ((A[0]!=B[i])&&(i<nB))
			i++;
		if (i==nB) return count;
		else
			if (check(A,nA,B,nB,i))
				count++;
		i++;
	}
	return count;
}

int check(int A[], int nA, int B[], int nB, int start)
{
	for (int i=0;i<nA;i++)
		if (A[i]!=B[i+start])
			return 0;
	return 1;
}
