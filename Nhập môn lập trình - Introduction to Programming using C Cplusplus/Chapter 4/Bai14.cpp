#include <stdio.h>
#define size 32000

void nhapMang(int A[], int &n);
void xuly(int A[], int tansuat[], int n);
void xuat(int A[], int tansuat[], int n);

int main()
{
	int A[size],tansuat[size],n;
	nhapMang(A,n);
	xuly(A,tansuat,n);
	xuat(A,tansuat,n);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void xuly(int A[], int tansuat[], int n)
{
	int i,flag[size];
	//Khoi tao mang flag[i] dung de xet xem da duyet qua phan tu A[i] chua
	for (i=0;i<n;i++)
		flag[i]=0;
	
	//Dem so lan xuat hien
	for (i=0;i<n;i++)
	{
		if (flag[i]==0)							//KT xem da duyet qua A[i] hay chua
		{
			int count=1;
			for (int j=i+1;j<n;j++)
				if ((A[j]==A[i])&&(flag[j]==0))
				{
					count++;
					flag[j]=-1;					//Danh dau da duyet qua
				}
			tansuat[i]=count;					//So lan xuat hien, nhung phan tu da duyet qua thi tansuat[i]=0
		}
	}
}

void xuat(int A[], int tansuat[], int n)
{
	for (int i=0;i<n;i++)
		if (tansuat[i]>0)
			printf("%d\t%d\n",A[i],tansuat[i]);
}
