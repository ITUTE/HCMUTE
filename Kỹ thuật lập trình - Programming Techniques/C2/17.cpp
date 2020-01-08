/* So chu so 0 sau cung cua n! phu thuoc vao so luong so 5 trong phep fact*/

#include <stdio.h>

int lastZero(int n);

int main()
{
	int n;	scanf("%d",&n);
	int kq=lastZero(n);
	printf("%d",kq);
	return 0;
}

int lastZero(int n)
{
	int count=0;
	while (n>=5)
	{
		n/=5;
		count+=n;
	}
	return count;
}
