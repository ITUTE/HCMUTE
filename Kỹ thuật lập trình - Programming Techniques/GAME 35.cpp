#include <stdio.h>
#include <ctime>
#include <cstdlib>
#define SIZE 100

void taoArray(int A[][SIZE]);
int check(int A[][SIZE], int row, int pre);
void luuBang(int A[][SIZE]);
void player(char &you, int value, int &sum);
void bot(int A[][SIZE], char you, int &value, int &sum);
void game(int A[][SIZE]);

int main()
{
	srand(time(NULL));
	int A[SIZE][SIZE]={0};
	taoArray(A);
	//luuBang(A);
	game(A);
	return 0;
}

//Luu bang phuong an de su dung lai (neu can)
void luuBang(int A[][SIZE])
{
	FILE *fo=fopen("table.txt","wt");
	if (fo==NULL)
		exit(0);
	for (int i=0;i<=35;i++)
	{
		fprintf(fo,"%d\t",i);
		for (int j=1;j<=5;j++)
			fprintf(fo,"%d ",A[i][j]);
		fprintf(fo,"\n");
	}
	fclose(fo);
}

//Sinh ra bang phuong an
void taoArray(int A[][SIZE])
{
	for (int i=34;i>=0;i--)
	{
		for (int j=1;j<=5;j++)
			if (i+j<=35 && check(A,i+j,j)==1)
				A[i][j]=1;
	}
}

int check(int A[][SIZE], int row, int pre)
{
	for (int i=1;i<=5;i++)
		if (A[row][i]==1 && i!=pre)
			return 0;
	return 1;
}

void game(int A[][SIZE])
{	
	//-----------------Chon thu tu tro choi---------------------
	char ans;										//Thu tu play
	printf("Do you want to play first? (1/0)\n");	//1. Player; 0. Bot
	do{
		fflush(stdin);
		scanf("%c",&ans);
		if (ans!='0' && ans!='1')
			printf("Nhap lai: ");
	} while (ans!='0' && ans!='1');
	
	fflush(stdin);
	system("cls");									//Xoa man hinh
	
	//------------------Bat dau tro choi----------------------
	
	int sum=0, value=0;
	char you='0';
	
	if (ans=='1')									//Player
		player(you,value,sum);
		
	while (sum<=35)
	{
		bot(A,you,value,sum);
		player(you,value,sum);
	}
}

void bot(int A[][SIZE], char you, int &value, int &sum)
{
	int flag=0;								//De kiem tra xem co phuong an nao tai dong thu A[sum] ko
	for (int i=1;i<=5;i++)
		if (A[sum][i]==1 && i!=you-'0')		//you-'0' de lay gia tri decimal
		{
			flag=1;
			value=i;						//Lay phuong an dau tien (luu y: i!=you-'0')
			break;	
		 } 
		 
	if (flag==0)
		do{
			value=rand()%5 +1;				//random cac so nguyen tu 1--5
		} while (value==you-'0');
		
	sum+=value;
	printf("\nBOT: \t%d\n",value);
	printf("SUM: \t%d\n",sum);
	
	if (sum==35)							//Kiem tra dieu kien dung de thong bao ket qua tro choi
	{
		printf("\n-----YOU LOST-----");
		exit(0);
	}
}

void player(char &you, int value, int &sum)
{
	do{										//Nhap step bat buoc tu '1' -- '5' va khac value cua BOT
		fflush(stdin);
		printf("\nYOU: \t");
		scanf("%c",&you);
		
	} while (you<'1' || you>'5' || you-'0'==value);
	
	sum+=you-'0';
	printf("SUM: \t%d\n",sum);
	
	if (sum>=35)							//Kiem tra dieu kien ket thuc game
	{
		if (sum>35)							//Thong bao won/lost
			printf("\n-----YOU LOST-----");
		else if (sum==35)
			printf("\n-----YOU WON-----");
		exit(0);							//Ket thuc game
	}
}
