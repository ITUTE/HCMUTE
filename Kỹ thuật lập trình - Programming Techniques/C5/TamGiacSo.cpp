#include <stdio.h>
#define PATH "TamGiacSo.txt"
#define SIZE 100

int A[SIZE][SIZE]={0}, M[SIZE][SIZE]={0}, n;
void TamGiacSo();
int pos_Max(int A[], int n);
void nhap();
void xuat();
void xuatKQ();

int main(){
	nhap();
	TamGiacSo();
	xuat();
	xuatKQ();
	return 0;
}

void nhap(){
	FILE *f=fopen(PATH,"r");
	if (f==NULL)
		return;
	fscanf(f,"%d",&n);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			fscanf(f,"%d",&A[i][j]);
	fclose(f);
}
void TamGiacSo(){
	M[0][0]=A[0][0];
	for (int i=1;i<n;i++)
		for (int j=0;j<n;j++)
			if (j==0)
				M[i][j]=A[i][j]+M[i-1][j];
			else if (j==i)
				M[i][j]=A[i][j]+M[i-1][j-1];
			else{
				if (M[i-1][j-1]>M[i-1][j])
					M[i][j]=A[i][j]+M[i-1][j-1];
				else M[i][j]=A[i][j]+M[i-1][j];
			}
}
void xuat(){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++)
			printf("%d\t",M[i][j]);
		printf("\n");
	}
	printf("\n");
}
void xuatKQ(){
	int i=0, j=0;
	while (i<n){
		printf("%d",A[i][j]);
		i++;
		if (i<n)	printf(" >>  ");
		if (M[i+1][j+1]>M[i+1][j])
			j++;
	}
	printf("\nMAX = %d",M[i-1][j]);
}
int pos_Max(int A[], int n){
	int max=A[0], pos=0;
	for (int i=1;i<n;i++)
		if (A[i]>max){
			max=A[i];
			pos=i;
		}
	return pos;
}
