#include <stdio.h>
#include <string.h>
#define SIZE 128

void nhap(int A[], int B[], int &n);
void xuat(int A[], int n);
void update(int tmp[]);
void generate();
int n,	best=1000000;
int p[SIZE]={0}, A[SIZE]={0}, B[SIZE]={0};	

int main()
{
	nhap(A,B,n);
	generate();
	printf("%d\n",best);
	xuat(p,n);
	return 0;
}

void generate()
{
	int tmp[SIZE]={0};		//tmp[i]=1=chon A, tmp[i]=0=chon B
	while (1){
		update(tmp);
		int i=n-1;
		while (tmp[i]==1 && i>=0){
			tmp[i]=0;
			i--;
		}
		if (i<0)
			return;
		tmp[i]=1;
	}
}

void update(int tmp[])
{
	//tmp[i]=1=chon A, tmp[i]=0=chon B
	int t1=0, t2=0, cost;
	for (int i=0;i<n;i++)
		if (tmp[i])
			t1+=A[i];
		else t2+=B[i];
	if (t1<t2)
		cost=t2;
	else cost=t1;
	if (cost<best)
	{
		best=cost;
		for (int i=0;i<n;i++)
			p[i]=tmp[i];
	}
}

void nhap(int A[], int B[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
	for (int j=0;j<n;j++)
		scanf("%d",&B[j]);
}

void xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}
