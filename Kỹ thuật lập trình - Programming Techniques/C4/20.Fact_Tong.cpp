#include<stdio.h>
#include<conio.h>
void xuLy(int n, int X[], int T[], int i);
void xuat(int X[], int n);
 
 int main()
{
    int n;    scanf("%d", &n);
    int X[n + 1], T[n + 1];
    X[0] = 1; T[0] = 0;
    xuLy(n, X, T, 1); 
    return 0;
}
void xuLy(int n, int X[], int T[], int i)
{
    for(int j = X[i - 1]; j <= (n - T[i - 1]); j++)  // X[i-1] <= X[i] <= n - T[i-1]
    {
        X[i] = j;
        T[i] = T[i - 1] + j;
        if(T[i] == n)
        	xuat(X,i);
        else xuLy(n, X, T, i + 1);
    }
}

void xuat(int X[], int n){
	for(int temp = 1;  temp <= n; temp++)
				printf("%d  ", X[temp]);
            printf("\n");
}
