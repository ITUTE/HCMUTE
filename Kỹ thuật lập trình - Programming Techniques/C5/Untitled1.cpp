#include <stdio.h>

int main(){
	int var=100;
	int &ref=var;
	int var2=1;
	ref=var2;
	printf("%d\n",var);
	printf("%d\n",&var);
	printf("%d\n",ref);
	printf("%d\n",&ref);
	return 0;
}
