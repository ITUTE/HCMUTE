#include <stdio.h>
#define SIZE 128

void xuat(int A[], int n);
void sinhToHop();

int A[SIZE], n,k;

int main()
{
	scanf("%d%d",&n,&k);
	if (k>n)
		return 0;
	//for (int i=0;i<n;i++)
	//	A[i]=i;
	sinhToHop();
	return 0;
}

void sinhToHop(){
	int subA[SIZE]={0};
	for (int i=0;i<k;i++) 	subA[i]=i;
	while (1){
		xuat(subA,k);
		int j=k-1;
		while (subA[j]==n-k+j && j>=0) j--;
		if (j>=0)	subA[j]++;
		else return;
		for (int jj=j+1;jj<k;jj++)
			subA[jj]=subA[jj-1]+1;
	}
}

void xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
	printf("\n");
}
