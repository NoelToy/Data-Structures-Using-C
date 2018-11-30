#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *nxt;
};
void insert_front(struct node **headref);
void insert_middle(struct node **headref);

void delete_front(struct node **headref);
void delete_middle(struct node **headref);

void display(struct node *head);
int count(struct node *head);

void main()
{
	int ch;
	struct node *head;
	head=NULL;
	
	do
	{
		printf("\n1.Insert Data in Front\n");
		printf("\n2.Insert Data in Front\n");
		printf("\n3.Delete Data form Front\n");
		printf("\n4.Delete Data form Middle\n");
		printf("\n5.Display The List\n");
		printf("\n6.Exit\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
					insert_front(&head);
			break;
			case 2:
					insert_middle(&head);
			break;
			case 3:
					delete_front(&head);
			break;
			case 4:
					delete_middle(&head);
			break;
			case 5:
					display(head);
			break;
			case 6:
					printf("\nExiting!!!\n");
			break;
			default :
					printf("\nInvalid Choice!!!\n");
		}
	}while(ch!=6);
}

void insert_front(struct node **headref)
{
	int data;
	struct node *newnode;
	struct node *temp=*headref;
	newnode=malloc(sizeof(struct node));
	
	printf("Enter the data:");
	scanf("%d",&data);
	
	newnode->data=data;
	newnode->nxt=NULL;
	
	if(temp==NULL)
	{
		*headref=newnode;
		newnode->nxt=*headref;
		return;
	}
	while(temp->nxt!=*headref)
	{
		temp=temp->nxt;
	}
	newnode->nxt=(*headref);
	(*headref)=newnode;
	temp->nxt=(*headref);
	
}

void insert_middle(struct node **headref)
{
	int data,pos,j=1;
	struct node *newnode;
	struct node *temp=*headref;
	if(*headref==NULL)
	{
		insert_front(headref);
		return;
	}
	printf("Enter the position:");
	scanf("%d",&pos);
	if(pos<=0 || pos >count(*headref))
	{
		printf("\nInvalid Position!!!\n");
		return;
	}
	if(pos==1)
	{
		insert_front(headref);
		return;
	}
	printf("Enter the data:");
	scanf("%d",&data);
	newnode=malloc(sizeof(struct node));
	newnode->data=data;
	newnode->nxt=NULL;
	
	/*if(pos==count(*headref))
	{
		while(temp->nxt!=*headref)
		{
			temp=temp->nxt;
		}
		newnode->nxt=*headref;
		temp->nxt=newnode;
	}*/
	while(j<pos-1)
	{	
		temp=temp->nxt;
		j++;
	}
	newnode->nxt=temp->nxt;
	temp->nxt=newnode;
	
}

void delete_front(struct node **headref)
{
	int data;
	struct node *temp=*headref;
	if(*headref==NULL)
	{
		printf("\nThe List is Empty!!!\n");
		return;
	}
	data=(*headref)->data;
	printf("\nThe data deleted is:%d\n",data);
	
	if(count(*headref)==1)
	{
		*headref=NULL;
		return;
	}
	while(temp->nxt!=*headref)
	{
		temp=temp->nxt;
	}
	*headref=(*headref)->nxt;
	temp->nxt=*headref;
	
}

void delete_middle(struct node **headref)
{
	int data,pos,j=1;
	struct node *temp=*headref;
	if(*headref==NULL)
	{
		printf("\nThe List is Empty!!!\n");
		return;
	}
	printf("Enter the position:");
	scanf("%d",&pos);
	if(pos<=0 || pos >count(*headref))
	{
		printf("\nInvalid Position!!!\n");
		return;
	}
	if(pos==1)
	{
		delete_front(headref);
		return;
	}
	while(j<pos-1)
	{	
		temp=temp->nxt;
		j++;
	}
	if(pos==count(*headref))
	{
		data=temp->nxt->data;
		printf("\nThe data deleted is:%d\n",data);
		temp->nxt=*headref;
		return;
	}
	data=temp->nxt->data;
	printf("\nThe data deleted is:%d\n",data);
	temp->nxt=temp->nxt->nxt;
}


int count(struct node *head)
{
	int count=0;
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		return count;
	}
	do
	{
		count++;
		temp=temp->nxt;
	}while(temp!=head);
	return count;
}

void display(struct node *head)
{
	if(count(head)==0)
	{
		printf("\nEmpty\n");
		return;
	}
	struct node *temp;
	temp=head;
	do
	{
		printf("%d->",temp->data);
		temp=temp->nxt;
	}while(temp!=head);
	printf("X\n");
}
