void Delete(FILE *f_d,int value)  
{  
    bool found=false;
if(head->data==value){
        struct node *temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=temp->prev=NULL;
        free(temp);
        found-true;     
    }
else{
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=value)
    {
       p=p->next;
       q=q->next;
       q->next->prev=p; 
       q->next=q->prev=NULL;
       free(q);
       found=true;
    }
  }
if(found==false){
  
}
}