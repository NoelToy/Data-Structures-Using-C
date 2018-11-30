#include<stdio.h>

#define MAXSIZE 10

int queue[MAXSIZE];

int front=-1;
int rear=-1;

void enqueue(int data);
void dequeue();
void peek();
int isempty();
int isfull();

void main()
{
	int ch,data;
	do
	{
		printf("\n1.Enqueue\n");
		printf("\n2.Dequeue\n");
		printf("\n3.Front Element\n");
		printf("\n4.Exit\n");
		
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
					A:
					printf("\nEnter the data:");
					while(scanf("%d",&data)!=1)
					{
						printf("\nInvalid Data\n");
						fflush(stdin);
						goto A;
					}
					enqueue(data);
					/*printf("\nFront is:%d\n",front);
					printf("\nRear is:%d\n",rear);*/
			break;
			case 2:
					dequeue();
					/*printf("\nFront is:%d\n",front);
					printf("\nRear is:%d\n",rear);*/
			break;
			case 3:
					peek();
			break;
			case 4:
					printf("\nExiting!!!!!\n");
			break;
			default:printf("\nInvalid Choice!!!!\n");
					
		}
	}while(ch!=4);
	getch();
}

int isempty()
{
	if(front==-1 || front>rear)
	{
		return 1;
	}
	else
		return 0;
}

int isfull()
{
	if(rear==MAXSIZE-1)
	{
		return 1;
	}
	return 0;
}
void enqueue(int data)
{
	if(isfull()==1)
	{
		printf("\nQueue Overflow\n");
		return;
	}
	if(isempty()==1)
	{
		++front;
		++rear;
		queue[rear]=data;
		return;
	}
	++rear;
	queue[rear]=data;
}
void dequeue()
{
	int data;
	if(isempty()==1)
	{
		printf("\nQueue Underflow\n");
		return;
	}
	data=queue[front];
	front=front+1;
	printf("\nThe dequeued data is: %d",data);
	if(isempty()==1)
	{
		front=-1;
		rear=-1;
	}
}
void peek()
{
	int data;
	if(isempty()==1)
	{
		printf("\nQueue Underflow\n");
		return;
	}
	data=queue[front];
	printf("\nThe front element is: %d\n",data);
}



