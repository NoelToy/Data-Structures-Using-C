#include<stdio.h>
void display();
void push();
void pop();
void peek();
int top=-1;
int stack[10];

void main()
{
	int ch;
	
	do
	{
		printf("\n1.Push\n");
		printf("\n2.Pop\n");
		printf("\n3.Peek\n");
		printf("\n4.Display\n");
		printf("\n5.Exit\n");
		
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
					display();
			break;
			case 5: printf("\nExiting.....\n");
			break;
			default: printf("\nInvalid Choice!!!!!\n");
		}
	}while(ch!=5);
	getch();
}

void push()
{
	int item;
	if(top==9)
	{
		printf("\nStack Overflow!!\n");
		return;
	}
	printf("\nEnter the item:");
	scanf("%d",&item);
	top=top+1;
	stack[top]=item;
}
void pop()
{
	int item;
	
	if(top==-1)
	{
		printf("\nStack Underflow!!\n");
		return;
	}
	item=stack[top];
	printf("\nThe item poped is:%d\n",item);
	top=top-1;
}
void display()
{
	int i;
	
	if(top==-1)
	{
		printf("\nThe Stack is empty!!!\n");
		return;
	}
	printf("\nThe Stack elements are:\n");
	for(i=top;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
}
void peek()
{
	int item;
	if(top==-1)
	{
		printf("\nThe Stack is empty!!!\n");
		return;
	}
	item=stack[top];
	printf("\nThe top element is:%d\n",item);
}

