#include <stdio.h>
#include <string.h>
#define SIZE 100
int max(int x, int y);
void LCS();
void trace();

char A[SIZE], B[SIZE];
int L[SIZE][SIZE]={0}, lenLCS;

int main(){
	gets(A);	gets(B);
	LCS();
	printf("%d\n",lenLCS);
	trace();
	return 0;
}

void LCS(){
	int lenA=strlen(A);
	int lenB=strlen(B);
	for (int i=1;i<=lenA;i++)
		for (int j=1;j<=lenB;j++)
			if (A[i-1]==B[j-1])
				L[i][j]=L[i-1][j-1]+1;
			else L[i][j]=max(L[i-1][j],L[i][j-1]);
	lenLCS=L[lenA][lenB];	
}

int max(int x, int y){
	if (x<y)
		return y;
	else return x;
}

void trace(){
	int i=strlen(A);
	int j=strlen(B);
	char S[SIZE];
	S[L[i][j]]='\0';
	while (L[i][j]){
		if (A[i-1]==B[j-1]){
			S[L[i][j]-1]=A[i-1];
			i--;	j--;
		}else
			if (L[i][j]==L[i-1][j])
				i--;
			else j--;
	}
	puts(S);
}
