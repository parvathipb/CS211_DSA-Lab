#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];
int i=1;
int*ptr;

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Insert a node
struct node *insert(struct node *node, int key) {
  if (node == NULL) return newNode(key);
  if (key < node->key)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

void inorder(FILE *f_b,struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(f_b,root->left);
    // Traverse root
    fprintf(f_b,"%d ", root->key);
    // Traverse right
    inorder(f_b,root->right);
  }
}

void preorder(FILE *f_b,struct node *root){
  if(root !=NULL){
    fprintf(f_b,"%d ",root->key);
    preorder(f_b,root->left);
    preorder(f_b,root->right);
  }
}

void postorder(FILE *f_b,struct node *root){
  if(root !=NULL){
    postorder(f_b,root->left);
    postorder(f_b,root->right);
    fprintf(f_b,"%d ",root->key);
  }
}

// Find the inorder successor
// struct node *minValue(struct node *node) {
//   struct node *current = node;
//   // Find the leftmost leaf
//   while (current && current->left != NULL){
//     current = current->left;
//   }
//   return current;
// }
void Min(FILE *f_b,struct node *min){
  while(min->left !=NULL){
    min=min->left;
  }
  fprintf(f_b,"%d\n",min->key);
}

void Max(FILE *f_b,struct node *max){
  while(max->right !=NULL){
    max=max->right;
  }
  fprintf(f_b,"%d\n",max->key);
}


void intra(struct node *traverse){
     if(traverse!=NULL){
      intra(traverse->left);
      int item=traverse->key;
      ptr[i-1]=item;
       ptr=(int*)realloc(ptr,((i+1)* sizeof(int)));
       i++;
        intra(traverse->right);
     }
}

void Predecessor(FILE *f_b,struct node *pred,int item){
     bool found=false;
       struct node *sear=pred;
       while(sear!=NULL){
              if(item == sear->key){
                if(sear->left!=NULL){
                  Max(f_b,sear->left);
                }
                else{
                        ptr=(int*)malloc(i*sizeof(int));
                       intra(pred);
                       for(int k=0;k<i-1;k++){
                        int n=ptr[k];
                        if(n==item && k!=0){
                          fprintf(f_b,"%d\n",ptr[k-1]);
                          break;
                        }
                        else if(n==item && k==0){
                            fprintf(f_b,"null\n");
                            break;
                        }
                       }
                       free(ptr);
                }
                found=true;
                break;
              }
              else if(item < sear->key){
                sear=sear->left;
              }
              else{
                sear=sear->right;
              }
       }

       if(found==false){
        fprintf(f_b,"%d does not exist\n",item);
       }
}

void Successor(FILE *f_b,struct node *suce,int item){
   bool found=false;
       struct node *sear=suce;
       while(sear!=NULL){
        if(item == sear->key){
             if(sear->right !=NULL){
              Min(f_b,sear->right);
             }
             else{
               ptr=(int*)malloc(i*sizeof(int));
                       intra(suce);
                       for(int k=0;k<i-1;k++){
                        int n=ptr[k];
                        int p=ptr[k+1];
                        if(n==item && k!=i-2){
                          fprintf(f_b,"%d\n",p);
                          break;
                        }
                        else if(n==item && k==i-2){
                          fprintf(f_b,"null\n");
                          break;
                        }
                       }
                       free(ptr);
             }
             found=true;
             break;
             }
        else if(item < sear->key){
          sear=sear->left;
        } 
        else{
          sear=sear->right;
        }
       }
       if(found==false){
        fprintf(f_b,"%d does not exist\n",item);
       }
}

void Search(FILE *f_b,struct node *sear,int item){
  bool found=false;
  while(sear!=NULL){
  if(item==sear->key){
    fprintf(f_b,"%d found\n",sear->key);
    found=true;
    break;
  }
  else if(item<sear->key){
    sear=sear->left;
  }
  else{
    sear=sear->right;
  }
  }
  if(found==false){
  fprintf(f_b,"%d not found\n",item);
  }
}


int main(int argcom, char* argvalue[]){
    FILE *fpoin,*f_b;
    printf("Value at argv[0]= %s\n",argvalue[0]);
    printf("Value at argv[1]= %s\n",argvalue[1]); 
struct node *root = NULL;

f_b= fopen("bst.txt","w");
fpoin= fopen (argvalue[1],"r");  
if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);
	} 
  while(fgets(bufferval,BSIZE,fpoin)!=NULL){
    char string[50];
    strcpy(string,bufferval);
    // printf("%s",string);
    char *token1 = strtok(string," ");
    char *token2=strtok(NULL," ");
    int numtok=atoi(token2);
    /*printf("%s",token1);
    printf("%s",token2);
    printf("%d",numtok);*/
        if(strcmp(token1,"insert")==0) {
          root=insert(root,numtok);
          fprintf(f_b,"%d inserted\n",numtok);
        }
        else if(strcmp(token1,"search")==0){
            Search(f_b,root,numtok);
        }
        else if(strcmp(token1,"inorder\n")==0){
            inorder(f_b,root);
            fprintf(f_b,"\n");
        }
        else if(strcmp(token1,"preorder\n")==0){
            preorder(f_b,root);
            fprintf(f_b,"\n");
        }
        else if(strcmp(token1,"postorder\n")==0){
            postorder(f_b,root);
            fprintf(f_b,"\n");
        }
        else if(strcmp(token1,"minimum\n")==0){
            Min(f_b,root);
        }
        else if(strcmp(token1,"maximum\n")==0){
            Max(f_b,root);
        }
        else if(strcmp(token1,"successor")==0){
            Successor(f_b,root,numtok);
        }
        else if(strcmp(token1,"predecessor")==0){
            Predecessor(f_b,root,numtok);      
        }
   }
   fclose(f_b);
   fclose(fpoin);
     return 0;
}

// Inorder Traversal
