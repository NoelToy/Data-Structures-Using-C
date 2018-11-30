#include<stdio.h>

struct student
{
	char name[20];
	char subname[20];
	int mark;

}stack[10];

void display();
void push();
void pop();
void peek();
int top=-1;
//int stack[10];

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
	if(top==9)
	{
		printf("\nStack Overflow!!\n");
		return;
	}
	/*printf("\nEnter the item:");
	scanf("%d",&item);*/
	top=top+1;
	printf("\nEnter Student Name : ");
	scanf(" %s", &stack[top].name);
	printf("\nEnter Subject Name : ");
	scanf(" %s", &stack[top].subname);
	printf("\nEnter Mark : ");
	scanf("%d", &stack[top].mark);
	printf("\n");
}
void pop()
{
	if(top==-1)
	{
		printf("\nStack Underflow!!\n");
		return;
	}
	//item=stack[top];
	printf("\nThe item poped is:\n");
	
	printf("\nStudent Name :%s",stack[top].name);
	printf("\nSubject Name :%s",stack[top].subname);
	printf("\nMarks :%d",stack[top].mark);
	
	
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
		printf("\n%s\t%s\t%d",stack[i].name,stack[i].subname,stack[i].mark);
	}
}
void peek()
{
	if(top==-1)
	{
		printf("\nThe Stack is empty!!!\n");
		return;
	}
	printf("\n%s\t%s\t%d\n",stack[top].name,stack[top].subname,stack[top].mark);
}
