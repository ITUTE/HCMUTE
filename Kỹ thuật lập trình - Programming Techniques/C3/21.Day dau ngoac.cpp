#include <stdio.h>
#include <string.h>
#define SIZE 100

int A[SIZE]={0}, m, n;
int count=0;
void xuat();
void SinhDayDauNgoac();
int thoaDK();
int KQ[SIZE][SIZE];

int main(){
	scanf("%d%d",&m,&n);
	SinhDayDauNgoac();
	xuat();
	return 0;
}

void SinhDayDauNgoac(){
	while (1){
		if (thoaDK()==1){
			count++;
			memcpy(KQ[count],A,sizeof(A));
		}
		int i=m-1;
		while (A[i]==1 && i>=0){
			A[i]=0;
			i--;
		}
		if (i<0)	return;
		A[i]=1;
	}
}
int thoaDK(){
	int c=0, dosau=0;
	for (int i=0;i<m;i++){
		if (A[i]==0){
			c++;
			if (c>dosau) dosau=c;
		}
		else c--;
		if (c<0)	return 0;
	}
	if (c==0 && dosau==n)
		return 1;
	return 0;
}

void xuat(){
	for (int k=1;k<=count;k++){
		for (int i=0;i<m;i++)
			if (KQ[k][i]==0)	printf("(");
			else printf(")");
		printf("\n");
	}
}
