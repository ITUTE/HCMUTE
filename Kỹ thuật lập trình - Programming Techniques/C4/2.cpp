#include <stdio.h>

void nhap(int *&A, int &n);
int isAmstrong(int a);
int sumAmstrong(int *A, int n);

int main()
{
	int *A;	int n;
	nhap(A,n);
	int kq=sumAmstrong(A,n);
	printf("%d",kq);
	delete[] A;
	return 0;
}

int isAmstrong(int a)
{
	int d=0, x=a;
	while (x>0)
	{
		int tmp=x%10;
		d+=tmp*tmp*tmp;
		x/=10;
	}
	if (d==a)
		return 1;
	return 0;
}

int sumAmstrong(int *A, int n)
{
	int sum=0;
	for (int i=0;i<n;i++)
		if (isAmstrong(A[i]))
			sum+=A[i];
	return sum;
}

void nhap(int *&A, int &n)
{
	scanf("%d",&n);
	A=new int[n];
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}
