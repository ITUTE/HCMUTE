//DN SupArray theo de bai: A[i]...A[i+x]
//Liet ke day con A[i]>0 dai nhat

#include <stdio.h>
#define size 100

void nhapMang(int A[], int &n);
void xuatDoanMang(int A[], int start, int end);				//xuat 1 doan trong mang
void listSupArray(int A[], int n, int &start, int &end);
int daySoDuong(int A[], int start, int end);

int main()
{
	int A[size],n,start=0,end=1;
	nhapMang(A,n);
	listSupArray(A,n,start,end);
	xuatDoanMang(A,start,end);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void listSupArray(int A[], int n, int &start, int &end)
{
	int i=0,length=0;
	while (i<n)			//i de xac dinh start
	{
		int j=i+1;		
		while (j<n)		//j de xac dinh end
		{
			if (daySoDuong(A,i,j)&&(j-i>length))
			{
				length=j-i;
				start=i;
				end=j;
			}
			j++;
		}
		i++;
	}
}
/*
A=[1 2 3]
B=[0 1 2 3 4 5 1 2 3 ]
*/
int daySoDuong(int A[], int start, int end)
{
	for (int i=start;i<=end;i++)
		if (A[i]<=0) return 0;
	return 1;
}

void xuatDoanMang(int A[], int start, int end)
{
	for (int i=start;i<=end;i++)
		printf("%d ",A[i]);
}
