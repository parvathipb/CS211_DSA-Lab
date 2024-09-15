#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];
struct node {
    int value;
    struct node * next;
};
const int W = 0;
const int G = 1;
const int B = 2;
struct node * head = NULL;
struct node * tail = NULL;
void enqueue(int data) {
  struct node * ptr;
  ptr = (struct node * ) malloc(sizeof(struct node));
  ptr-> value = data;
  ptr-> next = NULL;
  if ((head == NULL) && (tail == NULL)) {
      head = tail = ptr;   
  } 
  else {
    tail-> next = ptr;
    tail = ptr;   
    }
}
void dequeue() {
  struct node* q;
	q = head;
	if((head==NULL)&&(tail==NULL)){
	
    }
	else if(head == tail){
    int weight=head->value;
		head = tail = NULL;
		free(q);
	}
	else{
   int weight=head->value;
   head = head->next;
	free(q);
    }
}

int main(int argcom, char* argvalue[]){
    FILE *fpoin,*f_s;
    printf("Value at argv[0]= %s\n",argvalue[0]);
    printf("Value at argv[1]= %s\n",argvalue[1]);  
int n,m,*dist,count=0,k=0,l=0;
int *color;
f_s= fopen("sd.txt","w");
fpoin= fopen (argvalue[1],"r");  
if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	} 
  while(fgets(bufferval,BSIZE,fpoin)!=NULL){
    char string[50];
    strcpy(string,bufferval);
    char *token1 = strtok(string," ");
    char *token2=strtok(NULL," ");
    int num1=atoi(token1);
    int num2=atoi(token2);
    if(count==0){
        n=num1;
        m=num2;
        dist = (int*)malloc(n * sizeof(int));
        color = (int*)malloc(n * sizeof(int));
        count++;
    }
    else{
      break;
    }
  }
  fclose(fpoin);
        int *array1[n];
        for (int i = 0; i < n; i++){
        array1[i] = (int*)malloc(n * sizeof(int));
       }
fpoin= fopen (argvalue[1],"r");  
if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	} 
    while(fgets(bufferval,BSIZE,fpoin)!=NULL){
    char string[50];
    strcpy(string,bufferval);
    char *token1 = strtok(string," ");
    char *token2=strtok(NULL," ");
    int num1=atoi(token1);
    int num2=atoi(token2);
    if(k==0){
      k++;
    }
    else{
      if(l>=m){
        break;
      }
        array1[num1][num2]=1;
        array1[num2][num1]=1;
        l++;
          //  fprintf(f_s,"%d\n",num1);
          //  fprintf(f_s,"%d\n",num2);
    }
    }
   enqueue(0);
   dist[0]=0;
   int numb;
   while((head != NULL) && (tail != NULL)){
       numb=head->value;
       dequeue();
        for (int i = 0; i < n; i++) { 
            if ((array1[numb][i] == 1) && (color[i] == W)) {
                enqueue(i); 
                color[i] = G; 
                dist[i] = dist[numb] + 1;
                 }
        }
        color[numb] = B; 
    } 
    fprintf(f_s,"%d \n",dist[0]);
    for(int i=1;i<n;i++){
      if(dist[i]!=0){
      fprintf(f_s,"%d \n",dist[i]);
      }
      else{
        fprintf(f_s,"-1 \n");
      }
    }
}
