#include <stdio.h>
#include <string.h>
#define SIZE 1024
int isPalindrome(char s[]);

int main()
{
	char s[SIZE];
	gets(s);
	printf("%d",isPalindrome(s));
	return 0;
}

int isPalindrome(char s[])
{
	int n=strlen(s);
	for (int i=0;i<n/2;i++)
		if (s[i]!=s[n-i-1])
			return 0;
	return 1;
}
