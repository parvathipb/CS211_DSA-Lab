#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];
struct node
{
        int data; 
        struct node *next;
};
struct node *Queuehead=NULL;
struct node *Queuetail=NULL;
struct node *create()
{
        struct node *newnode=malloc(sizeof(struct node));
        if(newnode==NULL)
        {
                printf("\n Out of Memory Space: \n");
                exit(0);
        }
       
        newnode->next=NULL;
        return newnode;
       
}
void Enqueue(FILE *f_q,int value){
        struct node *newnode;
        if(Queuehead==NULL && Queuetail==NULL){
              Queuehead=newnode;
              Queuetail=newnode;
              newnode->data=value;
              fprintf(f_q,"enqueued %d \n",value);    
        }
        else{
                if(Queuehead->next ==NULL &&  Queuetail->next==NULL){
                        Queuehead->next =newnode;
                         Queuetail->next=newnode;
                         Queuetail=Queuetail->next;
                         Queuetail->data=value;
                         fprintf(f_q,"enqueued %d\n",value);
                }
                else{
                         Queuetail->next=newnode;
                         Queuetail=Queuetail->next;
                         Queuetail->data=value;
                         fprintf(f_q,"enqueued %d\n",value);
                }
        }
        
}
void Dequeue(FILE *f_q){
          struct node *p;
          if(Queuehead==NULL)
        {
                fprintf(f_q,"underflow\n");
               
        }
        else{
                if(Queuehead==Queuetail){
                      p=Queuehead;
                      Queuehead=NULL;
                      Queuetail=NULL;
                       int del=p->data;  
                       fprintf(f_q,"dequeued %d\n",del);
                }
                else{
                         p=Queuehead;
                         Queuehead=Queuehead->next ;
                         int del=p->data;
                         fprintf(f_q,"dequeued %d\n",del);
                        free(p);
                }
               
        }
}
void PrintQ(FILE *f_q){
        struct node *q;
        if(Queuehead==NULL && Queuetail==NULL){
              fprintf(f_q,"\n");
        }
        else{
           if(Queuehead->next == NULL){
         int Queuetraversalnumber=Queuehead->data;
         fprintf(f_q,"%d ",Queuetraversalnumber);
              }
          else{
                q=Queuehead;
                 while(q!=NULL){
        int Queuetraversalnumber=q->data;
        fprintf(f_q,"%d ",Queuetraversalnumber);
        q=q->next;
                                    }

             }
         fprintf(f_q,"\n");
        }
}
void searchQ(FILE *f_q, int value){
         struct node *Queuefind;
        if(Queuehead==NULL)
        {
                fprintf(f_q," not found %d\n",value);
                
        }
         else if(Queuehead->next ==NULL)
        {
              
                int poppedelem=Queuehead->data;
                if(poppedelem==value){
                    fprintf(f_q,"found %d\n",value);
                }
                else{
                    fprintf(f_q,"not found %d\n",value);
                }
               
                
        }
        else{
              Queuefind=Queuehead;
               bool found=false;
               while(Queuefind!=NULL){
                      int Queuefindnumber=Queuefind->data;
                     
                     if(Queuefindnumber==value){
                       fprintf(f_q,"found %d\n",Queuefindnumber);
                       found=true;
                        break;
                                      }
                     Queuefind=Queuefind->next;
                     }

                    if(found==false){
                         fprintf(f_q,"not found %d\n",value);
                   }
        }
}
// queue functions finished

int main(int argcom, char* argvalue[]){
  FILE *fpoin,*f_q,*f_s,*f_d;  
  printf("Value at argv[0]= %s\n",argvalue[0]);
  printf("Value at argv[1]= %s\n",argvalue[1]); 
  printf("Value at argv[2]= %s\n",argvalue[2]);
  int d=atoi(argvalue[2]);
  printf("%d\n",d);
 int t=0;
//f_s= fopen("stack.txt","w");
f_q=fopen("queue.txt","w");
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
        for(int i=0;i<l-3;i++){
          str[i]=bufferval[i+2];
        }
      }
     int value=atoi(str);
        switch (choice) {
        case '+':
          if(t>d){
            //fprintf(f_s,"overflow\n");
            fprintf(f_q,"overflow\n");
          }
          else{
            //push(f_s,value);
            Enqueue(f_q,value); 
            t++;
          }
          printf("%c %d\n",choice,value);
                  
          //Insert(f_d,value);
          break;
        case '-':
            //fprintf(f_s,"Popped %d\n", pop(f_s));
            Dequeue(f_q);
            t--;
           //Delete(f_d,value);
            break;
        case '!':
            //display(f_s);
            printf("%c\n",choice);
          PrintQ(f_q);
            //displayD(f_d);
            break;
        case '?':
            //search(f_q,value);
            printf("%c %d\n",choice,value);
            searchQ(f_q,value);
            //searchD(f_d,value);
            break;
        }
   }

  fclose(fpoin);
  fclose(f_q);
}
