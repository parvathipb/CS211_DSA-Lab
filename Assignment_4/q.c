#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 4096
char bufferval[BSIZE];
struct Node
{
        int data; 
        struct Node *next;
};
struct Node *Qh=NULL;
struct Node *Qt=NULL;
struct Node *createnew()
{
        struct Node *newnode=malloc(sizeof(struct Node));
        if(newnode==NULL)
        {
                printf("\n Out of Memory Space: \n");
                exit(0);
        }
       
        newnode->next=NULL;
        return newnode;
       
}
void Enqueue(FILE*f_q,int value){
        struct Node *newnode;
        newnode=createnew();
        if(Qh==NULL && Qt==NULL){
              Qh=newnode;
              Qt=newnode;
              newnode->data=value;
              fprintf(f_q,"enqueued %d \n",value);    
        }
        else{
                if(Qh->next ==NULL &&  Qt->next==NULL){
                        Qh->next =newnode;
                         Qt->next=newnode;
                         Qt=Qt->next;
                         Qt->data=value;
                         fprintf(f_q,"enqueued %d\n",value);
                }
                else{
                         Qt->next=newnode;
                         Qt=Qt->next;
                         Qt->data=value;
                         fprintf(f_q,"enqueued %d\n",value);
                }
        }
        
}
void Dequeue(FILE*f_q,int value){
          struct Node *ft;
          if(Qh==NULL)
        {
                fprintf(f_q,"underflow\n");
               
        }
        else{
                if(Qh==Qt){
                      ft=Qh;
                      Qh=NULL;
                      Qt=NULL;
                       int r=ft->data;  
                       fprintf(f_q,"dequeued %d\n",r);
                }
                else{
                          ft=Qh;
                         Qh=Qh->next ;
                         int r=ft->data;
                         fprintf(f_q,"dequeued %d\n",r);
                        free(ft);
                }
               
        }
}
void PrintQ(FILE* f_q){
        struct Node *Pq;
        if(Qh==NULL && Qt==NULL){
              fprintf(f_q,"\n");
        }
        else{
           if(Qh->next == NULL){
         int m=Qh->data;
         fprintf(f_q,"%d ",m);
              }
          else{
                Pq=Qh;
                 while(Pq!=NULL){
        int m=Pq->data;
        fprintf(f_q,"%d ",m);
        Pq=Pq->next;
              }
             }
         fprintf(f_q,"\n");
        }
}
void searchQ(FILE*f_q, int value){
         struct Node *tem;
  if(Qh==NULL)
        {
                fprintf(f_q," not found %d\n",value);
                
        }
  else if(Qh->next ==NULL)
        {
              
                int de=Qh->data;
                if(de==value){
                    fprintf(f_q,"found %d\n",value);
                }
                else{
                    fprintf(f_q,"not found %d\n",value);
                }
               
                
        }
  else{
              tem=Qh;
               bool found=false;
               while(tem!=NULL){
                      int l=tem->data;
                     
                     if(l==value){
                       fprintf(f_q,"found %d\n",l);
                       found=true;
                        break;
                        }
                     tem=tem->next;
                     }

                    if(found==false){
                         fprintf(f_q,"not found %d\n",value);
                   }
        }
}
// queue functions finished
int main(int argc,char*argv[]){
      if(argc!=3){
        printf("command line argument should be in the format 'execution file','input file','max of stack'");
        exit(0);
      }
       FILE*inp=fopen(argv[1],"r");
      // FILE*stack=fopen("stack.txt","w");
       FILE*f_q=fopen("queue.txt","w");
      // FILE* dll=fopen("dll.txt","w");
      int maxqueue=atoi(argv[2]);
      
   //int top=-1;
   int QHI=-1;
   int QTI=-1;
    
      while( (fgets(bufferval,BSIZE,inp) )!=NULL){
             int l=strlen(bufferval);

             char str[l-3];
            
             if(l>2){
                 for(int i=0;i<(l-3);i++){
                str[i]=bufferval[i+2];
                      }
                      
                     }
             int value=atoi(str);
            

             char symbol=bufferval[0];
             // printf("%d %c %d\n",len,symbol,number);
             switch (symbol)
             {
            case '+':
                /*if(top<maxstack){
                    Push(stack, number);
                    top++;
                }
                else{
                    fprintf(stack,"overflow\n");
                }*/
               

               if(( QTI+1)%maxqueue == QHI){
                 fprintf(f_q,"overflow\n");
               }
               else{
                 Enqueue(f_q,value);
                  	if(QHI == -1){
		        QHI++;    }
                        QTI++;
		        QTI = QTI % maxqueue;  }   
                 //inserted(dll,number);      
                break;
            case '-':
                 /*if(top>-1){
                   Pop(stack);
                    top--;
                }
                else{
                    fprintf(stack,"underflow\n");
                }*/

                if(QHI == -1){
                        fprintf(f_q,"underflow \n");
                }
                else{
                        if(QHI == QTI){
                           Dequeue(f_q,value);
                           //fprintf(queue,"dequeued %d\n",number);
                           QHI=-1;
                           QTI=-1;
			

                        }
                        else{
                             Dequeue(f_q,value);
                              //fprintf(queue,"dequeued %d\n",number);
                             QHI++;
			     QHI = QHI% maxqueue;   
                        }
                }
              
                        //deleted(dll,number);
                
                
               
                break;
            case '?':
                 //StackFound(stack,number);
                 searchQ(f_q,value);
                  //dllFound(dll,number);
                break;
            case '!':
                //Stacktraversal(stack,top);
                PrintQ(f_q);
                 //dlltraversal(dll);
                
                break;
             
             }

      }

     
}
