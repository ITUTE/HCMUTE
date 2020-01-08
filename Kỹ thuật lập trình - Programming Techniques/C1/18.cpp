#include <stdio.h>
#include <windows.h>
#define PATH "array_2.txt"
#define SIZE 128

void nhapMang(int A[][SIZE], int &m, int &n);
void loang(int A[][SIZE], int row, int col);

int main()
{
	int A[SIZE][SIZE];	int m,n;
	nhapMang(A,m,n);
	loang(A,2,2);
	return 0;
}

void nhapMang(int A[][SIZE], int &m, int &n)
{
	FILE *f=fopen(PATH,"r");
	if (f!=NULL)
	{
		fscanf(f,"%d%d",&m,&n);
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++)
				fscanf(f,"%d",&A[i][j]);
		fclose(f);
	}
}

void loang(int A[][SIZE], int row, int col)
{
	int X[]={-1,0,1};
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++){
			int x=row+X[i], y=col+X[j];
			if (A[x][y]==0){
				Sleep(500);
				printf("%d	%d\n",x,y);
				A[x][y]=-2;				//flag
				loang(A,x,y);
			}
		}
}
