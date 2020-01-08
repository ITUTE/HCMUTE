#include <stdio.h>
#include <math.h>

//TAMGIAC voi a,b,c la do dai 3 canh

struct TAMGIAC
{
	float a;
	float b;
	float c;
};

void nhap(TAMGIAC &A);
void xuat(TAMGIAC A);
float chuVi(TAMGIAC A);
float dienTich(TAMGIAC A);

int main()
{
	TAMGIAC A;
	nhap(A);
	//xuat(A);
	printf("%f",dienTich(A));
	return 0;
}

void nhap(TAMGIAC &A)
{
	float t;
	scanf("%f",&t);
	A.a=t;
	scanf("%f",&t);
	A.b=t;
	scanf("%f",&t);
	A.c=t;
}

void xuat(TAMGIAC A)
{
	printf("%.2f \t %.2f \t %.2f",A.a,A.b,A.c);
}

float chuVi(TAMGIAC A)
{
	return (A.a+A.b+A.c);
}

float dienTich(TAMGIAC A)
{
	float p=chuVi(A)*0.5;
	float t=p*(p-A.a)*(p-A.b)*(p-A.c);
	return sqrt(t);
}
