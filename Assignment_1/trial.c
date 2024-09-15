#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
void toh(int,char,char,char);
void toh(int n,char a,char b,char c){
    char *bufferval[BSIZE];
    if(n>=1){
        toh(n-1,a,c,b);
        FILE *f_o;
        f_o= fopen("toh.txt","w");
        fprintf(f_o,"Pop disk %d from %c and Push disk %d to %c\n",n,a,n,b);
      sprintf(*bufferval,"Pop disk %d from %c and Push disk %d to %c\n",n,a,n,b);
       printf("Pop disk %d from %c and Push disk %d to %c\n",n,a,n,b);
      toh(n-1,c,b,a);

    }
}
int main(int argc,char* argv[]){

FILE *f_o;
int n=atoi(argv[1]);
char *bufferval[BSIZE];


f_o= fopen("toh.txt","w");//writing to a file

    if (f_o==NULL){
        printf("Error opening file.\n");
        return 1;//to check if output.txt file can open or not
    }
    else{
        //putting the outputs into the file using fprintf 
toh(n,'A','C','B');
        fprintf(f_o,"%s\n",*bufferval);
        printf("Program ran Successfully");
    }
    
    //closing the file
    fclose(f_o);
    return 0;
    }

