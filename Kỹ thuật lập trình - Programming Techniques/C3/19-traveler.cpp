#include <stdio.h>
#include <string.h>
#define SIZE 128
#define PATH "ways.txt"
void nhap(int A[][SIZE], int &n);
void xuat(int A[], int n);
void traveler();
void swap(int &x, int &y);
void update(int A[]);
int C[SIZE][SIZE]={0},	p[SIZE]={0};
int n,	cost=0,	best=1000000;;

int main()
{
	nhap(C,n);
	traveler();
	printf("%d\n",best);
	xuat(p,n+1);
	return 0;
}

void traveler()
{
	int A[SIZE];
	for (int i=0;i<n;i++)
		A[i]=i;
	while (1){
		update(A);
		int i=n-2;
		while (A[i]>A[i+1] && i>=0)	i--;
		if (i<0)
			return;
		int j=n-1;
		while (A[j]<A[i])	j--;
		swap(A[i],A[j]);
		int d=i+1, c=n-1;
		while (d<c)
			swap(A[d++],A[c--]);
	}
}

void update(int A[])
{
	int sum=0;
	A[n]=A[0];
	for (int i=0;i<n;i++)
		sum+=C[A[i]][A[i+1]];
	if (sum<best)
	{
		best=sum;
		memcpy(p,A,n+1);
	}
}

void swap(int &x, int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}

void nhap(int A[][SIZE], int &n)
{
	FILE *f=fopen(PATH,"r");
	if (f!=NULL)
	{
		fscanf(f,"%d",&n);
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			fscanf(f,"%d",&A[i][j]);
		fclose(f);
	}
}

void xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}
