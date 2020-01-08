#include <stdio.h>
#define PATH "GiaiThua.txt"

double GT(int n);				//De quy
void GT(int n, double &kq);		//De quy duoi
void xuatFile(int n);

int main()
{
	int n;	scanf("%d",&n);
	double kq=GT(n);
	//double kq=1;
	//GT(n,kq);
	xuatFile(n);
	return 0;
}

void xuatFile(int n)
{
	FILE *f=fopen(PATH,"wt");
	if (f==NULL)
		return;
	for (int i=0;i<=n;i++)
	{
		double kq=GT(i);
		fprintf(f,"n= %d,	%.0lf\n\n",i,kq);
	}
	fclose(f);
}
double GT(int n)
{
	if (n==0)
		return 1;
	else return n*GT(n-1);
}

void GT(int n, double &kq)
{
	if (n>0)
	{
		kq*=n;
		GT(n-1,kq);
	}
}
