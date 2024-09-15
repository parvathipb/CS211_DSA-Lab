#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];

typedef struct node{
    char *value;
    struct node* next;
}node;

void insert(node** head,char *new_value){
    node* new_node=malloc(sizeof(node*));
    new_node->value = (char*) malloc (strlen(new_value)+1);
    strcpy(new_node->value,new_value);
    new_node->next=*head;
    *head=new_node;
    //printf("inserted %s\n",new_value);
}

void insert_into_table(node** hashtable,char *new_value,int sum,int Hash_table_Size){
    int location=sum%Hash_table_Size;
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

node** get_hashtable(int Hash_table_Size){
    node** hashtable=calloc(Hash_table_Size,sizeof(node*));
    return hashtable;
}

void sortArr(char a[]) {
  int temp = 0, i, l;
  // below used logic is of bubble sort 
  for (i = 0; i < strlen(a) - 1; i++) {
    for (l = i + 1; l < strlen(a); l++) {
      if (a[i] > a[l]) {
        temp = a[i];
        a[i] = a[l];
        a[l] = temp;

      }
    }
  }
}

int isAnagram(char a[], char t[]) {
 int i = 0;
char b[50];
strcpy(b,t);
  int freq_a[26] = {0};
  int freq_b[26] = {0};
  // converting uppercase to lowercase
  while (a[i] != '\0') {
    if (a[i] >= 'A' && a[i] <= 'Z') {
      a[i] = 'a' + (a[i] - 'A');
    }
    i++;
  }

  i = 0;
  // converting uppercase to lowercase
  while (b[i] != '\0') {
    if (b[i] >= 'A' && b[i] <= 'Z') {
      b[i] = 'a' + (b[i] - 'A');
    }
    i++;
  }

  sortArr(a); // sorting the string
  sortArr(b); // sorting the string
  for (i = 0; i < strlen(a); i++) {
    if (a[i] != b[i]) {
      return 0;
    }
  }

  return 1;
}

void display(node** hashtable,int Hash_table_Size){
    for(int i=0;i<Hash_table_Size;i++){
        node* head=hashtable[i];
        printf("%d: ",i);
        if(head==NULL){
            printf("NULL");
        }
        else{
            node* current=head;
            while(current!=NULL){
                printf("%s ",current->value);
                current=current->next;
            }
        }
        printf("\n");
    }
}

void print_anagrams(FILE *f_a,node** hashtable,int key,char *string2){
       node* head=hashtable[key];
       if(head==NULL){
            //fprintf(f_a,"");
        }
        else{
            node* current=head;
            while(current!=NULL){
                if(isAnagram(string2,current->value)==1){
                   fprintf(f_a,"%s ",current->value);
                   //printf("%s ",current->value);
                }
                // printf("%s \t",current->value);
                current=current->next;
            }
        }
        fprintf(f_a,"\n");
        //printf("\n");
}

int main(int argcom, char* argvalue[]){
    FILE *fpoin,*f_a,*f_q;//*f_r,*f_p,*f_z;
    printf("Value at argv[0]= %s\n",argvalue[0]);
    printf("Value at argv[1]= %s\n",argvalue[1]); 
    printf("Value at argv[2]= %s\n",argvalue[2]); 
    printf("Value at argv[3]= %s\n",argvalue[3]); 
int m=atoi(argvalue[2]);
printf("%d\n",m);
node** table=get_hashtable(m);

f_a= fopen("anagrams.txt","w");
f_q=fopen(argvalue[3],"r");
//f_r=fopen("display.txt","w");
//f_p=fopen("p.txt","w");
// f_z=fopen("z.txt","w");
fpoin= fopen (argvalue[1],"r");  

if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	}
  else{ 
  while(fgets(bufferval,BSIZE,fpoin)!=NULL){
    char *string1;
    string1=strtok(bufferval,"\n");
    int len=strlen(string1);
    int sum=0;
    //printf("hello");
    for(int i=0;i<len;i++){
        sum=sum+string1[i];
    }
    sum-=10;
    // fprintf(f_z,"%d\n",sum);
    //printf("%d",sum);
    insert_into_table(table,string1,sum,m);
  }
   //display(table,m);
  }
  fclose(fpoin);

if(f_q==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	} 
  while(fgets(bufferval,BSIZE,f_q)!=NULL){
    char *string2;
    string2=strtok(bufferval,"\n");
    int n=strlen(string2);
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+string2[i];
    }
    int key =sum%m;
    print_anagrams(f_a,table,key,string2);
  }

fclose(f_q);
fclose(f_a);
return 0;

}