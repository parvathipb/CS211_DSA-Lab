#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#define N 1024
int top = -1;
    int stack[N];
void Push(int n,char dest_stack){
    int x;
    if (top==n-1)
    {
       printf("Overflow\n");
    }
    else{
        top++;
        stack[top]=x;
        printf("Push disk %d to Stack %c\n",n,dest_stack);
    }
}

void Pop(int n,char source_stack){
    int item;
    if (top==-1)
    {
        printf("Underflow\n");
    }
    else{
        item=stack[top];
        top--;
        printf("Pop disk %d from Stack %c\n",n,source_stack);
    }   
}
void Task1(int n,char dest_stack){
    int i;
    for(i=n;i>=1;i--){
    Push(i,dest_stack);
}
}
void toh(int,char,char,char);
void toh(int n,char source_stack,char dest_stack,char aux_stack){
    if(n>=1){
        toh(n-1,source_stack,aux_stack,dest_stack);
        Pop(n,source_stack);
        Push(n,dest_stack);
        printf("Pop disk %d from %c and Push disk %d to %c\n",n,source_stack,n,dest_stack);
      toh(n-1,aux_stack,dest_stack,source_stack);

    }
}
int main(int argc,char* argv[]){

FILE *f_o;
int n=atoi(argv[1]);


f_o= fopen("toh2.txt","w");//writing to a file
    int fd=fileno(f_o), copy=dup(1);
	dup2(fd,1);
    Task1(n,'A');
	toh(n,'A','C','B');/* this one is to tmp.txt */
	fflush(stdout);
      	fclose(f_o); 
	dup2(copy,1); /* return stdout to normal */
    Task1(n,'A');
	toh(n,'A','C','B');
    
    //closing the file
    return 0;
    }

