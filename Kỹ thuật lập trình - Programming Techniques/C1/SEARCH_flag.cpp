//Search, flag
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
#define PATH "array.txt"

void scanArray(int A[], int &n);
void xuatMang(int A[], int n);
int pos(int A[], int n, int key);

int main()
{
	int A[SIZE],n;
	scanArray(A,n);
	int key;
	scanf("%d",&key);
	int p=pos(A,n,key);
	printf("%d",p);
	//xuatMang(A,n);
	return 0;
}

void scanArray(int A[], int &n)
{
	FILE *fi;
	fi=fopen(PATH,"rt");
	if (fi!=NULL)
	{
		fscanf(fi,"%d",&n);
		for (int i=0;i<n;i++)
			fscanf(fi,"%d",&A[i]);
	}
	else
	{
		printf("Khong the doc FILE");
		exit(0);
	}
	fclose(fi);
}

void xuatMang(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

int pos(int A[], int n, int key)
{
	for (int i=0;i<n;i++)
		if (A[i]==key)
			return i;
	return -1;
}
