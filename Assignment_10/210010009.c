#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define INF 9999
#define BSIZE 1024
char bufferval[BSIZE];
FILE *f_d;

void Dijkstra(int **array1, int k, int top) {
  int **array2, dist[k], prds[k];
  int done[k], num, min, nxtn, i, j;
        array2=malloc(sizeof(int*)*k);
        for(i=0;i<k;i++)
            array2[i]=malloc(sizeof(int)*k);

  for (i = 0; i < k; i++)
    for (j = 0; j < k; j++)
      if (array1[i][j] == 0){
        array2[i][j] = INF;
      }
      else{
        array2[i][j] = array1[i][j];
      }
    for(i=0;i<k;i++)
        for(j=0;j<k;j++)
          if(i==j)
               array2[i][j]=0;

  for (i = 0; i < k; i++) {
    dist[i] = array2[top][i];
    prds[i] = top;
    done[i] = 0;
  }

  dist[top] = 0;
  done[top] = 1;
  num = 1;

  while (num < k - 1) {
    min = INF;

    for (i = 0; i < k; i++)
      if (dist[i] < min && !done[i]) {
        min = dist[i];
        nxtn = i;
      }

    done[nxtn] = 1;
    for (i = 0; i < k; i++)
      if (!done[i])
        if (min + array2[nxtn][i] < dist[i]) {
          dist[i] = min + array2[nxtn][i];
          prds[i] = nxtn;
        }
    num++;
  }
  
  f_d= fopen("dijkstra.txt","w");
  fprintf(f_d,"%d 0\n",top);
  for (i = 0; i < k; i++)
    if (i != top) {
      if(dist[i]==INF){
          fprintf(f_d,"%d -1\n",i);
      }
      else{
      fprintf(f_d,"%d %d\n",i,dist[i]);
      }
    }
}


int main(int argcom, char* argvalue[]){
    FILE *fpoin,*f_a;
    printf("Value at argv[0]= %s\n",argvalue[0]);
    printf("Value at argv[1]= %s\n",argvalue[1]);  
    printf("Value at argv[2]= %s\n",argvalue[2]); 
    int h=atoi(argvalue[2]);
    printf("%d\n",h);
    int i,j,k,n=0,m=0;
    int l=0;
    int **array1;
f_d= fopen("dijkstra.txt","w");
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
        //array1[num2][num1]=num3;
        //fprintf(f_m,"%d\n",array1[num1][num2]);
    }

Dijkstra(array1, k, h);

  fclose(f_d);
  fclose(fpoin);
return 0;
}