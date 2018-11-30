#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
void insert(struct node *);
void display(struct node *);

void main()
{
	char ch;
	int item;
	struct node *head;
	head=NULL;
	
	printf("Enter the data:");
	scanf("%d",&item);
	head=malloc(sizeof(struct node));
	head->data=item;
	head->next=NULL;
	printf("Do you want to continue?(Yy/nN):");
	scanf(" %c",&ch);
	while(ch=='y'||ch=='Y')
	{
		insert(head);
		
		printf("Do you want to continue?(Yy/nN):");
		scanf(" %c",&ch);
	}
	display(head);
	getch();
}

void insert(struct node *head)
{
	struct node *temp,*tempnode;
	int item;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->next==NULL)
		{
			break;
		}
		temp=temp->next;
	}
	printf("Enter a the data:");
	scanf("%d",&item);
	tempnode=malloc(sizeof(struct node));
	tempnode->data=item;
	tempnode->next=NULL;
		
	temp->next=tempnode;
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


