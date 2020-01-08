#include <stdio.h>
#include <string.h>
#define SIZE 100
char A[SIZE],	B[SIZE],	S[SIZE];
int L[SIZE][SIZE]={0};
void Len_LCS(){
	int nA=strlen(A), nB=strlen(B);
	for (int i=1;i<=nA;i++)
		for (int j=1;j<=nB;j++)
			if (A[i-1]==B[j-1])
				L[i][j]=L[i-1][j-1]+1;
			else
				if (L[i-1][j]>L[i][j-1])
					L[i][j]=L[i-1][j];
				else L[i][j]=L[i][j-1];
}
 
void Trace(){
	int i=strlen(A),	j=strlen(B);
	S[L[i][j]]='\0';
	while (L[i][j]){
		if (A[i-1]==B[j-1]){
			S[L[i][j]-1]=A[i-1];
			i--;	j--;
		}else
			if (L[i-1][j]==L[i][j])
				i--;
			else j--;
	}
}

int main(){
	gets(A);	gets(B);
	Len_LCS();
	Trace();
	printf("%s",S);
	return 0;
}
