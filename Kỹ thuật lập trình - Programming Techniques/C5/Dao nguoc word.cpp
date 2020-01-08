#include <stdio.h>
#include <string.h>
void daoNguoc(char S[]);

int main(){
	char S[100];
	gets(S);
	daoNguoc(S);
	puts(S);
	return 0;
}

void daoNguoc(char S[]){
	int len=strlen(S);
	int i=0;
	while (i<len){
		while (S[i]==' ') i++;
		int j=i;
		while (S[j]>' ') j++;
		for (int k=0;k<(j-i)/2;k++){
			char tmp=S[i+k];
			S[i+k]=S[j-1-k];
			S[j-1-k]=tmp;
		}
		i=j;
	}
}
