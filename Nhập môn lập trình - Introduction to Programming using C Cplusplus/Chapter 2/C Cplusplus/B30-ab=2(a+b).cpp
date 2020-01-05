#include <stdio.h>

char isOK(char n);
void list();

int main()
{
	list();
	return 0;
}

char isOK(char n)
{
	char a=n/10;
	char b=n%10;
	if (a*b==2*(a+b))
		return 1;
	else return 0;
}

void list()
{
	for (char i=10;i<100;i++)
		if (isOK(i)) printf("%d ",i);
}
