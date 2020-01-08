#include<stdio.h>
#include <stdlib.h>
#define PATH "Knight_s Tour 2.txt"
#define SIZE 8

int A[SIZE][SIZE] = { 0 };
int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
int dem = 1;

void xuat();
void fill();
void MaDiTuan(int x, int y);
int kiemtra(int x, int y);
int n;
 
int main() 
 {
 	scanf("%d",&n);
 	int x, y;
 	scanf("%d%d",&x,&y);
 	A[x][y]=1;
 	MaDiTuan(x,y);
    /*for (int i=0;i<n;i++)
	    for (int j=0;j<n;j++)
	    {
	    	fill();
	    	A[i][j]=1;
	    	MaDiTuan(i,j);
		}
	*/
    return 0;
}

void fill()
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			A[i][j]=0;
}

void xuat()
{
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d\t", A[i][j]);
        printf("\n");
    }
    /*
	FILE *f=fopen(PATH,"a");
	if (f==NULL)
		exit(0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            fprintf(f,"%d\t", A[i][j]);
        fprintf(f,"\n");
    }
    fprintf(f,"\n");
    fclose(f);
    */
}
 
void MaDiTuan(int x, int y)
{
    for (int i=0;i<8;i++)
    {
    	int u=x+X[i], v=y+Y[i];
    	if (kiemtra(u,v)==1 && A[u][v]==0)
    	{
    		A[u][v]=++dem;
    		if (dem==n*n){
    			xuat();
    			exit(0);
			}
			else MaDiTuan(u,v);
			A[u][v]=0;
			dem--;
		}
	}
}

int kiemtra(int x, int y)
{
	if (x>=0 && y>=0 && x<n && y<n)
		return 1;
	return 0;
}
