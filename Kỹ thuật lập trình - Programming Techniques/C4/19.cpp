#include <stdio.h>
#include <math.h>
#include <string.h>
void lietke(int n, int x);

int main(){
	int n; scanf("%d",&n);
	for (int i=0;i<pow(2,n);i++)
		lietke(n,i);
	return 0;
}

void lietke(int n, int x){
	int tmp[n]={0};
	int i;
	for (i=0;i<n;i++)
		tmp[i]=(x>>(n-i-1))&0x1;
	int j=0, count=0;
	while (j<n)
		if (tmp[j]==0 && tmp[j+1]==1){
			count++;	j+=2;
		}
		else j++;
	if (count==2){
		for (int k=0;k<n;k++) printf("%d",tmp[k]);
			printf("\n");
	}
}
