/*
	Xoa phan tu co f>1
*/

#include <stdio.h>
#define size 320000

void nhapMang(int A[], int &n);
void del_element(int A[], int &n, int pos);
void del_trung(int A[], int &n);
void xuatMang(int A[], int n);

int main()
{
	int A[size];
	int n;
	nhapMang(A,n);
	del_trung(A,n);
	xuatMang(A,n);
	return 0;
}

void nhapMang(int A[], int &n)
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void xuatMang(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d ",A[i]);
}

void del_element(int A[], int &n, int pos)
{
	for (int i=pos;i<n-1;i++)
		A[i]=A[i+1];
	n--;								//Giam 1 phan tu, vi da xoa 1 phan tu khoi A[]
}

void del_trung(int A[], int &n)
{
	int i=0, flag;
	while (i<n)
	{
		int j=i+1;	
		flag=0;							//Duyet cac phan tu sau A[i], so sanh A[i] voi cac phan tu dung sau no
		while (j<n)						//Khi chua den cuoi mang A[]
		{
			if (A[j]==A[i])				//Tim thay phan tu trung nhau
			{
				flag=1;
				del_element(A,n,j);		/*Xoa phan tu trung nhau phia sau A[i], khong co i++ vi sau khi xoa, A[j] thay doi gia tri, nen can KT lai*/
			}	
			else
				j++;
		}
		if (flag==1) del_element(A,n,i);
		else i++;
	}
}
