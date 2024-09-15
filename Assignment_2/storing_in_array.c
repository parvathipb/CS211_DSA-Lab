#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define N 1024
int num[N];
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
    while(!feof(fpoin)){
        fscanf(fpoin,"%d",&num[count]);
        count++;
    }
    int i;
    for ( i = 0; i < count; i++)
    {
        printf("%d\n",num[i]);
    }
    return 0;
}