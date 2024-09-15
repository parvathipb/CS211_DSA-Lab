#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];

int main(int argcom, char* argvalue[]){
  FILE *fpoin,*f_q,*f_s,*f_d;  
  printf("Value at argv[0]= %s\n",argvalue[0]);
  printf("Value at argv[1]= %s\n",argvalue[1]); 
  printf("Value at argv[2]= %s\n",argvalue[2]);
  int d=atoi(argvalue[2]);
  printf("%d\n",d);
  fpoin= fopen (argvalue[1],"r");  
if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	}
   while(fgets(bufferval,BSIZE,fpoin)!=NULL){
     int l=strlen(bufferval);
     char choice=bufferval[0];
     char str[l-3];
     if(l>2){
        for(int i=0;i<(l-3);i++){
          str[i]=bufferval[i+2];
        }
      }
     int value=atoi(str);
        switch (choice) {
        case '+':
        printf("%c ",choice);
        printf("%d\n",value);
        break;
        case '-':
        printf("%c ",choice);
        printf("%d\n",value);
        break;
        case '!':
        printf("%c\n",choice);
        break;
        case '?':
        printf("%c ",choice);
        printf("%d\n",value);
        break;
        }
   }
   fclose (fpoin);
}