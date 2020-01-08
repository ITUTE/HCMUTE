#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
#define oo 100000
#define PATH "Hugo.txt"

void nhap();
int getbit(int x, int k);
void move(int &x, int &y, int k);
void Hugo(int &i, int &j);
void TruyVet();
int A[SIZE][SIZE]={0}, P[SIZE]={0}, tmp[SIZE]={0};
int m, n, x, y, count=0, min=oo;

int main(){
	nhap();
	int i=x, j=y;
	Hugo(i,j);
	printf("%d\n",min);
	TruyVet();
	return 0;
}

void nhap(){
	FILE *f=fopen(PATH,"r");
	if (f==NULL)
		exit(0);
	fscanf(f,"%d%d",&m,&n);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			fscanf(f,"%d",&A[i][j]);
	fscanf(f,"%d%d",&x,&y);
	fclose(f);
}

void Hugo(int &i, int &j){
	if (A[i][j]){
		int k;
		for (k=0;k<8;k++)
			if (getbit(A[i][j],k)){
				count++;
				if (count<min){
					tmp[count]=k;
					move(i,j,k);
					Hugo(i,j);
					i=-i; j=-j;
					move(i,j,k);
					i=-i; j=-j;
				}
				count--;
			}
	}
	else if (min>count && count>0){
		min=count;
		memcpy(P,tmp,sizeof(tmp));
	}
}

int getbit(int x, int k){
	return (x>>k) & 0x1;
}

void move(int &x, int &y, int k){
	int X[]={-1, -1, 0, 1, 1, 1, 0, -1};
	int Y[]={ 0,  1, 1, 1, 0,-1,-1, -1};
	x+=X[k];	y+=Y[k];
}

void TruyVet(){
	for (int i=1;i<=min;i++)
		printf("%d ",P[i]);
	printf("\n");
	for (int i=1;i<=min;i++){
		printf("%d\t%d\n",x,y);
		move(x,y,P[i]);
	}
}
