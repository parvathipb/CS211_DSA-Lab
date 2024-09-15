#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
#define N 1024
int num[N];
char bufferval[BSIZE];
int main(int argcom, char* argvalue[]){
    FILE *fpoin;
    int count=0;
    char filename[1024];
    fpoin= fopen (argvalue[1],"r");   //To read the provided input file
  if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);//To check what happens when input is not provided through command line
	}
   while(fgets(bufferval,BSIZE,fpoin)!=NULL){
        num[count]=atof(bufferval);
        count++;
    }
    int i;
    for ( i = 0; i < count; i++)
    {
        printf("%d\n",num[i]);
    }
    return 0;
}