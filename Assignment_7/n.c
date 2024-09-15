#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define Hash_table_Size 11

typedef struct node{
    int value;
    struct node* next;
}node;
void insert(node** head,int new_value){
    node* new_node=malloc(sizeof(node*));
    new_node->value=new_value;
    // new_node->next=NULL;
    new_node->next=*head;
    *head=new_node;
    // if(*head==NULL){
    //     *head=new_node;
    // }
    // else{
    //     node* current=*head;
    //      while(current->next!=NULL){
    //          current=current->next;
    //      }
    //     current->next=new_node;
    // }
}

int get_location(int new_value){
    if(new_value<0){
          new_value*=-1;
    }
    return new_value%Hash_table_Size;
}

void insert_into_table(node** hashtable,int new_value){
    int location=get_location(new_value);
    if (hashtable[location]==NULL){
        hashtable[location]=malloc(sizeof(node*));
        node *head=NULL;
        insert(&head,new_value);
        hashtable[location]=head;
    }
    else{
        node* head=hashtable[location];
        insert(&head,new_value);
        hashtable[location]=head;
    }

}

void display(node** hashtable){
    for(int i=0;i<Hash_table_Size;i++){
        node* head=hashtable[i];
        printf("%d: ",i);
        if(head==NULL){
            printf("NULL");
        }
        else{
            node* current=head;
            while(current!=NULL){
                printf("%d ",current->value);
                current=current->next;
            }
        }
        printf("\n");
    }
}

node* get_hashtable(){
    node** hashtable=calloc(Hash_table_Size,sizeof(node*));
    return hashtable;
}

int main(){
   
    node** table=get_hashtable();
    insert_into_table(table,0);
    insert_into_table(table,2);
    insert_into_table(table,78);
    insert_into_table(table,12);
    insert_into_table(table,9);
    insert_into_table(table,6);
    insert_into_table(table,4);
    insert_into_table(table,1);
    insert_into_table(table,5);
    insert_into_table(table,9);
    insert_into_table(table,10);
    insert_into_table(table,11);
    insert_into_table(table,-30);
    insert_into_table(table,8);
    insert_into_table(table,8);
    insert_into_table(table,4);
    insert_into_table(table,9);
    insert_into_table(table,5);
    display(table);
// node *head=NULL;
// insert(&head,5);
// insert(&head,6);
// printf("%d\n",head->value);
// printf("%d\n",head->next->value);

    return 0;
}