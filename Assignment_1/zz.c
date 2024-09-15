#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>
#define N 1024
int ttop = -1;
int stack[N];
int main(int argc,char* argv[]){

FILE *f_o;
int n=atoi(argv[1]);

f_o= fopen("toh5.txt","w");//writing to a file
    
    Task(n,'A');
	toh(n,'A','C','B');/* this one is to toh.txt */
	fflush(stdout);
    fclose(f_o); 
	
    Task(n,'A');
	toh(n,'A','C','B');
    
    //closing the file
    return 0;
    }
void Push(int n,char dest_stack){
    int x;
    FILE *f_o;
    if (ttop==N-1)
    {
       printf("Stack Overflow\n");
    }
    else{
        ttop++;
        stack[ttop]=x;
        f_o= fopen("toh5.txt","w");
        fprintf(f_o,"Push disk %d to Stack %c\n",n,dest_stack);
    }
}

void Pop(int n,char source_stack){
    FILE *f_o;
    int itemp;
    if (ttop==-1)
    {
        printf("Stack Underflow\n");
    }
    else{
        itemp=stack[ttop];
        ttop--;
        f_o= fopen("toh5.txt","w");
        fprintf(f_o,"Pop disk %d from Stack %c\n",n,source_stack);
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
