// Tuan08_CL2_QuayLui.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX 6
//Ki?u d? li?u bi?u di?n 1 v? trí trong ma tr?n
//g?m 2 thành ph?n (d?ng,c?t)
struct POS {
	int row, col;
};

//Các bi?n toàn c?c
//Ma tr?n ð?u vào
int a[MAX][MAX] = {
	{ 1,0,1,1,0,0 },
	{ 0,1,0,1,0,0 },
	{ 0,1,0,1,1,0 },
	{ 1,0,0,0,1,1 },
	{ 0,1,1,1,0,0 },
	{ 1,0,0,0,1,1 },
};
//M?ng ð? ðánh d?u nh?ng ô ð? duy?t qua r?i (tránh l?p)
int mark[MAX][MAX];
//C?p c?a ma tr?n
int n = 6;

POS kq[100];		//m?ng lýu ðý?ng ði hi?n t?i
POS minpath[100];	//lýu ðý?ng ði ng?n nh?t
int nk = 0;			//ð? dài ðý?ng ði hi?n t?i
int minn = n*n;		//ð? dài ðý?ng ði ng?n nh?t

//M?t s? hàm x? l?
//1. Ki?m tra xem ð? ð?n ðích hay chýa
int check(POS cur, int dir) {
	switch (dir) {
	case 0:	if (cur.col == 0) return 1; break;//left
	case 1:	if (!cur.row) return 1; break;//top
	case 2:	if (cur.col == n - 1) return 1; break;//right
	case 3:	if (cur.row == n - 1) return 1; break;//bottom
	}
	return 0;
}
//2. Kh?i t?o toàn b? m?ng mark b?ng 0
void initmark() {
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			mark[i][j] = 0;
}

//3. Gi?i thu?t ð? quy và quay lui ð? t?m ðý?ng ði
void findpath2(POS cur, int dir)
{
	if (check(cur, dir)) //ð? ði ðý?c ð?n ðích th? in kq
	{
		cout << "Tim duoc duong di:\n";
		for (int i = 0; i<nk; i++)
			cout << "(" << kq[i].row << "," << kq[i].col << ")-->";
		cout << "end\n";
		//1. Lýu l?i ðý?ng ði ng?n nh?t
		//if (nk<minn) {
		//	minn = nk;
		//	//memcpy(minpath,kq,nk*sizeof(POS));
		//	for (int i=0; i<nk; i++)
		//		minpath[i] = kq[i];
		//}
	}
	//Th? 8 ô xung quanh ô ðang ð?ng, xem có ði ðý?c ti?p ko
	for (int i = 1; i >= -1; i--)
		for (int j = 1; j >= -1; j--)
			if ((i || j) && cur.row + i >= 0 && cur.row + i<n
				&& cur.col + j >= 0 && cur.col + j<n) {
				POS p;						//lýu ô ti?p theo có th? ði
				p.row = cur.row + i;
				p.col = cur.col + j;
				if (a[p.row][p.col] == a[cur.row][cur.col] &&
					!mark[p.row][p.col]) {	//chýa ði và ði ðý?c
					mark[p.row][p.col] = 1; //ðánh d?u là ð? ði qua
					kq[nk++] = p;
					findpath2(p, dir);		//ð? quy ð? ti?p t?c t?m ðý?ng
					nk--;					//quay lui, h?y ðý?ng ði th?
					mark[p.row][p.col] = 0; //h?y ðánh d?u
				}
			}
}

int main()
{
	initmark();		//kh?i t?o ma tr?n ðánh d?u
					
	POS start;		//v? trí xu?t phát (ô 2,2)
	start.row = 2;
	start.col = 2;
	mark[start.row][start.col] = 1;	//ðánh d?u ð? duy?t
	kq[nk++] = start;
	findpath2(start, 1);	//lên c?nh trên c?a ma tr?n
    return 0;
}


