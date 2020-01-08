#include <stdio.h>
#define SIZE 128
#define PATH "ways.txt"
void nhap();
void xuat(int A[], int n);
void update();
void branchBound(int xi);
int n,	fee=0,	bestSolution=1000000;	//+vocung
int A[SIZE][SIZE]={0};	//bang price
int p[SIZE]={0};		//duong di hien tai
int best[SIZE]={0};		//duong di can in ra
bool flag[SIZE]={0};	//kim tra da di qua hay chua?

int main()
{
	nhap();
	p[0]=0;	p[n]=0;
	flag[0]=1;
	branchBound(1);
	xuat(best,n+1);
	printf("\n%d",bestSolution);
	return 0;
}

void nhap()
{
	FILE *f=fopen(PATH,"r");
	if (f!=NULL)
	{
		fscanf(f,"%d",&n);
		for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			fscanf(f,"%d",&A[i][j]);
		fclose(f);
	}
}

void branchBound(int xi)
{
	if (fee>=bestSolution)				//nhanh-can
		return;
	for (int i=0;i<n;i++)
		if (flag[i]==0)
		{
			p[xi]=i;
			flag[i]=1;
			fee+=A[p[xi-1]][p[xi]];
			if (xi==n-1)				//da di qua tat ca thanh pho
				update();				//kiem tra xem day co phai duong di toi uu nhat
			else branchBound(xi+1);
			//Quay lui
			flag[i]=0;
			fee-=A[p[xi-1]][p[xi]];
		}
}

void update()
{
	if (fee+A[p[n-1]][p[0]]<bestSolution)
	{
		bestSolution=fee+A[p[n-1]][p[0]];
		for (int i=0;i<=n;i++)
			best[i]=p[i];
	}
}

void xuat(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}
