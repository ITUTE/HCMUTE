#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int A[SIZE]={0};	//A[i]=x cho biet queen hang i dat o cot x
int n;

void Queen(int x);
void xuat(int A[], int n);
void xuatBanCo(int A[], int n);
int kiemtra(int x, int col);

int main(){
	scanf("%d",&n);
	Queen(0);
	return 0;
}

void Queen(int x){
	if (x==n){
		xuatBanCo(A,n);
		//exit(0);
	}else{
		//tim vi tri dat quan co thu x (hang x)
		for (int col=0;col<n;col++)
			if (kiemtra(x,col)){
				A[x]=col;		//Con co thu x di vao hang x, col=i
				Queen(x+1);		//De quy tim vi tri dat con co tiep theo
				A[x]=0;			//Backtrack
			}
	}
}
//kiem tra xem cot col co the dat quan co thu x ko?
int kiemtra(int x, int col){
	//duyet tat ca cac vi tri dat queen truoc do
	for (int i=0;i<x;i++)
		//kiem tra (x,col) so voi cac vi tri dat queen truoc do (A[i])
		if (col==A[i] || x-col==i-A[i] || x+col==i+A[i])
			return 0;
	return 1;
}
void xuat(int A[], int n){
	printf("\n");
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}
void xuatBanCo(int A[], int n)
{
	printf("\n");
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)
			if (A[i]==j)
				printf("  1  ");
			else printf("  0  ");
		printf("\n");
	}
}
