#include <stdio.h>

double find(double a);

int main()
{
	double a;	scanf("%lf",&a);
	double kq=find(a);
	printf("%.0lf",kq);
	return 0;
}

double find(double a)
{
	double s=0, i=0;
	while (s<a)
	{
		i++;
		s+=1/i;
	}
	return i;
}
