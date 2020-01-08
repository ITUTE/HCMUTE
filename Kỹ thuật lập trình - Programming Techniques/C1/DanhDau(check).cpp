#include <stdio.h>
#include <string.h>
#define SIZE 100
#define delimits " 	"

void player(int A[], int n, int you[], int &nYou, int &count);
void bot(int A[], int n, int you[], int &nYou, int &count);
void game();

int main()
{
	game();
	return 0;
}

void game()
{
	int A[SIZE]={0};
	int you[SIZE]={0};
	int n=10, nYou=0, count=0;
	while (count<=n)
	{
		if (count==n)
			printf("\n\n\t\tYOU LOST");
		printf("\n\nYOU:\n");
		player(A,n,you,nYou,count);
		for (int i=0;i<n;i++)
			printf("%d ",A[i]);
		printf("\n\nBOT:\n");
		bot(A,n,you,nYou,count);
		for (int i=0;i<n;i++)
			printf("%d ",A[i]);
	}
}

void player(int A[], int n, int you[], int &nYou, int &count)
{
	char S[SIZE];
	gets(S);
	char *tmp;
	tmp=strtok(S,delimits);
	nYou=0;
	while (tmp!=NULL)
	{
		int len=strlen(tmp);
		int s=0;
		for (int i=0;i<len;i++)
			s=10*s+(tmp[i]-'0');
		if (count>=n || A[s]==1)
			player(A,n,you,nYou,count);
		you[nYou++]=s;
		tmp=strtok(NULL,delimits);
	}
	for (int i=0;i<nYou;i++)
	{
		A[you[i]]=1;
		count++;
	}
}

void bot(int A[], int n, int you[], int &nYou, int &count)
{
	for (int i=0;i<nYou;i++)
	{
		A[n-you[i]-1]=1;
		count++;
	}
}


