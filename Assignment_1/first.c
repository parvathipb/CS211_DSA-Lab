#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
void Push(){
    int x;
    if (top==N-1)
    {
       printf("Overflow");
    }
    else{
        top++;
        stack[top]=x;
    }
}

void Pop(){
    int item;
    if (top==-1)
    {
        printf("Underflow");
    }
    else{
        item=stack[top];
        top--;
        printf("%d",item);
    }   
}

void toh(int,char,char,char);
void toh(int n,char source_stack,char dest_stack,char aux_stack){
    if (n == 1) {
         printf("Pop disk %d from Stack %c\n",n,source_stack);
         printf("Push disk %d to Stack %c\n",n,dest_stack);
    }
    else(n>1){
        toh(n-1,source_stack,aux_stack,dest_stack);
      printf("Pop disk %d from Stack %c\n",n,source_stack);
      printf("Push disk %d to Stack %c\n",n,dest_stack);
      toh(n-1,aux_stack,dest_stack,source_stack);

    }
}
int main(int argc,char* argv[]){
FILE *f_o;
int n=atoi(argv[1]);
int disks[n];
toh(n,'A','C','B');
    


f_o= fopen("toh.txt","w");//writing to a file

    if (f_o==NULL){
        printf("Error opening file.\n");
        return 1;//to check if output.txt file can open or not
    }
    else{
        //putting the outputs into the file using fprintf 
        toh(n,'A','C','B');
        //printf("Program ran Successfully");
    }
    
    //closing the files
    fclose(f_o);
    return 0;
    }
