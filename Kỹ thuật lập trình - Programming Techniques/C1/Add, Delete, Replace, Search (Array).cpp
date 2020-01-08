#include <stdio.h>
#include <string.h>
#define PATH "array.txt"

void nhapMang(int *&A, int &n);
void add(int *&A, int &n, int pos, int value);
void del(int *&A, int &n, int pos);
void replace(int *&A, int n, int pos, int value);
int search(int *A, int n, int value);
void xuatMang(int *A, int n);

int main()
{
	int *A;
	int n;
	nhapMang(A,n);
	//add(A,n,4,-1);
	//del(A,n,19);
	//replace(A,n,0,-1);
	//printf("%d",search(A,n,20));
	//xuatMang(A,n);
	delete[] A;
	return 0;
}

int search(int *A, int n, int value)
{
	A[n]=value;
	int i=0;
	while (A[i]!=value)	i++;
	if (i==n)
		return -1;
	return i;
}

void replace(int *&A, int n, int pos, int value)
{
	if (pos>=0 && pos<n)
		A[pos]=value;
}

void add(int *&A, int &n, int pos, int value)
{
	if (pos>=0 && pos <=n){
		memmove(A+pos+1,A+pos,n-pos);
		A[pos]=value;
	}
}

void del(int *&A, int &n, int pos)
{
	if (pos<n){
		memmove(A+pos,A+pos+1,n-pos);
		n--;
	}
}

void xuatMang(int *A, int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void nhapMang(int *&A, int &n)
{
	FILE *f=fopen(PATH,"r");
	if (f!=NULL)
	{
		fscanf(f,"%d",&n);
		A=new int[n];
		for (int i=0;i<n;i++)
			fscanf(f,"%d",&A[i]);
		fclose(f);
	}
}
