/*Acknowledgement to GeeksforGeeks*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024
char bufferval[BSIZE];
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int num[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = num[l + i];
        for (j = 0; j < n2; j++)
        R[j] = num[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            num[k] = L[i];
            i++;
        }
        else {
            num[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        num[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        num[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int num[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(num, l, m);
        mergeSort(num, m + 1, r);
        merge(num, l, m, r);
    }
}
 
int main(int argcom, char* argvalue[]){
    FILE *fpoin,*f_o,*f_m;
    int count=0;
    int size=0;
    char filename[1024];
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
   /* for(int i=0;i<count;i++){
      printf("%d\n",num[i]);
   }*/
mergeSort(num, 0, count - 1);

f_m= fopen("mergesort.txt","w");
if (f_o==NULL){
        printf("Error opening file.\n");
        return 1;//to check if output.txt file can open or not
    }
    else{
        for (int i = 0; i < count; i++)
        {
             fprintf(f_m,"%d\n",num[i]);
        }
    }
    fclose(f_m);
    fclose(f_o);
    return 0;
}