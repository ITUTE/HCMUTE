// Tuan06_CL2_MineSweeper.cpp : Defines the entry point for the console application.
// H? và tên: Nguy?n Vãn A
// MSSV: 15110001
// Chýõng tr?nh 1: Tr? chõi MINESWEEPER

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <time.h>

#define MAX 20

//Khai báo hàm
//2. In ma tr?n (kích thý?c dxc)
void inmt(int a[][MAX], int d, int c);
//Hàm phát sinh s? ng?u nhiên t? 0 ð?n n-1
int random(int n)
{
	int a = rand();
	return a%n;
}
//Hàm ð?t nh?ng qu? m?n vào v? trí ng?u nhiên trong b?i m?n
void datmin(int a[][MAX], int n, int somin);
//Hàm tính toán giá tr? các ô c?n l?i trong b?i m?n
void tinhsomin(int a[][MAX], int n);
//6.Vi?t hàm t?m v? trí c?a ô xung quanh có nhi?u m?n nh?t
//tr? v? s? m?n nhi?u nh?t
//các tham s? d và c lýu d?ng,c?t c?a ô t?m ðý?c
int timmax(int a[][MAX], int n, int &d, int &c);
//7*.Vi?t hàm t?m vùng kxk có ít m?n nh?t (k cho trý?c)
int timmin(int a[][MAX], int n, int k, int &d, int &c);
//8**.Vi?t hàm cho bi?t vùng ch?a nh?ng s? 0 li?n k? l?n
//nh?t g?m bao nhiêu ô.
int timvung0(int a[][MAX], int n);

int main()
{
	int a[MAX][MAX];		//"b?i m?n"
	int n;					//kích thý?c
	int somin;				//s? m?n

	srand(time(NULL));
	//nh?p kích thý?c (>=5 và <=MAX)
	do {
		cout << "Nhap kich thuoc (tu 5 den " <<MAX <<"):";
		cin >> n;
	} while (n<5 || n>MAX);
	//nh?p s? m?n (<=1/4 s? ô)
	do {
		cout << "Nhap kich thuoc (tu 1 den " << n*n/4 << "):";
		cin >> somin;
	} while (somin<1 || somin>n*n/4);
	datmin(a, n, somin);
	tinhsomin(a, n);
	inmt(a, n, n);
	//t?m vùng có ít m?n nh?t
	int d, c;
	int m = timmin(a, n, 4, d, c);
	cout << m << endl << "(" << d << "," << c << ")" << endl;
	cout << timvung0(a, n) << endl;
    return 0;
}

//2. In ma tr?n (kích thý?c dxc)
void inmt(int a[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			cout.width(5);		//gióng th?ng c?t
			cout << a[i][j];
		}
		cout << endl;			//h?t 1 d?ng c?a ma tr?n
	}
}

//Hàm ð?t nh?ng qu? m?n vào v? trí ng?u nhiên trong b?i m?n
void datmin(int a[][MAX], int n, int somin)
{
	int i, j;
	//kh?i gán
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;
	//ð?t m?n
	while (somin > 0) {
		i = random(n);
		j = random(n);
		if (a[i][j] == 0) {
			a[i][j] = -1;
			somin--;
		}
	}
}

//Hàm tính toán giá tr? các ô c?n l?i trong b?i m?n
void tinhsomin(int a[][MAX], int n)
{
	int i, j, k, l, dem;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] == 0)			//ch? xét nh?ng ô ko có m?n
			{
				dem = 0;
				for (k = i - 1; k <= i + 1; k++)
					for (l = j - 1; l <= j + 1; l++)
						if (k >= 0 && k < n && l >= 0 && l < n &&
							(k != i || l != j) && a[k][l] == -1)
							dem++;
				a[i][j] = dem;		//lýu l?i s? m?n xung quanh
			}
}

//6.Vi?t hàm t?m v? trí c?a ô xung quanh có nhi?u m?n nh?t
//tr? v? s? m?n nhi?u nh?t
//các tham s? d và c lýu d?ng,c?t c?a ô t?m ðý?c
int timmax(int a[][MAX], int n, int &d, int &c)
{
	int max = a[0][0];
	d = c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (max < a[i][j]) {
				max = a[i][j];
				d = i;
				c = j;
			}
	return max;
}
//7*.Vi?t hàm t?m vùng kxk có ít m?n nh?t (k cho trý?c)
int timmin(int a[][MAX], int n, int k, int &d, int &c) {
	int i, j, dem, l, m;
	int min = k*k;
	d = c = 0;						//c?p nh?t l?i sau
	if (k<0 || k>n) return -1;		//l?i, ko h?p l?
	for (i = 0; i <= n - k; i++)	//duy?t t?t c? các kh?i kxk
		for (j = 0; j <= n - k; j++)
		{
			//b?t ð?u ð?m s? m?n trong vùng kxk, góc trái trên (i,j)
			dem = 0;
			for (l = 0; l < k; l++)
				for (m = 0; m < k; m++)
					if (a[i + l][j + m] == -1) dem++;
			if (dem < min) {
				min = dem;
				d = i;
				c = j;
			}
		}
	return min;
}
//8**.Vi?t hàm cho bi?t vùng ch?a nh?ng s? 0 li?n k? l?n
//nh?t g?m bao nhiêu ô.
//B? túc: Hàm ð? quy dùng ð? loang trên ma tr?n
int dem0(int a[][MAX], int n, int d, int c) {
	int plus = 0;
	int count = 0;
	if (a[d][c] == 0) {
		plus = 1;
		a[d][c] = -2;
	}
	//xét 8 ô xung quanh ô (d,c)
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (a[d + i][c + j] == 0)		//n?u là s? 0 th? g?i ð? quy ð? loang
				count = dem0(a, n, d + i, c + j);
	return count + plus;
}

int timvung0(int a[][MAX], int n)
{
	int max = 0;
	int temp = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0)
				temp = dem0(a, n, i, j);
			if (max < temp) max = temp;
		}
	return max;
}
