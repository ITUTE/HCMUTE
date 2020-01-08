#include <stdio.h>
#include <string.h>
#define SIZE 20

void nhapMang();
void sinh_HoanVi();
void xuat(int A[]);
void swap(int &x, int &y);

char value[SIZE];
int n;

int main()
{
	gets(value);
	n=strlen(value);
	sinh_HoanVi();
	return 0;
}

void sinh_HoanVi()
{
	int A[SIZE];
	for (int i=0;i<n;i++)
		A[i]=i;
	while (1){
		xuat(A);
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

void swap(int &x, int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}

void xuat(int A[])
{
	for (int i=0;i<n;i++)
		printf("%c ",value[A[i]]);
	printf("\n");
}
