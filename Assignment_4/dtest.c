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
       printf ("inserted %d\n",value);   
   }  
   else   
   {  
       ptr->data=value;  
       ptr->next=head;  
       ptr->prev = NULL;  
       head->prev=ptr;  
       head=ptr; 
         fprintf(f_d,"inserted %d\n",value);
         printf ("inserted %d\n",value); 
   }       
}  

void Delete(FILE *f_d,int value)  
{  
    struct node *ptr;       
if(head == NULL)  
    {  
        fprintf(f_d,"cannot delete %d\n",value);
        printf("cannot delete %d\n",value);  
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
        printf("deleted %d\n",value) ;
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
        printf("deleted %d\n",value);
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
        printf(" \n");
    } else {
    while(ptr != NULL)  
    {  
        fprintf(f_d,"%d ",ptr->data); 
        printf("%d ",ptr->data); 
        ptr=ptr->next;  
    } 
    fprintf(f_d," \n");
    printf(" \n");
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
                printf("found %d\n",value); 
                flag=true;  
                break;  
            }     
            ptm = ptm -> next;  
        }  
        if(flag==false)  
        {  
            fprintf(f_d,"not found %d\n",value);  
            printf("not found %d\n",value);
          
    }          
}
int main(int argcom, char* argvalue[]){
  FILE *fpoin,*f_q,*f_s,*f_d;  
  printf("Value at argv[0]= %s\n",argvalue[0]);
  printf("Value at argv[1]= %s\n",argvalue[1]); 
  printf("Value at argv[2]= %s\n",argvalue[2]);
  int d=atoi(argvalue[2]);
  printf("%d\n",d);

//f_s= fopen("stack.txt","w");
//f_q=fopen("queue.txt","w");
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
          //Enqueue(f_q,value);
          Insert(f_d,value);
          break;
        case '-':
            //fprintf(f_s,"Popped %d\n", pop(f_s));
            //t--;
            //Dequeue(f_q);
            Delete(f_d,value);
            break;
        case '!':
            //display(f_s);
            //PrintQ(f_q);
            displayD(f_d);
            break;
        case '?':
            //search(f_q,value);
            //searchQ(f_q,value);
            searchD(f_d,value);
            break;
        }
   }

  fclose(fpoin);
  //fclose(f_s);
  //fclose(f_q);
  fclose(f_d);
 return 0;
}

