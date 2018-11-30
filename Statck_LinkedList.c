#include<stdio.h>


struct node
{
	int data;
	struct node *next;
}*top=NULL;


void push();
void pop();
void peek();


void main()
{
	int ch;
	
	do
	{
		printf("\n1.Push\n");
		printf("\n2.Pop\n");
		printf("\n3.Peek\n");
		printf("\n4.Exit\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
					push();
			break;
			case 2:
					pop();
			break;
			case 3:
					peek();
			break;
			case 4:
					printf("\nExited......\n");
			break;
			default:
					printf("\nInvalid Choice!!\n");
			
		}
		
	}while(ch!=4);
	getch();
}


void push()
{
	int data;
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	
	printf("\nEnter the data:");
	scanf("%d",&data);
	newnode->data=data;
	
	if(top==NULL)
	{
		newnode->next=NULL;
		top=newnode;
		return;
	}
	newnode->next=top;
	top=newnode;
}

void pop()
{
	int data;
	if(top==NULL)
	{
		printf("\nStatck Underflow\n");
		return;
	}
	data=top->data;
	printf("\nThe data poped is:%d\n",data);
	top=top->next;
}

void peek()
{
	int data;
	if(top==NULL)
	{
		printf("\nStatck Underflow\n");
		return;
	}
	data=top->data;
	printf("\nThe top element is:%d\n",data);
}

