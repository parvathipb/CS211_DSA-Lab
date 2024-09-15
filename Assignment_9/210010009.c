/*Acknowledgement to Programiz.com*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];
#define MAX 500000

typedef struct node {
  int h, g, d;
} node;

typedef struct Node {
  node value[MAX];
  int k;
} Node;
Node hal;

int k;
Node bitt;
void arrange() {
  int i, j;
  node temp;
  for (i = 1; i < hal.k; i++)
    for (j = 0; j < hal.k - 1; j++)
      if (hal.value[j].d > hal.value[j + 1].d) {
        temp = hal.value[j];
        hal.value[j] = hal.value[j + 1];
        hal.value[j + 1] = temp;
      }
}
void setunion(int get[], int x, int y) {
  int i;
  for (i = 0; i < k; i++)
    if (get[i] == y)
      get[i] = x;
}
int search(int get[], int nover) {
  return (get[nover]);
}
void KFunc(int **array1) {
  int get[MAX], i, j, z, w;
  hal.k = 0;
  for (i = 1; i < k; i++)
    for (j = 0; j < i; j++) {
      if (array1[i][j] != 0) {
        hal.value[hal.k].h = i;
        hal.value[hal.k].g = j;
        hal.value[hal.k].d = array1[i][j];
        hal.k++;
      }
    }
  arrange();
  for (i = 0; i < k; i++)
    get[i] = i;
  bitt.k = 0;
  for (i = 0; i < hal.k; i++) {
    z = search(get, hal.value[i].h);
    w = search(get, hal.value[i].g);

    if (z != w) {
      bitt.value[bitt.k] = hal.value[i];
      bitt.k = bitt.k + 1;
      setunion(get, z, w);
    }
  }
}
void display(FILE *f_m) {
  int a;
  for (a = 0; a < bitt.k; a++) {
    fprintf(f_m,"%d %d %d\n", bitt.value[a].h, bitt.value[a].g, bitt.value[a].d);
  }
}

int main(int argcom, char* argvalue[]){
    FILE *fpoin,*f_a,*f_m;
    int i,j,n=0,m=0;
    int l=0;
    int **array1;
    printf("Value at argv[0]= %s\n",argvalue[0]);
    printf("Value at argv[1]= %s\n",argvalue[1]);  
f_m= fopen("mst.txt","w");
fpoin= fopen (argvalue[1],"r");  
f_a=fopen(argvalue[1],"r");

if(f_a==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	} 
  while(fgets(bufferval,BSIZE,f_a)!=NULL){
    char string[50];
    strcpy(string,bufferval);
    char *token1 = strtok(string," ");
    char *token2=strtok(NULL," ");
    char *token3=strtok(NULL," ");
    int num1=atoi(token1);
    int num2=atoi(token2);
    int num3=atoi(token3);
    if(num1>n && num2>m){
        n=num1;
        m=num2;
    }
    else if(num1>n){
        n=num1;
    }
    else if(num2>m){
        m=num2;
    }
    l++;
  }
  if(n>m){
    k=n;
  }
  else{
    k=m;
  }
  //printf("%d\n",k);
  fclose(f_a);
k=k+1;
printf("%d\n",k);
array1=malloc(sizeof(int*)*k);
for(i=0;i<k;i++)
    array1[i]=malloc(sizeof(int)*k);
for(i=0;i<k;i++)
    for(j=0;j<k;j++)
        array1[i][j]=0;

if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	} 
  while(fgets(bufferval,BSIZE,fpoin)!=NULL){
    char string[50];
    strcpy(string,bufferval);
    char *token1 = strtok(string," ");
    char *token2=strtok(NULL," ");
    char *token3=strtok(NULL," ");
    int num1=atoi(token1);
    int num2=atoi(token2);
    int num3=atoi(token3);
    //fprintf(f_m,"%d\n",num3);
        array1[num1][num2]=num3;
        array1[num2][num1]=num3;
        //fprintf(f_m,"%d\n",array1[num1][num2]);
    }
 KFunc(array1);
 display(f_m);

  fclose(f_m);
  fclose(fpoin);
return 0;
}