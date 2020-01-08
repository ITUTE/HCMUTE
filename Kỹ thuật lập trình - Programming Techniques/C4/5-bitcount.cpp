#include <stdio.h>

int getbit(int n, int k);
int countbit(int n);
void bin(int n);

int main()
{
	int n;	scanf("%d",&n);
	bin(n);
	printf("%d",countbit(n));
	return 0;
}

int getbit(int n, int k)
{
	return (n>>k) & 0x1;
}
int countbit(int n)
{
	int sum=0;
	for (int i=8*sizeof(n)-1;i>=0;i--)
	{
		int tmp=getbit(n,i);
		if (tmp)
			sum++;
	}
	return sum;
}
void bin(int n)
{
	for (int i=8*sizeof(n)-1;i>=0;i--)
	{
		printf("%d",(n>>i) & 0x1);
		if (i%4==0)
			printf(" ");
	}
	printf("\n");
}
