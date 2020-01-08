#include <stdio.h>
#include <string.h>
#include <math.h>
#define SIZE 1024

struct SNL{
	int sign;
	char value[SIZE];									//chuoi value duoc in nguoc
};

void str_convert(SNL &num, char S[SIZE]);				//Chuyen string ki tu thong thuong sang kieu du lieu SNL (BigNum)
void Cong(SNL n1, SNL n2, SNL &result);					//Cong 2 so (co xem xet den sign cua moi so)
void Cong_unsigned(SNL num1, SNL num2, SNL &result);		//Cong 2 so do dai (length) = nhau
void insert(char S[], int pos, int n, char ch);			//Chen vao S[] bat dau tu vi tri pos, them n ki tu /ch/
void prepare(SNL &num1, SNL &num2);						//Them so 0 va reverse
void xuatSNL(SNL num);									//Xuat ra so BigNum
void Tru_unsigned(SNL num1, SNL num2, SNL &result);		//Tru 2 so voi a>b co do dai (length) = nhau
void Tru(SNL n1, SNL n2, SNL &result);				//Tru 2 so (co xem xet cac dieu kien cu the)
int SoSanh(char S1[], char S2[]);						//So sanh |value| cua 2 so BigNum
void sup_Nhan(SNL num, int x, SNL &result);
void Nhan(SNL num1, SNL num2, SNL &result);

int main(){
	char a[SIZE], b[SIZE];
	//gets(a);gets(b);
	scanf("%s",&a);	scanf("%s",&b);
	SNL num1, num2, Cong_result, Tru_result, Nhan_result;
	str_convert(num1,a);	str_convert(num2,b);
	printf("\n%s + %s = ",a,b);							//cong
	Cong(num1,num2,Cong_result);	xuatSNL(Cong_result);
	printf("\n%s - %s = ",a,b);							//tru
	Tru(num1,num2,Tru_result);		xuatSNL(Tru_result);
	printf("\n%s * %s = ",a,b);							//Nhan
	Nhan(num1,num2,Nhan_result);	xuatSNL(Nhan_result);
	return 0;
}

void str_convert(SNL &num, char S[SIZE]){
	int i, n=strlen(S), len=0;
	if (S[0]=='-')
			{	num.sign=-1;	i=1;	}
	else	{	num.sign=1;		i=0;	}
	while (i<=n) num.value[len++]=S[i++];
	strrev(num.value);
}
void Cong_unsigned(SNL num1, SNL num2, SNL &result){
	prepare(num1,num2);								//num1, num2 are reversed, result.value="".
	int n=strlen(num1.value), remind=0, tmp, i;
	for (i=0;i<n;i++){
		tmp=num1.value[i]+num2.value[i]+remind-96;
		result.value[i]=tmp%10+'0';
		remind=tmp/10;
	}
	if (remind==1)	result.value[i++]='1';
	result.value[i]='\0';
}
void Cong(SNL n1, SNL n2, SNL &result){
	SNL num1=n1, num2=n2;
	if (num1.sign==num2.sign){
		Cong_unsigned(num1,num2,result);
		result.sign=num1.sign;
	} else {
		if (num1.sign==-1){
			num1.sign=1;	Tru(num2,num1,result);
		}
		else if (num2.sign==-1){
			num2.sign=1;	Tru(num1,num2,result);
		}
	}
}
void Tru_unsigned(SNL num1, SNL num2, SNL &result){
	prepare(num1,num2);									//num1, num2 are reversed.
	int remind=0, tmp, i;
	int n=strlen(num1.value);
	for (i=0;i<n;i++){
		if (num1.value[i]>=num2.value[i]+remind){
			tmp=num1.value[i]-num2.value[i]-remind;
			remind=0;
		} else {
			tmp=num1.value[i]-num2.value[i]-remind+10;
			remind=1;
		}
		result.value[i]=tmp+48;
	}
	result.value[i]='\0';	i--;
	while (result.value[i]=='0')
		result.value[i--]='\0';
}
void Tru(SNL n1, SNL n2, SNL &result){
	SNL num1=n1, num2=n2;
	int ss=SoSanh(num1.value,num2.value);
	if (ss==0){
		strcpy(result.value,"0");
		result.sign=1;
	}
	else if (num1.sign==num2.sign){
		if (ss>0){
			result.sign=num1.sign;
			Tru_unsigned(num1,num2,result);
		}
		else if (ss<0){
			result.sign=num1.sign*(-1);
			Tru_unsigned(num2,num1,result);
		}
		}else{
			result.sign=num1.sign;
			Cong_unsigned(num1,num2,result);
		}
}
int SoSanh(char S1[], char S2[]){
	if (strlen(S1)>strlen(S2))
		return 1;
	else if (strlen(S1)<strlen(S2))
		return -1;
	return strcmp(S1,S2);
}
void sup_Nhan(SNL num, int x, SNL &result){
	int i, remind=0, n=strlen(num.value);
	for (i=0;i<n;i++){
		int tmp=x*(num.value[i]-'0')+remind;
		result.value[i]=tmp%10+'0';
		remind=tmp/10;
	}
	if (remind>0)
		result.value[i++]=remind+'0';
	result.value[i]='\0';
}
void Nhan(SNL num1, SNL num2, SNL &result){
	int n=strlen(num2.value), k=-1;
	result.sign=1;									//Khoi tao sign term, ko lay gia tri -1 vi sau do multi=result nen sign bi thay doi lien tuc
	for (int i=0;i<n;i++){
		k++;
		SNL multi=result, tmp;						//multi luu gia tri hien tai cua result, tmp luu gia tri phep *
		tmp.sign=1;
		sup_Nhan(num1,num2.value[i]-'0',tmp);
		int len=strlen(tmp.value);
		strrev(tmp.value);							//Dao nguoc xau de them '0'
		for (int j=0;j<k;j++)						//Nhan 10, ung voi vi tri tuong ung
			tmp.value[len++]='0';
		tmp.value[len]='\0';
		strrev(tmp.value);							//Dao nguoc xau lai trang thai ban dau
		Cong(multi,tmp,result);
	}
	if (num1.sign*num2.sign<0)	result.sign=-1;		//Cap nhat sign that su
}
void xuatSNL(SNL num){
	if (num.sign==-1)		printf("-");
	strrev(num.value);
	printf("%s",num.value);
	strrev(num.value);
}
void prepare(SNL &num1, SNL &num2){
	int len1=strlen(num1.value),	len2=strlen(num2.value);
	if (len1>len2)
		insert(num2.value,len2,len1-len2,'0');
	else if (len1<len2)
		insert(num1.value,len1,len2-len1,'0');
}
void insert(char S[], int pos, int n, char ch){
	int i;
	for (i=pos;i<pos+n;i++)
		S[i]=ch;
	S[i]='\0';
}
