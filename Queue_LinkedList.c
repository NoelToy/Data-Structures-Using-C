#include<stdio.h>

struct node
{
	int data;
	struct node *next;
};


struct node *front=NULL;
struct node *rear=NULL;
int count = 0;

void enqueue();
void dequeue();
void peek();

int isempty();


void main()
{
	int ch;
	
	do
	{
		printf("\n1.Enqueue\n");
		printf("\n2.Dequeue\n");
		printf("\n3.Peek\n");
		printf("\n4.Count\n");
		printf("\n5.Exit\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
					enqueue();
			break;
			case 2:
					dequeue();
			break;
			case 3:
					peek();
			break;
			case 4:
					printf("\nThe number of elements in the queue is:%d\n",count);
			break;
			case 5:
					printf("\nExiting......\n");
			break;
			default:
					printf("\nInvalid choice!!!!\n");
			
		}
	}while(ch!=5);
	
}

void enqueue()
{
	int data;
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	A:
	printf("\nEnter the data:");
	while(scanf("%d",&data)!=1)
	{
		printf("\nInvalid Data\n");
		fflush(stdin);
		goto A;
	}
	
	if(front==NULL && rear==NULL)
	{
		newnode->data=data;
		newnode->next=NULL;
		
		rear=newnode;
		front=newnode;
		count++;
		return;
		
	}
	newnode->data=data;
	newnode->next=NULL;
	rear->next=newnode;
	rear=newnode;
	count++;
}

void dequeue()
{
	int data;
	if(isempty()==1)
	{
		printf("\nThe Queue is Empty!!!\n");
		return;
	}
	data=front->data;
	printf("\nThe data dequeued is:%d\n",data);
	front=front->next;
	--count;
}
void peek()
{
	int data;
	if(isempty()==1)
	{
		printf("\nThe Queue is Empty!!!\n");
		return;
	}
	data=front->data;
	printf("\nThe data dequeued is:%d\n",data);
}
int isempty()
{
	if(front==NULL)
	{
		return 1;
	}
	return 0;
}
