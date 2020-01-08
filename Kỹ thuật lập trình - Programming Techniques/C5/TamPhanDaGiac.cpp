#include <stdio.h>
#include <math.h>
#define SIZE 100

struct OXY{
	double x,y;
};
int n;
OXY A[SIZE];
double F[SIZE][SIZE]={0};
double DoDai(OXY A, OXY B);

int main(){
	nhap();
	return 0;
}

void nhap(){
	double x,y;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%ld%ld",&x,&y);
		A[i].x=x;
		A[i].y=y;
	}
}

void TamPhanDaGiac(){
	
}

double DoDai(OXY A, OXY B){
	return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
}
