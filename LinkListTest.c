#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
void insert(struct node **,int);
void display(struct node *);

void main()
{
	char ch;
	int item;
	struct node *head;
	head=NULL;
	
	do
	{
		printf("Enter the data:");
		scanf("%d",&item);
		insert(&head,item);
		
		printf("Do you want to continue?(Yy/nN):");
		scanf(" %c",&ch);
		
	}while(ch=='y'||ch=='Y');
	display(head);
	getch();
}

void insert(struct node **head,int item)
{
	struct node *tempnode;
	tempnode=malloc(sizeof(struct node));
	
	struct node *temp=*head;
	tempnode->data=item;
	tempnode->next=NULL;
	
	if(*head==NULL)
	{
		*head=tempnode;
		return;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=tempnode;
		return;
	}
	
}
void display(struct node *head)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("The data is: %d\n",temp->data);
		temp=temp->next;
	}
}


