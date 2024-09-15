#include<stdio.h>
#include<stdlib.h>
void toh(int,char,char,char);

int main(int argc, char *argv[]){
    // printf("enter the no.of disks\n");
    //scanf("%d",&n);
    int n=atoi(argv[1]);
    toh(n,'a','b','c');
    return 0;
}
void toh(int n,char a,char b,char c){
    if(n>=1){
        toh(n-1,a,c,b);
      printf("Pop disk %d from %c and Push disk %d to %c\n",n,a,n,b);
      toh(n-1,c,b,a);

    }
}