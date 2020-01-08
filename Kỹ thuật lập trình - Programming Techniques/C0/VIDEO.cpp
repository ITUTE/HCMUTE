#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PATH	"VIDEO.txt"
#define strSIZE	51
#define SIZE 	100

struct VIDEO{
	char title[strSIZE], genre[strSIZE], director[strSIZE], actor[strSIZE], actress[strSIZE], producer[strSIZE];
	int year;
};

char *fgetline(FILE *fp, char *str, int maxSIZE);
void getVideo(FILE *fp, VIDEO &x);
void getAllVideos(VIDEO A[], int &n);
void xuatVideo(VIDEO x);
void xuatAllVideos(VIDEO A[], int n);
void inputVideo(VIDEO A[], int &n);
void xuatGenre(VIDEO A[], int n);
void xuatActor(VIDEO A[], int n);
void xuatDirector(VIDEO A[], int n);
void sortTitle(VIDEO A[], int n);

int main()
{
	VIDEO A[SIZE];
	int n;
	getAllVideos(A,n);
	sortTitle(A,n);
	//xuatDirector(A,n);
	//inputVideo(A,n);
	xuatAllVideos(A,n);
	return 0;
}

void sortTitle(VIDEO A[], int n)
{
	VIDEO tmp;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (strcmp(A[i].title,A[j].title)>0)
			{
				tmp=A[i];
				A[i]=A[j];
				A[j]=tmp;
			}
}

void xuatAllVideos(VIDEO A[], int n)
{
	for (int i=0;i<n;i++)
		xuatVideo(A[i]);
}

void xuatVideo(VIDEO x)
{
	printf("\nTitle: %s\n", x.title);
	printf("Genre: %s\n", x.genre);
	printf("Director: %s\n", x.director);
	printf("Actor: %s\n", x.actor);
	printf("Actress: %s\n", x.actress);
	printf("Year: %d\n", x.year);
	printf("Producer: %s\n", x.producer);
}

void xuatDirector(VIDEO A[], int n)
{
	char tmp[strSIZE];	
	printf("Director: ");	gets(tmp);
	for (int i=0;i<n;i++)
		if (strcmp(tmp,A[i].director)==0)
			xuatVideo(A[i]);
}

void xuatActor(VIDEO A[], int n)
{
	char tmp[strSIZE];	
	printf("Actor: ");	gets(tmp);
	for (int i=0;i<n;i++)
		if (strcmp(tmp,A[i].actor)==0)
			xuatVideo(A[i]);
}

void xuatGenre(VIDEO A[], int n)
{
	char tmp[strSIZE];	
	printf("Genre: ");	gets(tmp);
	int flag=0;
	for (int i=0;i<n;i++)
		if (strcmp(tmp,A[i].genre)==0)
		{
			xuatVideo(A[i]);
			flag=1;
		}
	if (flag==0)
		printf("Not found");
}

void inputVideo(VIDEO A[], int &n)
{
	FILE *fp=fopen(PATH,"a");
	if (fp==NULL)
	{
		printf("Error!\n");
		return;
	}
	char tmp[strSIZE];
	int year;
	printf("Title: ");		gets(tmp);	strcpy(A[n].title,tmp);		fprintf(fp,"%s\n",tmp);
	printf("Genre: ");		gets(tmp);	strcpy(A[n].genre,tmp);		fprintf(fp,"%s\n",tmp);
	printf("Director: ");	gets(tmp);	strcpy(A[n].director,tmp);	fprintf(fp,"%s\n",tmp);
	printf("Actor: ");		gets(tmp);	strcpy(A[n].actor,tmp);		fprintf(fp,"%s\n",tmp);
	printf("Actress: ");	gets(tmp);	strcpy(A[n].actress,tmp);	fprintf(fp,"%s\n",tmp);
	printf("Year: ");		scanf("%d",&year);	A[n].year=year;		fprintf(fp,"%d\n",year);
	fflush(stdin);
	printf("Producer: ");	gets(tmp);	strcpy(A[n].producer,tmp);	fprintf(fp,"%s",tmp);
	n++;
	fclose(fp);
}

void getAllVideos(VIDEO A[], int &n)
{
	FILE *fp=fopen(PATH,"rt");
	if (fp==NULL)
		exit(0);
	n=0;
	while (!feof(fp))
		if (n<SIZE)
			getVideo(fp,A[n++]);
		else break;
	fclose(fp);
}

void getVideo(FILE *fp, VIDEO &x)
{
	fgetline(fp,x.title,strSIZE);
	fgetline(fp,x.genre,strSIZE);
	fgetline(fp,x.director,strSIZE);
	fgetline(fp,x.actor,strSIZE);
	fgetline(fp,x.actress,strSIZE);
	fscanf(fp,"%d",&x.year);
	char ch=fgetc(fp);
	fgetline(fp,x.producer,strSIZE);
}

char* fgetline(FILE *fp, char *str, int maxSIZE)
{
	int ch, len;
	if (feof(fp))
		return NULL;
	len=0;
	do{
		ch=fgetc(fp);
		if (ch=='\n' || ch==EOF)
			break;
		if (len<maxSIZE-1)
			str[len++]=ch;
	} while (1);
	str[len]=0;
	return str;
}
