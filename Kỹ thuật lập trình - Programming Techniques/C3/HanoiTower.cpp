#include <stdio.h>
#include <ctime>
#define PATH "HanoiTower.txt"

void HanoiTower(int n, char start, char end, char spare, FILE *f);

int main()
{
	int n;		scanf("%d",&n);
	FILE *f=fopen(PATH,"wt");
	clock_t start = clock();
	HanoiTower(n,'A','C','B',f);
	clock_t finish = clock();
	double duration = (double)(finish - start) / CLOCKS_PER_SEC;
	fprintf(f,"\n%.15lf",duration);
	printf("%lf",duration);
	fclose(f);
	return 0;
}

void HanoiTower(int n, char start, char end, char spare, FILE *f)
{
	if (n>0)
	{
		HanoiTower(n-1,start,spare,end,f);
		fprintf(f,"Move %d from %c to %c\n",n,start,end);
		printf("Move %d from %c to %c\n",n,start,end);
		HanoiTower(n-1,spare,end,start,f);
	}
}
