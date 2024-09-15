/*CircularQueueOpsArrays.c:: */
#include "stdio.h"
#include "stdlib.h"

void Enqueue();
void Dequeue();
void PrintQ();
int* Queue;
int QSize;
int Head = -1;
int Tail = -1;
int main(int argc, char* argv[])
{
	int Op;

	if(argc < 2)
	{
		printf("Please Enter the Queue size...\n");
		printf("Usage is: %s <Queue Size> \n", argv[0]);
		exit(0);
	}	
	
	QSize = atoi(argv[1]);

	Queue = (int*)malloc(QSize*sizeof(int));
	while(1)
	{
		printf("Enter the Queue operation as below:\n");	
		printf("1.Enqueue...\n");	
		printf("2.Dequeue...\n");	
		printf("3.Print...\n");	
		printf("4.Exit...\n");	
		scanf("%d", &Op);

		switch(Op)
		{
			case 1:
				Enqueue();
			break;
			case 2:
				Dequeue();
			break;
			case 3:
				PrintQ();
			break;
			case 4:
			default:
				exit(0);
			break;
		}
	}

}


int IsQFull()
{
	if((Tail+1)%QSize == Head)
		return 1;
	else
		return 0;
}

void Enqueue()
{
	int Element;
	if(!IsQFull())
	{
		printf("Enter the element to be Enqueued...\n");	
		scanf("%d", &Element);
		Tail++;
		Tail = Tail%QSize;
		Queue[Tail] = Element;
  
		if(Head == -1)
		Head++;
	}
	else
		printf("Element cannot be inserted as Queue is full\n");
}



int IsQEmpty()
{
	if((Head == -1))
		return 1; 		
	else
		return 0;
}

void Dequeue()
{
	if(!IsQEmpty())
	{
		//Queue[Head] = -1;
		if(Head == Tail)/*That means only one element is present*/
		{
      printf("%d is deleted from the queue\n", Queue[Head]);
      Queue[Head] = -1;
			Head = Tail = -1;
		}
		else
		{
      printf("%d is deleted from the queue\n", Queue[Head]);
      Queue[Head] = -1;
			Head++;
			Head = Head%QSize;
		}
	}
	else
	{
		printf("Element cannot be deleted as Queue is already empty \n");
	}
}


void PrintQ()
{
	int i;

	printf("The elements of Queue are:\n");
	for(i=0; i<QSize; i++)
	printf("Queue[%d] = %d\n", i, Queue[i]);

	printf("Head is: %d\n", Head);
	printf("Tail is: %d\n", Tail);
}