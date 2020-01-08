#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define PATH2 "array_2.txt"

void printArray_2(int A[][SIZE], int m, int n);
void draw(int A[][SIZE], int Ndong, int Ncot);

int main()
{
	int A[SIZE][SIZE],m,n;
	scanf("%d%d",&m,&n);
	draw(A,m,n);
	printArray_2(A,m,n);
	return 0;
}

void printArray_2(int A[][SIZE], int m, int n)
{
	FILE *fi=fopen(PATH2,"wt");
	if (fi==NULL)
		exit(0);
	fprintf(fi,"%d %d\n",m,n);
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
			fprintf(fi,"%d\t",A[i][j]);
		fprintf(fi,"\n");
	}
	fclose(fi);
}

void draw(int A[][SIZE], int Ndong, int Ncot)
{
	int i=-1;
	int j=-1;
	int dong=0, cot=0;
	int value=1;
	int max=Ndong*Ncot;
	while (value<=max)
	{
		j++;i++;
		//if (value<=max)
		while (j<Ncot)
			A[i][j++]=value++;
			
		Ncot--;
		i++;j--;
		//if (value<=max)
		while (i<Ndong)
			A[i++][j]=value++;
			
		Ndong--;
		j--;i--;
		if (value<=max)
		while (j>=cot)
			A[i][j--]=value++;
			
		cot++;
		i--;j++;dong++;
		//if (value<=max)
		while (i>=dong)	
			A[i--][j]=value++;
		//dong++;
	}
}
