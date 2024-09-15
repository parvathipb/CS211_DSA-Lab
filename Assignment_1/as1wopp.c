#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#define BSIZE 1024
void toh(int,char,char,char);
void toh(int n,char a,char b,char c){
    if(n>=1){
        toh(n-1,a,c,b);
        printf("Pop disk %d from %c and Push disk %d to %c\n",n,a,n,b);
      toh(n-1,c,b,a);

    }
}
int main(int argc,char* argv[]){

FILE *f_o;
int n=atoi(argv[1]);


f_o= fopen("toh1.txt","w");//writing to a file
    int fd=fileno(f_o), copy=dup(1);
	dup2(fd,1);
	toh(n,'A','C','B');;	/* this one is to tmp.txt */
	fflush(stdout);
      	fclose(f_o); 
	dup2(copy,1); /* return stdout to normal */
	toh(n,'A','C','B');
    
    //closing the file
    return 0;
    }

