/*Acknowledgement to stackoverflow.com;Porfolio courses(youtube);Programming Knowledge(youtube)*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define BSIZE 1024

int main(int argcom, char* argvalue[]){
    FILE *fpoin,*f_o; // File Pointers for reading and writing 
    
    char filename[1024];
    char bufferval[BSIZE];
    double currentnum,maxvalue,minvalue;
    int count =0;double sumofnum=0;//initially taken
    double averageofnum;



     fpoin= fopen (argvalue[1],"r");   //To read the provided input file
  if(fpoin==NULL)
	{
		printf("FILE NOT FOUND");
		exit(0);//To check what happens when input is not provided through command line
	}
    while(fgets(bufferval,BSIZE,fpoin)!=NULL){
        //performing necessary operations to get the required outputs
        currentnum=atof(bufferval);
        if(count==0){
            //initial conditions for finding max & min numbers in the file
            maxvalue=currentnum;
            minvalue=currentnum;
        }
        else if(currentnum>maxvalue){
            maxvalue=currentnum;
            }
        else if(currentnum<minvalue){
            minvalue=currentnum;
        }
        sumofnum+=atof(bufferval);//adding the values starting from first to last
        count++;//counting number of numbers in the file
         //counts when empty line is present in middle and considers that number as "0"
        //doesn't count from the last empty line in the file
    }

    averageofnum=sumofnum/count;

/*To check if outputs are obtained correctly
printf("count:%d\n",count);
printf("min:%.2f\n",minvalue);
printf("max:%.2f\n",maxvalue);
printf("sum:%.2f\n",sumofnum);
printf("average:%.2f\n",averageofnum);
*/
   
    f_o= fopen("output.txt","w");//writing to a file

    if (f_o==NULL){
        printf("Error opening file.\n");
        return 1;//to check if output.txt file can open or not
    }
    else{
        //putting the outputs into the file using fprintf 
        fprintf(f_o,"%d\n",count);
        fprintf(f_o,"%.0lf\n",minvalue);
        fprintf(f_o,"%.0lf\n",maxvalue);
        fprintf(f_o,"%.0lf\n",sumofnum);
        fprintf(f_o,"%.2lf\n",averageofnum);
        //printf("Program ran Successfully");
    }
    
    //closing the files
    fclose(fpoin);
    fclose(f_o);
    return 0;
    
}