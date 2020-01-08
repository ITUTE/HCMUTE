#include <stdio.h>
#define oo 100000
#define SIZE 100
void nhap(int A[], int &n);
int CountSubarray(int A[], int n, int P[]);
void TruyVet(int A[], int n, int P[]);
void xuat(int A[], int start, int end);
void MaxSubarray(int A[], int n, int P[]);

int main(){
	int A[SIZE]={0}, n;
	int P[SIZE]={0};
	nhap(A,n);
	int kq=CountSubarray(A,n,P);
	printf("%d\n",kq);
	MaxSubarray(A,n,P);
	//TruyVet(A,n,P);
	return 0;
}

void nhap(int A[], int &n){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

int CountSubarray(int A[], int n, int P[]){
	int i=0, count=0;
	while (i<n){
		if (A[i]<A[i+1]){
			count++;
			P[i]=count;
			int j=i+1;
			while (A[j]>A[j-1]){
				P[j]=count;
				j++;
			}
			i=j;
		}
		else i++;
	}
	return count;
}
void TruyVet(int A[], int n, int P[]){
	int i=0;
	while (i<n){
		if (P[i]){
			while (P[i]==P[i+1]){
				printf("%d ",A[i]);
				i++;
			}
			printf("%d",A[i]);
			i++; printf("\n");
		}else i++;
	}
}

void MaxSubarray(int A[], int n, int P[]){
	int i=0;
	int max=-oo, start=-1, end=-1;
	while (i<n){
		int count=0;
		if (P[i]){
			int j=i;
			while (P[j]==P[j+1]){
				count+=A[j];
				j++;
			}
			count+=A[j];
			if (count>max){
				max=count;
				start=i; end=j;
			}
			i=j+1;
		}else i++;
	}
	printf("%d\n",max);
	xuat(A,start,end);
}

void xuat(int A[], int start, int end){
	for (int i=start;i<=end;i++)
		printf("%d ",A[i]);
	printf("\n");
}
