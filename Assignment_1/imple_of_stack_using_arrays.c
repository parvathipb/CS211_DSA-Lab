#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define N 5;
int stack[N];
int top = -1;
void Push(){
    int x;
    printf("Enter data");
    scanf("%d",&x);
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
void Peep(){
    if(top==-1){
        printf("Empty");
    }
    else{
        printf("%d",stack[top]);
    }
}
void display(){
    int i;
    for(i=top;i>=0;i--){
        printf("%d",stack[i]);
    }
}

void main(){
int ch;


}