// Tuan03_CL2_CardGame.cpp : Defines the entry point for the console application.
// Chýõng tr?nh cài ð?t tr? chõi bài cào (ð?m nút)

#include "stdafx.h"
#include <time.h>
#include <iostream>
using namespace std;

#define MAX 52

//Khai báo c?u trúc 1 lá bài
typedef struct LABAI {
	int nuoc;		//1: cõ, 2: rô, 3: chu?n, 4: bích
	int nut;		//1 --> 13: 11 = J, 12 = Q, 13 = K
};

//Bi?n toàn c?c
LABAI bobai[52];

//Khai báo các hàm x? l?
//1. T?o b? bài tây g?m 52 lá
void taobobai(LABAI bobai[52]);
//2. Xáo tr?n th? t? trong b? bài (ng?u nhiên)
void xaobai(LABAI bobai[52]);
//3. Chia bài cho n ngý?i chõi, m?i ngý?i c?m k lá bài
void chiabai(LABAI bobai[52], LABAI vanbai[MAX][MAX], int n, int k);
//4. Ð?m nút bài cào: tr? v? s? nút
//0 = bù, 10 = ba tây, 1-9 = s? nút
int demnut(LABAI b1, LABAI b2, LABAI b3);
//5. Xác ð?nh ngý?i chõi th?ng cu?c?
//Tr? v? s? lý?ng ngý?i th?ng cu?c, stt c?a nh?ng ngý?i th?ng, s? nút cao nh?t
int kiemtrathang(LABAI vanbai[MAX][MAX], int n, int thang[], int &sonut);
//6. In b? bài ra màn h?nh ð? quan sát
void inbobai(LABAI bobai[52]);
//7. In thông tin 1 lá bài ra màn h?nh
void inlabai(LABAI b);

int main()
{
	srand(time(NULL));
	taobobai(bobai);
	xaobai(bobai);
	inbobai(bobai);
    return 0;
}

//Ð?nh ngh?a hàm
//1. T?o b? bài tây g?m 52 lá
void taobobai(LABAI bobai[52])
{
	int i = 0;		//s? th? t? t?ng lá trong b? bài
	for (int nt = 1; nt <= 13; nt++)
		for (int nc = 1; nc <= 4; nc++)
		{
			bobai[i].nut = nt;
			bobai[i].nuoc = nc;
			i++;
		}
}
//2. Xáo tr?n th? t? trong b? bài (ng?u nhiên)
//Hàm t?o 1 s? nguyên ng?u nhiên có giá tr? t? 0 ð?n n-1
int random(int n)
{
	if (!n) return 0;		//ch?ng l?i
	return rand() % n;
}

void xaobai(LABAI bobai[52])
{
	int solan = 20 + random(33);		//xào t?i thi?u 20 l?n, t?i ða 52 l?n
	for (int i = 0; i < solan; i++)
	{
		int vt1 = random(52);			//l?y 2 v? trí ng?u nhiên
		int vt2 = random(52);
		LABAI t = bobai[vt1];
		bobai[vt1] = bobai[vt2];
		bobai[vt2] = t;
	}
}

//6. In b? bài ra màn h?nh ð? quan sát
void inbobai(LABAI bobai[52])
{
	for (int i = 0; i < 52; i++) {
		inlabai(bobai[i]);
		cout << endl;
	}
}

//7. In lá bài
void inlabai(LABAI b)
{
	char s[5][10] = { "","co","ro","chuon","bich" };	//m?ng g?m 5 chu?i
	char t[3] = { 'J', 'Q', 'K' };
	if (b.nut == 1)
		cout << "A " << s[b.nuoc];
	else if (b.nut <= 10)
		cout << b.nut << " " << s[b.nuoc];
	else
		cout << t[b.nut-11] << " " << s[b.nuoc];
}


