#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
void display(struct node *);
void insert(struct node *);
int length(struct node *);
void main()
{
	struct node *head;
	int count;
	char ch;
	int item;
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
	count=length(head);
	//printf("The data of the head is: %d\n",head->data);
	//printf("The data of the node1 is: %d\n",node1->data);
	
	printf("The number of nodes is: %d\n",count);
	getch();
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
int length(struct node *head)
{
	int count=0;
	struct node *temp;
	temp=head;
	
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
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
