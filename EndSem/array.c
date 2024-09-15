#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];
int main(int argcom, char* argvalue[]){
    FILE *fpoin,*f_a;
    printf("Value at argv[0]= %s\n",argvalue[0]);
    printf("Value at argv[1]= %s\n",argvalue[1]);  
int i,count=0;
f_a= fopen("arr.txt","w");
fpoin= fopen (argvalue[1],"r");  
  int array[1603];
  if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	} 
  while(fgets(bufferval,BSIZE,fpoin)!=NULL){
    int num1=atoi(bufferval);
    //fprintf(f_a,"%d\n",num1);

    array[num1]=num1;
  }
  for(i=0;i<1603;i++){
    fprintf(f_a,"%d\n",array[i]);
  }
  fclose(fpoin);
  return 0;
}