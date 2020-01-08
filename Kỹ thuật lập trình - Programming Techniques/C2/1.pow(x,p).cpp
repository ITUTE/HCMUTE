#include <stdio.h>

double power(float x, int p);

int main(){
    float x;	scanf("%f",&x);
    int p;		scanf("%d",&p);
    double kq=power(x,p);
    printf("%.16lf\n",kq);
    return 0;
}

double power(float x, int p)
{
	if (p<0)
		return 1/power(x,-p);
	if (p==0)
		return 1;
	if (p==1)
		return x;
	/*p>1*/
	double tmp=power(x,p/2);
	if (p%2)
		return x*tmp*tmp;
	//p%2==0
	return tmp*tmp;
}
