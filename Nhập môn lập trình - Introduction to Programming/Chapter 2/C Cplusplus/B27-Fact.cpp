//-----Phan tich Thua so Nguyen to-----

#include <stdio.h>
#include <math.h>
void nhap(int &n);
void fact(int n);

int main()
{
	int n;
	nhap(n);
	fact(n);
	return 0;
}

void nhap(int &n)
{
	scanf("%d", &n);
}

//Nguyen ly: Sang nguyen to Eratosthenes
void fact(int n)
{
	if (n<0)
	{
		n=-n;
		printf("-");
	}
	else if (n==1||n==0)
			printf("%d",n);
		else
		{
			int i=2;
			while (n>1)	//DK stop
			{
				while (n%i==0)
					{
						printf("%d.",i);
						n/=i;
					}
				i++;
			}
		}
}
