#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];
void countingsort(int num[],int s,int count){
       int ax[count];
       int i,cnt[10]={0};
       int ep=1;
       for(i=1;i<s;i++){
        ep=ep*10;
       }
       for(i=0;i<count;i++){
        cnt[(num[i]/ep)%10]++;}
        for (i=1;i<10;i++){
            cnt[i]+=cnt[i-1];}
            for(i=count-1;i>=0;i--){
                ax[cnt[(num[i]/ep)%10]-1]=num[i];
                cnt[(num[i]/ep)%10]--;}
                for(i=0;i<count;i++){
                    num[i]=ax[i];}
}

int radixsort(int num[],int d,int count){
    for(int i=1;i<=d;i++){
        countingsort(num,i,count);
    }
}

/*void print(int num[],int count){
    for (int i=0;i<count;i++)
    {
        printf("%d\n",num[i]);
    }  
}*/
int main(int argcom, char* argvalue[]){
  FILE *fpoin,*f_o,*f_r;   // File Pointers for reading and writing 
  int n;
  int count=0;
  int size=0;
  printf("Value at argv[0]= %s\n",argvalue[0]); //To verify your 1st Command Line Argument
  printf("Value at argv[1]= %s\n",argvalue[1]); // To verify your 2nd Command Line Argumnent
  printf("Value at argv[2]= %s\n",argvalue[2]); // To verify your 3rd Command Line Argumnent
  //printf("Value of argc =%d\n",argcom);  // # of arugments passed through Command Line
  int d=atoi(argvalue[2]);
  printf("%d\n",d);

fpoin= fopen (argvalue[1],"r");   //To read the provided input file
if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);//To check what happens when input is not provided through command line
	}
   while(fgets(bufferval,BSIZE,fpoin)!=NULL){
    count++;
    }
    fclose(fpoin);

int num[count];
f_o= fopen (argvalue[1],"r");
    if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);//To check what happens when input is not provided through command line
	}
   while(fgets(bufferval,BSIZE,fpoin)!=NULL){
    num[size]=atoi(bufferval);
    size++;
   }
radixsort(num,d,count);
//print(num,count); 
f_r= fopen("radix.txt","w");  // Write to file ,. 'a'-->append mode
if (f_r==NULL){
        printf("Error opening file.\n");
        return 1;//to check if output.txt file can open or not
    }
    else{
        for (int i = 0; i < count; i++)
        {
             fprintf(f_r,"%d\n",num[i]);
        }
    }


  fclose(f_r);
  fclose(f_o);
 return 0;
}