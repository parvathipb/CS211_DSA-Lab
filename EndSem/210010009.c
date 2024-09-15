#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];

int main(int argcom, char* argvalue[]){
    FILE *fpoin,*f_t;
    printf("Value at argv[0]= %s\n",argvalue[0]);
    printf("Value at argv[1]= %s\n",argvalue[1]);  
int n,m,i,j,count=0,k=0,l=0;
int z,coun=0;
f_t= fopen("ts.txt","w");
fpoin= fopen (argvalue[1],"r");  
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
    int num1=atoi(token1);
    int num2=atoi(token2);
    if(count==0){
        n=num1;
        m=num2;
        count++;
    }
    else{
      break;
    }
  }
  fclose(fpoin);
int *array1[n];
for (i = 0; i < n; i++){
 array1[i] = (int*)malloc(n * sizeof(int));
}
for(i=0;i<n;i++){
 for(j=0;j<n;j++){
   array1[i][j]=0;
  }
}
int *fl = (int*)malloc(n * sizeof(int));
int *deg = (int*)malloc(n * sizeof(int));
fpoin= fopen (argvalue[1],"r");  
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
    int num1=atoi(token1);
    int num2=atoi(token2);
    if(k==0){
      k++;
    }
    else{
      if(l>=m){
        break;
      }
        array1[num1][num2]=1;
        l++;
    }
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            deg[i]=deg[i]+array1[j][i];
    while(coun<n){
        for(z=0;z<n;z++){
            if((deg[z]==0) && (fl[z]==0)){
                fprintf(f_t,"%d\n",(z));
                fl[z]=1;
            }
            for(i=0;i<n;i++){
                if(array1[i][z]==1)
                    deg[z]--;
            }
        }
 
        coun++;
    }

    fclose(fpoin);
    fclose(f_t);
    return 0;
}
 
