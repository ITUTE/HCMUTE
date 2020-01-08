#include <stdio.h>

void Eratosthenes(int &n);

int main()
{
	int n;
	Eratosthenes(n);	
	return 0;
}

void Eratosthenes(int &n)
{
	scanf("%d",&n);
	int A[n]={0};
	A[0]=1; A[1]=1;
	for (int i=2;i<=n;i++)
		if (A[i]==0)
			for (int j=2*i;j<=n;j+=i)
				A[j]=1;
	for (int i=0;i<=n;i++)
		if (A[i]==0)
			printf("%d ",i);
}
