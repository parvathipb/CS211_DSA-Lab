/*Acknowledgement to cboard.cprogramming.com;Jenny's lectures CS/IT NET&JRF(youtube);capt Joe(youtube)*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#define N 1024
int ttop = -1;
int stack[N];
void Push(int n,char dest_stack){
    int x;
    if (ttop==N-1)
    {
       printf("Stack Overflow\n");
    }
    else{
        ttop++;
        stack[ttop]=x;
        printf("Push disk %d to Stack %c\n",n,dest_stack);
    }
}

void Pop(int n,char source_stack){
    int itemp;
    if (ttop==-1)
    {
        printf("Stack Underflow\n");
    }
    else{
        itemp=stack[ttop];
        ttop--;
        printf("Pop disk %d from Stack %c\n",n,source_stack);
    }   
}
void Task(int n,char dest_stack){
    int i;
    for(i=n;i>=1;i--){
    Push(i,dest_stack);
}
}
void toh(int,char,char,char);
void toh(int n,char source_stack,char dest_stack,char aux_stack){
    if(n==1){
        /* base case */
        //moving disk from source_stack to dest_stack
       //pop disk 1 from stack A and push disk 1 to stack C
         Pop(n,source_stack);
         Push(n,dest_stack);
    }
    else{ /* recursion case */
        toh(n-1,source_stack,aux_stack,dest_stack);
        Pop(n,source_stack);
        Push(n,dest_stack);
       //for checking  //printf("Pop disk %d from %c and Push disk %d to %c\n",n,source_stack,n,dest_stack);
        toh(n-1,aux_stack,dest_stack,source_stack);
    }
}
int main(int argc,char* argv[]){

FILE *f_o;
int n=atoi(argv[1]);

f_o= fopen("toh.txt","w");//writing to a file
    int fd=fileno(f_o), copy=dup(1);
	dup2(fd,1);
    Task(n,'A');
	toh(n,'A','C','B');/* this one is to toh.txt */
	fflush(stdout);
    fclose(f_o); 
	dup2(copy,1); /* return stdout to normal */
    Task(n,'A');
	toh(n,'A','C','B');
    
    //closing the file
    return 0;
    }

