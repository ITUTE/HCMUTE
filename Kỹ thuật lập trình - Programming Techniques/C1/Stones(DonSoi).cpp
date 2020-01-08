#include <stdio.h>
#include <math.h>
#define SIZE 100

void scanArray(int A[], int n);
void printArray(int A[], int n);
void stones(int A[], int n, int k, int solution[][2], int &nS);
void find(int A[], int n, int &a, int &b);
void xuly(int A[], int a, int b, int solution[][2], int &nS, int value, bool &flag);

int main()
{
	int A[SIZE];
	int n, k;
	scanf("%d%d",&n,&k);
	scanArray(A,n);
	
	int solution[SIZE][2]={0};
	int nS=0;
	stones(A,n,k,solution,nS);
	
	//In ra bang phuong an (step-by-step)
	printf("\n\n");
	for (int i=0;i<nS;i++)
		printf("%d\t%d\n",solution[i][0],solution[i][1]);
	return 0;
}

void find(int A[], int n, int &a, int &b)
{
	/*
	Tim vi tri (a,b) sao cho delta(a,b)=0 hoac delta(a,b) max
	*/
	
	//Khoi tao gia tri ban dau (*)
	a=0, b=0;			
	int delta=0;
	
	//duyet tuyen tinh cac phan tu trong mang A[]
	for (int i=0;i<n-1;i++)
		if (A[i]!=0)						//Bo qua vi tri co gia tri 0	
			for (int j=i+1;j<n;j++)
				if (A[j]!=0)				//Bo qua vi tri co gia tri 0	
				{
					int tmp=abs(A[i]-A[j]);
					if (tmp==0)				//delta(a,b)==0 nen return va ket thuc 
					{
						a=i;
						b=j;
						return;
					}
					else if (tmp>=delta)	//thuat toan tim max(delta)
					{
						a=i;
						b=j;
						delta=tmp;
					}
				}
}

void stones(int A[], int n, int k, int solution[][2], int &nS)
{
	bool flag=true;			//dau hieu ket thuc vong lap while
	int value=pow(2,k);		//value=2^k
	nS=0;					//so luong steps can thuc hien cong viec "don soi"
	int a,b;				//luu vi tri 2 phan tu can "don soi"
	
	//In ra A[] dau tien
	printArray(A,n);
	printf("\n");
	
	//Bat dau thuc hien viec "don soi"
	while (flag==true)
	{
		find(A,n,a,b);		//tim kiem vi tri thoan man DK, luu vao a, b
		
		if (A[a]>=A[b])		//DK if de xac dinh vi tri soi bi giam or tang. Co the bo qua cho code don gian 
			xuly(A,a,b,solution,nS,value,flag);
		else xuly(A,b,a,solution,nS,value,flag);
		
		//In ra mang A[] sau moi step thuc hien
		printArray(A,n);
		printf("\n");
	}
}

void xuly(int A[], int a, int b, int solution[][2], int &nS, int value, bool &flag)
{
	//DK: A[a]>A[b];
	solution[nS][0]=a;		//vi tri phan tu "giam" gia tri
	solution[nS][1]=b;		//vi tri phan tu "tang" gia tri
	nS++;
	
	A[a]-=A[b];
	A[b]*=2;
	
	if (A[b]==value)		//kiem tra DK ket thuc (*)
		flag=false;
}

void scanArray(int A[], int n)
{
	for (int i=0;i<n;i++)
		scanf("%d",&A[i]);
}

void printArray(int A[], int n)
{
	for (int i=0;i<n;i++)
		printf("%d\t",A[i]);
}
