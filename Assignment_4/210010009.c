#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];
struct node  
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head; 
struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;
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

void Insert(FILE *f_d,int value)  
{  
   struct node *ptr;     
   ptr = (struct node *)malloc(sizeof(struct node));   
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=value;  
       head=ptr;
       fprintf(f_d,"inserted %d\n",value);
    
   }  
   else   
   {  
       ptr->data=value;  
       ptr->next=head;  
       ptr->prev = NULL;  
       head->prev=ptr;  
       head=ptr; 
         fprintf(f_d,"inserted %d\n",value);
        
   }       
}  

void Delete(FILE *f_d,int value)  
{  
    struct node *ptr;       
if(head == NULL)  
    {  
        fprintf(f_d,"cannot delete %d\n",value);
       
    } 
else{
    bool found=false;
    ptr = head; 
    while(ptr!=NULL) {  
       if(ptr -> data == value) {
        if(ptr->prev==NULL){ 
        head=head->next;
        ptr->next->prev=NULL;
        ptr->next=NULL;
        fprintf(f_d,"deleted %d\n",value);
      
        free(ptr);
        found=true;
        break; 
      }  
       else if(ptr -> next== NULL)  
      {  
        ptr ->prev->next=NULL;
        fprintf(f_d,"deleted %d\n",value);
        free(ptr);
        found=true;
        break;  
      }  
       else  
      {   
        ptr->next->prev=ptr->prev;
        ptr->prev->next=ptr->next;
        fprintf(f_d,"deleted %d\n",value);
       
        free(ptr);
        found=true; 
        break;
      } 
    }
    ptr=ptr->next;
  }  
  if(found==false){
      fprintf(f_d,"cannot delete %d\n",value);
  }   
 }
}
void displayD(FILE *f_d)  
{  
    struct node *ptr;   
    ptr = head;  
    if (head == NULL) {
        fprintf(f_d," \n");
      
    } else {
    while(ptr != NULL)  
    {  
        fprintf(f_d,"%d ",ptr->data); 
       
        ptr=ptr->next;  
    } 
    fprintf(f_d," \n");
    
 } 
}  
void searchD(FILE *f_d,int value)  
{  
    struct node *ptm;  
    bool flag=false;  
    ptm = head;      
        while (ptm!=NULL)  
        {  
            if(ptm->data == value)  
            {  
                fprintf(f_d,"found %d\n",value); 
               
                flag=true;  
                break;  
            }     
            ptm = ptm -> next;  
        }  
        if(flag==false)  
        {  
            fprintf(f_d,"not found %d\n",value);  
           
          
    }          
}

int main(int argcom, char* argvalue[]){
  FILE *fpoin,*f_q,*f_s,*f_d;  
  printf("Value at argv[0]= %s\n",argvalue[0]);
  printf("Value at argv[1]= %s\n",argvalue[1]); 
  printf("Value at argv[2]= %s\n",argvalue[2]);
  int d=atoi(argvalue[2]);
  printf("%d\n",d);
  int t=0;
  int maxqueue=d;
   int QHI=-1;
   int QTI=-1;

f_s= fopen("stack.txt","w");
f_q=fopen("queue.txt","w");
f_d=fopen("dll.txt","w");
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
            fprintf(f_s,"Overflow\n");
          }
          else{
            push(f_s,value);
            t++;
          }
           if(( QTI+1)%maxqueue == QHI){
                 fprintf(f_q,"overflow\n");
               }
               else{
                 Enqueue(f_q,value);
                  	if(QHI == -1){
		        QHI++;    }
                        QTI++;
		        QTI = QTI % maxqueue;  } 
          Insert(f_d,value);
          break;
        case '-':
            fprintf(f_s,"Popped %d\n", pop(f_s));
            t--;
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
            Delete(f_d,value);
            break;
        case '!':
            display(f_s);
            PrintQ(f_q);
            displayD(f_d);
            break;
        case '?':
            search(f_s,value);
            searchQ(f_q,value);
            searchD(f_d,value);
            break;
        }
   }

  fclose(fpoin);
  fclose(f_s);
  fclose(f_q);
  fclose(f_d);
 return 0;
}
