#include <stdio.h>
void bin(int n);
void k_leftShift(int &n, int k);
void k_rightShift(int &n, int k);

int main()
{
	int n,k;		scanf("%d%d",&n,&k);
	bin(n);
	k_rightShift(n,k);
	bin(n);
	return 0;
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

void k_leftShift(int &n, int k)
{
	int tmp=n>>(8*sizeof(n)-k);
	n=n<<k;
	n=n|tmp;
}

void k_rightShift(int &n, int k)
{
	int x=32-k+1;
	int tmp=n<<x;
	bin(tmp);
	//n=n>>k;
	bin(n);
	n=n|tmp;
}
