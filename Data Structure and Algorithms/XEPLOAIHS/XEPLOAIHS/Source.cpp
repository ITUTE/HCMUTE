#include <iostream>
#include <string.h>
#define SIZE 100
using namespace std;

struct HOCSINH
{
	string Name = "";
	double Toan = 0, Ly = 0, Hoa = 0, Van = 0, Anh = 0, DTB = 0;
	char XepLoai=0;
};

void Nhap(HOCSINH A[], int& n);
void Xuat(HOCSINH A[], int n);
void XepLoai(HOCSINH A[], int n);
void swap(HOCSINH& A, HOCSINH& B);
void QuickSort(HOCSINH A[], int left, int right);
void SortDTB(HOCSINH A[], int n);

int main()
{
	HOCSINH A[SIZE];
	int n;
	Nhap(A, n);
	XepLoai(A, n);
	QuickSort(A, 0, n - 1);
	SortDTB(A, n);
	cout << "-----------------------------------" << endl;
	Xuat(A, n);
	return 0;
}

void Nhap(HOCSINH A[], int& n)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i].Name >> A[i].Toan >> A[i].Ly >> A[i].Hoa >> A[i].Van >> A[i].Anh;
		A[i].DTB = (A[i].Toan + A[i].Hoa + A[i].Ly + A[i].Van + A[i].Anh) / 5;
	}
}

void Xuat(HOCSINH A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i].Name << "\t" << A[i].DTB << "\t" << A[i].XepLoai << endl;
	}
}

void XepLoai(HOCSINH A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (A[i].DTB >= 8.0 && !(A[i].Toan < 7 || A[i].Ly < 7 || A[i].Hoa < 7 || A[i].Anh < 7 || A[i].Van < 7))
			A[i].XepLoai = 'G';
		else if (A[i].DTB >= 7.0 && !(A[i].Toan < 5 || A[i].Ly < 5 || A[i].Hoa < 5 || A[i].Anh < 5 || A[i].Van < 5))
			A[i].XepLoai = 'K';
		else if (A[i].DTB >= 5.0 && !(A[i].Toan < 3 || A[i].Ly < 3 || A[i].Hoa < 3 || A[i].Anh < 3 || A[i].Van < 3))
			A[i].XepLoai = 'T';
		else
			A[i].XepLoai = 'Y';
	}
}

void QuickSort(HOCSINH A[], int left, int right)
{
	if (left <= right)
	{
		int mid = (left + right) / 2;
		int i = left, j = right;
		while (A[i].XepLoai < A[mid].XepLoai)	i++;
		while (A[j].XepLoai > A[mid].XepLoai)	j--;
		if (i <= j)
		{
			swap(A[i], A[j]);
			i++;
			j--;
		}
		if (left < j)	QuickSort(A, left, j);
		if (i < right)	QuickSort(A, i, right);
	}
}

void SortDTB(HOCSINH A[], int n)
{
	int i = 0;
	while (i < n)
	{
		int j = i + 1;
		while (A[j].XepLoai == A[i].XepLoai)	j++;
		for (int ik = i; ik < j - 1; ik++)
			for (int jk = ik + 1; jk < j; jk++)
				if (A[ik].DTB < A[jk].DTB)
					swap(A[ik], A[jk]); 
		i = j;
	}
}

void swap(HOCSINH& A, HOCSINH& B)
{
	HOCSINH tmp = A;
	A = B;
	B = tmp;
}