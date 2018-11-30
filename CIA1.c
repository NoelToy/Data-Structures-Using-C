#include<stdio.h>

#define MAXSIZE 10

int stack[MAXSIZE];
int top=-1;

void push(int data);
int pop();


void main()
{
	int i,size,temp;
	int a[MAXSIZE];
	B:
	printf("\nEnter the size of the array:");
	scanf("%d",&size);
	if(size > MAXSIZE)
	{
		printf("\nThe size should be less than %d\n",MAXSIZE);
		goto B;
	}
	for(i=0;i<size;i++)
	{
		A:
		fflush(stdin);
		printf("\nEnter the value for a[%d]:",i);
		scanf("%d",&temp);
		if(i==0)
		{
			a[i]=temp;
		}
		else
		{
			if(temp<a[i-1])
			{
				printf("\nPlease Enter the values in assecnding order!!!\n");
				fflush(stdin);
				goto A;
			}
			else
			{
				a[i]=temp;
			}
		}
		push(a[i]);
	}
	
	printf("\nThe rearranged list is:\n");
	for(i=0;i<size;i++)
	{
		if(i%2==0)
		{
			a[i]=pop();
		}
	}
	for(i=size-1;i>=0;i--)
	{
		if(i%2!=0)
		{
			a[i]=pop();
		}
	}
	
	for(i=0;i<size;i++)
	{
		printf("\nEnter the value for a[%d]:%d\n",i,a[i]);
	}
	getch();
}

void push(int data)
{
	if(top==9)
	{
		printf("\nStack Overflow!!!\n");
		return;
	}
	top=top+1;
	stack[top]=data;
}
int pop()
{
	int data;
	if(top==-1)
	{
		printf("\nStack Underflow!!!\n");
		return;
	}
	data=stack[top];
	top=top-1;
	return data;
}
