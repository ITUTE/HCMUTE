#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct QUANBAI
{
	string Name;
	string Loai;
	int Value = 0;
};

string QuanBai[] = { "","A","2","3","4","5","6","7","8","9","10","J","Q","K" };

void KhoiTao(QUANBAI A[], int& n);
void Xuat(QUANBAI A[], int n);
void swap(QUANBAI& A, QUANBAI& B);
void Sort(QUANBAI A[], int n);
void QuickSort(QUANBAI A[], int left, int right);
void SortLoai(QUANBAI A[], int n);
int PhanLoai(string str);
int returnValue(string str);

int main()
{
	int n;
	QUANBAI A[52];
	KhoiTao(A, n);
	cout << "-----------" << endl;
	Sort(A, n);
	Xuat(A, n);
	return 0;
}

void Sort(QUANBAI A[], int n)
{
	QuickSort(A, 0, n - 1);
	SortLoai(A, n);
}

void KhoiTao(QUANBAI A[], int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		
		cin >> A[i].Name;
		cin >> A[i].Loai;
		A[i].Value = returnValue(A[i].Name);
	}
}

void Xuat(QUANBAI A[], int n)
{
	for (int i = 0; i < n; i++)
		cout << A[i].Name << "  " << A[i].Loai << "  " << A[i].Value << endl;
}

void QuickSort(QUANBAI A[], int left, int right) 
{
	if (left > right)
		return;
	int mid = (left + right) / 2;
	int i = left, j = right;
	while (i <= j)
	{
		while (A[i].Value < A[mid].Value)	i++;
		while (A[j].Value > A[mid].Value)	j--;
		if (i <= j)
		{
			swap(A[i], A[j]);
			i++;
			j--;
		}
		if (left < j)	QuickSort(A, left, j);
		if (right > i)	QuickSort(A, i, right);
	}
}

void SortLoai(QUANBAI A[], int n)
{
	int i = 0;
	while (i < n)
	{
		int j = i+1;
		while (A[j].Value == A[i].Value)	j++;
		for (int ik = i; ik < j - 1; ik++)
			for (int jk = i + 1; jk < j; jk++)
				if (PhanLoai(A[ik].Loai) > PhanLoai(A[jk].Loai))
					swap(A[ik], A[jk]);
		i = j;
	}
}

int PhanLoai(string str)
{
	if (str == "B")
		return 1;
	if (str == "Ch")
		return 2;
	if (str == "R")
		return 3;
	if (str == "C")
		return 4;
}

int returnValue(string str)
{
	for (int i = 1; i <= 13; i++)
		if (str == QuanBai[i])
			return i;
	return 0;
}

void swap(QUANBAI& A, QUANBAI& B)
{
	QUANBAI tmp = A;
	A = B;
	B = tmp;
}