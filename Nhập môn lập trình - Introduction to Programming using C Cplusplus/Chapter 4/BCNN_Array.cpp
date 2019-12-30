#include <stdio.h>
#define SIZE 10000

void inputArray(int A[], int &n);
int UCLN(int a, int b);
int BCNN(int a, int b);
int BCNN_Array(int A[], int n);

int main()
{
	int A[SIZE];
	int n;
	inputArray(A,n);
	int kq=BCNN_Array(A,n);
	printf("%d",kq);
	return 0;
}

void inputArray(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

int UCLN(int a, int b)
{
	if (a<0) a=-a;
	if (b<0) b=-b;
	while (a*b!=0)
		if (a>b) a%=b;
			else
				if (b>a) b%=a;
	return a+b;
}

int BCNN(int a, int b)
{
	return (a*b)/UCLN(a,b);
}
int BCNN_Array(int A[], int n)
{
	int kq=BCNN(A[0],A[1]);
	for (int i=2;i<n;i++)
		kq=BCNN(kq,A[i]);
	return kq;
}
