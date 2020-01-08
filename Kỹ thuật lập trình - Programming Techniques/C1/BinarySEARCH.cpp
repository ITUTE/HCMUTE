//Binary search

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define PATH "array.txt"

void scanArray(int A[], int &n);
int pos_BinarySearch(int A[], int n, int key);

int main()
{
	int A[SIZE],n;
	scanArray(A,n);
	int key;
	scanf("%d",&key);
	int pos=pos_BinarySearch(A,n,key);
	printf("%d",pos);
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

int pos_BinarySearch(int A[], int n, int key)
{
	int left=0;
	int right=n-1;
	int mid=(left+right)/2;
	while (left<=right)
	{
		if (A[mid]==key)
			return mid;
		else if (A[mid]<key)
			left=mid;
		else right=mid;
		mid=(left+right)/2;
	}
}
