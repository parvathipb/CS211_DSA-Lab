#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];
int z;
void dfs(int u, int n, int **array1,int *s,int *res) { /* DFS */
 
    int v;
    s[u] = 1;
    for (v = 0; v < n - 1; v++) {
        if (array1[u][v] == 1 && s[v] == 0) {
            dfs(v, n, array1,s,res);
        }
    }
    z += 1;
    res[z] = u;
}
 
void topological_order(int n, int **array1,int *s,int *res) { /* TO FIND TOPOLOGICAL ORDER*/
 
    int i, u;   
    for (i = 0; i < n; i++) {
        s[i] = 0;
    }
    z = 0;
    for (u = 0; u < n; u++) {
        if (s[u] == 0) {
            dfs(u, n, array1,s,res);
        }
    }
    return;
} 

int main(int argcom, char* argvalue[]){
    FILE *fpoin,*f_t;
    printf("Value at argv[0]= %s\n",argvalue[0]);
    printf("Value at argv[1]= %s\n",argvalue[1]);  
int n,m,i,j,count=0,k=0,l=0;
f_t= fopen("ts.txt","w");
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
        count++;
    }
    else{
      break;
    }
  }
  fclose(fpoin);
int *array1[n];
for (i = 0; i < n; i++){
 array1[i] = (int*)malloc(n * sizeof(int));
}
// for(i=0;i<n;i++){
//  for(j=0;j<n;j++){
//    array1[i][j]=0;
//   }
// }
int *res = (int*)malloc(n * sizeof(int));
int *s = (int*)malloc(n * sizeof(int));
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
        l++;
           // fprintf(f_t,"%d\n",num1);
           // fprintf(f_t,"%d\n",num2);
    }
    }
    //for(i=0;i<n;i++){
    //for(j=0;j<n;j++){
    //   fprintf(f_t,"%d\n",array1[i][j]);
    //   }
    // }
    topological_order(n, array1,s,res);
    for (i = n; i >= 1; i--) {
        fprintf(f_t,"%d\n", res[i]);
    }
    fclose(fpoin);
    fclose(f_t);
    return 0;
}