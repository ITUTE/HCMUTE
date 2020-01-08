#include <stdio.h>

void nhap(int *&A, int &n);
int pos(int *A, int n);
int pos_MaxEven(int *A, int n);

int main()
{
	int *A;	int n;
	nhap(A,n);
	int p=pos(A,n);
	if (p>=0)
		printf("%d",A[p]);
	else printf("~~~~");
	delete[] A;
	return 0;
}

void nhap(int *&A, int &n)
{
	scanf("%d",&n);
	A=new int[n];
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

int pos(int *A, int n)
{
	int value=A[pos_MaxEven(A,n)];
	int pos=-1;
	for (int i=0;i<n;i++)
		if (A[i]%2 && A[i]>value)
			pos=i;
	return pos;
}

int pos_MaxEven(int *A, int n)
{
	int pos=-1;
	for (int i=0;i<n;i++)
		if (A[i]%2==0 && (A[i]>A[pos] || pos==-1))
			pos=i;
	return pos;
}
