#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *pre;
	struct node *next;
};

void insert_end(struct node **headref,int data);

void display(struct node *head);

void merge(struct node *head1,struct node *head2,struct node **meregeheadref);


void main()
{
	int size1,size2,i,data;
	
	struct node	*head1;
	struct node *head2;
	struct node *mergehead;
	
	head1=NULL;
	head2=NULL;
	mergehead=NULL;
	
	printf("\nEnter the size of the list:");
	scanf("%d",&size1);
	
	for(i=0;i<size1;i++)
	{
		printf("\nEnter the data:");
		scanf("%d",&data);
		insert_end(&head1,data);
	}
	
	printf("\nEnter the size of the list:");
	scanf("%d",&size2);
	
	for(i=0;i<size2;i++)
	{
		printf("\nEnter the data:");
		scanf("%d",&data);
		insert_end(&head2,data);
	}
	printf("\nThe First List is:\n");
	display(head1);
	printf("\nThe Second List is:\n");
	display(head2);
	
	merge(head1,head2,&mergehead);
	printf("\nThe Third List is:\n");
	display(mergehead);
	
	getch();
}
void insert_end(struct node **headref,int data)
{
	struct node *temp=*headref;
	
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	
	newnode->data=data;
	newnode->pre=NULL;
	newnode->next=NULL;
	
	if(*headref==NULL)
	{
		*headref=newnode;
		return;
	}
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	newnode->pre=temp;
	temp->next=newnode;
}

void merge(struct node *head1,struct node *head2,struct node **meregeheadref)
{
	struct node *temp1=head1;
	struct node *temp2=head2;
	
	while(temp1!=NULL && temp2!=NULL)
	{
		if(temp1->data <= temp2->data)
		{
			insert_end(meregeheadref,temp1->data);
			temp1=temp1->next;
		}
		else
		{
			insert_end(meregeheadref,temp2->data);
			temp2=temp2->next;
		}
	}
	
	while(temp1!=NULL)
	{
		insert_end(meregeheadref,temp1->data);
		temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
		insert_end(meregeheadref,temp2->data);
		temp2=temp2->next;
	}
}

void display(struct node *head)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("X");
}

