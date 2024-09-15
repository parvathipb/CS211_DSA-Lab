#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
void toh(int,char,char,char);
int main(int argc, char *argv[]){
     FILE *f_o;
    int n=atoi(argv[1]);
    toh(n,'a','c','b');
    f_o= fopen("toh.txt","w");//writing to a file

    if (f_o==NULL){
        printf("Error opening file.\n");
        return 1;//to check if output.txt file can open or not
    }
    
    //closing the file
    fclose(f_o);
    return 0;
}
void toh(int n,char a,char b,char c){
    FILE *f_o;
     if (n == 1) {
        f_o= fopen("toh.txt","w");
        fprintf(f_o,"Pop disk %d from %c and Push disk %d to Stack %c\n",n,a,n,b);
        printf("Pop disk %d from %c and Push disk %d to Stack %c\n",n,a,n,b);
        
    }
     else
     {
        toh(n-1,a,c,b);
        f_o= fopen("toh.txt","w");
        fprintf(f_o,"Pop disk %d from %c and Push disk %d to %c\n",n,a,n,b);
        printf("Pop disk %d from %c and Push disk %d to %c\n",n,a,n,b);
        toh(n-1,c,b,a);

     }
    }

