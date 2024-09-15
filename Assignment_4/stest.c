#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(FILE *f_s,int value) {
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top; 
    }
    top = newNode; 
    fprintf(f_s,"pushed %d\n",value);
}



int pop(FILE *f_s) {
    if (top == NULL) {
        fprintf(f_s,"underflow\n");
    } else {
        struct Node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        return temp_data;
    }
}

void display(FILE *f_s) {
    // Display the elements of the stack
    if (top == NULL) {
        fprintf(f_s," \n");
    } else {
        struct Node *temp = top;
        while (temp->next != NULL) {
            fprintf(f_s,"%d ", temp->data);
            temp = temp->next;
        }
        fprintf(f_s,"%d \n", temp->data);
    }
}

void search(FILE *f_s,int value)
{
    struct Node *current = top; // Initialize current
    if(top==NULL){
        fprintf(f_s,"not found %d\n",value);
    }
    else if(top->next==NULL){
            int p=current->data;
            if(p==value){
                fprintf(f_s,"found %d\n",value);
            }
            else{
                fprintf(f_s,"not found %d\n",value);
            }
        }
    else{
        bool foundelem=false;
        while(current!=NULL) {
        if(current->data==value){
           fprintf(f_s,"found %d\n",value);
           foundelem=true;
           break;
        }
        current = current->next;      
        }
        if(foundelem==false){
            fprintf(f_s,"not found %d\n",value);
        }
    }
}

int main(int argcom, char* argvalue[]){
  FILE *fpoin,*f_q,*f_s,*f_d;  
  printf("Value at argv[0]= %s\n",argvalue[0]);
  printf("Value at argv[1]= %s\n",argvalue[1]); 
  printf("Value at argv[2]= %s\n",argvalue[2]);
  int d=atoi(argvalue[2]);
  printf("%d\n",d);
  //int QSize=d;
  //Queue = (int*)malloc(QSize*sizeof(int));
  int t=0;

f_s= fopen("stack.txt","w");
//f_q=fopen("queue.txt","w");
//f_d=fopen("dll.txt","w");
fpoin= fopen (argvalue[1],"r");  
if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	}
   while(fgets(bufferval,BSIZE,fpoin)!=NULL){
     int l=strlen(bufferval);
     char choice=bufferval[0];
     char str[l-3];
     if(l>2){
        for(int i=0;i<(l-3);i++){
          str[i]=bufferval[i+2];
        }
      }
     int value=atoi(str);
        switch (choice) {
        case '+':
          if(t>d){
            fprintf(f_s,"overflow\n");
          }
          else{
            push(f_s,value);
            t++;
          }
          //Enqueue(f_q,value);
          //Insert(f_d,value);
          break;
        case '-':
            fprintf(f_s,"popped %d\n", pop(f_s));
            t--;
            //Dequeue(f_q);
            //Delete(f_d,value);
            break;
        case '!':
            display(f_s);
            //PrintQ(f_q);
            //displayD(f_d);
            break;
        case '?':
            search(f_s,value);
            //searchQ(f_q,value);
            //searchD(f_d,value);
            break;
        }
   }

  fclose(fpoin);
  fclose(f_s);
  //fclose(f_q);
  //fclose(f_d);
 return 0;
}