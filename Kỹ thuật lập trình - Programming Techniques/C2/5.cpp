#include <stdio.h>

void nhapMang(int *&A, int &n);
void xuatMang(int *A, int n);
int binarySearch(int *A, int L, int R, int x);

int main()
{
	int *A;
	int n;
	nhapMang(A,n);
	//xuatMang(A,n);
	int x;	scanf("%d",&x);
	printf("%d",binarySearch(A,0,n-1,x));
	delete[] A;
	return 0;
}

int binarySearch(int *A, int L, int R, int x)
{
	while (L<=R)
	{
		int mid=L+(R-L)/2;
		if (A[mid]==x)
			return mid;
		if (A[mid]>x)
			R=mid-1;
		else L=mid+1;
	}
	//De quy
	/*if (L>R)	
		return -1;
		
	int mid=L+(R-L)/2;								//tranh tran so (stack overflow)
	if (A[mid]==x)
		return mid;
	else if (A[mid]>x)	
		return binarySearch(A,L,mid-1,x);
	return	binarySearch(A,mid+1,R,x);*/
}

void xuatMang(int *A, int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void nhapMang(int *&A, int &n)
{
	scanf("%d",&n);
	A=new int[n];
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}
