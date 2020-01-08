#include <stdio.h>
#include <math.h>

struct DIEM
{
	float x;
	float y;
};

void nhap(DIEM &A);
float k_cach(DIEM A, DIEM B);
DIEM O_dx(DIEM A);
DIEM Ox_dx(DIEM A);
DIEM Oy_dx(DIEM A);
int kiemtra(DIEM A);

int main()
{
	DIEM A,B;
	nhap(A);
	nhap(B);
	printf("%d",kiemtra(A));
	return 0;
}

void nhap(DIEM &A)
{
	float t;
	scanf("%f",&t);
	A.x=t;
	scanf("%f",&t);
	A.y=t;
}

float k_cach(DIEM A, DIEM B)
{
	float d=pow(A.x-B.x,2)+pow(A.y-B.y,2);
	return sqrt(d);
}

DIEM O_dx(DIEM A)
{
	DIEM Z;
	Z.x=-A.x;
	Z.y=-A.y;
	return Z;
}

DIEM Oy_dx(DIEM A)
{
	DIEM Z=A;
	Z.x=-Z.x;
	return Z;
}

DIEM Ox_dx(DIEM A)
{
	DIEM Z=A;
	Z.y=-Z.y;
	return Z;
}

int kiemtra(DIEM A)
{
	if (A.x>=0)
		if (A.y>=0)
			return 1;
		else return 4;
	else
		if (A.y>=0)
			return 2;
		else return 3;
}
