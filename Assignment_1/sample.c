#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void toh(int,char,char,char);

int main(int argc, char *argv[]){
    // printf("enter the no.of disks\n");
    //scanf("%d",&n);
    FILE *f_o;
    int n=atoi(argv[1]);
    toh(n,'a','b','c');
    f_o= fopen("toh.txt","w");//writing to a file

    if (f_o==NULL){
        printf("Error opening file.\n");
        return 1;//to check if output.txt file can open or not
    }
    else{
        //putting the outputs into the file using fprintf 
        toh(n,'A','C','B');
        fprintf(f_o,"%s\n",*bufferval);
        printf("Program ran Successfully");
    }
    
    //closing the file
    fclose(f_o);
    return 0;
}

void toh (int n,char source_stack,char dest_stack,char aux_stack) {
if (n == 1) { /* base case */
move disk from source_stack to dest_stack;
//pop disk 1 from stack A
//push disk 1 to stack C
}
else /* recursion case */
{
toh(n - 1, source_stack, aux_stack, dest_stack)
move disk from source_stack to dest_stack;
toh(n - 1, aux_stack, dest_stack, source_stack)
}

}