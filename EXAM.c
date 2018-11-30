#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *pre;
	struct node *next;
};

void insert_front(struct node **headref);
void display(struct node *head);

void merge(struct node **headref1,struct node **headref2);

void sorter(struct node **headref,int size);

void main()
{
	int size1,size2,i;
	
	struct node *head1;
	struct node *head2;
	
	head1=NULL;
	head2=NULL;
	
	printf("\nEnter the size:");
	scanf("%d",&size1);
	
	for(i=0;i<size1;i++)
	{
		insert_front(&head1);
	}
	
	printf("\n***************************************\n");
	printf("\nEnter the size:");
	scanf("%d",&size2);
	for(i=0;i<size2;i++)
	{
		insert_front(&head2);
	}
	printf("\n***************************************\n");
	printf("\nFirst List is\n");
	printf("\n***************************************\n");
	display(head1);
	
	printf("\n***************************************\n");
	printf("\nSecond List is\n");
	printf("\n***************************************\n");
	display(head2);
	
	merge(&head1,&head2);
	printf("\n***************************************\n");
	printf("\nMerged List is\n");
	printf("\n***************************************\n");
	display(head1);

	sorter(&head1,size1+size2);
	printf("\n***************************************\n");
	printf("\nSorted List is\n");
	printf("\n***************************************\n");
	display(head1);
	
	
	getch();
}

void insert_front(struct node **headref)
{
	int data;
	
	struct node *head;
	head=*headref;
	
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	
	printf("\nEnter the data:");
	scanf("%d",&data);
	
	newnode->data=data;
	newnode->next=NULL;
	newnode->pre=NULL;
	
	if(*headref==NULL)
	{
		*headref=newnode;
		return;
	}
	
	newnode->next=*headref;
	head->pre=newnode;
	*headref=newnode;
}

void display(struct node *head)
{
	struct node *temp;
	temp=head;
	printf("\nThe data items are:\n");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("X");
}

void merge(struct node **headref1,struct node **headref2)
{
	struct node *head1;
	struct node *head2;
	struct node *temp;
	
	head1=*headref1;
	head2=*headref2;
	
	temp=head1;
	
	while(temp->next !=NULL)
	{
		temp=temp->next;
	}
	temp->next=head2;
	head2->pre=temp;
}

void sorter(struct node **headref,int size)
{
	int temp;
	struct node *head;
	head=*headref;
	
	struct node *slow;
	struct node *fast;
	
	slow=head;
	
	while(slow!=NULL)
	{
		fast=slow->next;
		while(fast!=NULL)
		{
			if(slow->data >= fast->data)
			{
				temp=slow->data;
				slow->data=fast->data;
				fast->data=temp;
			}
			fast=fast->next;
		}
		slow=slow->next;
	}	
}


