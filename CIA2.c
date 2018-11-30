#include<stdio.h>

struct node
{
	int data;
	struct node *next;
}*head;

void insert_start();
void insert_middle();
void delete_start();
void delete_middle();
int count(); 
void display();

void shift();


void main()
{
	int size,i,ch;
	head=NULL;
	
	do
	{
		printf("\n1.Insert In Start\n");
		printf("\n2.Insert In Middle\n");
		printf("\n3.Delete In Start\n");
		printf("\n4.Delete In Middle\n");
		printf("\n5.Shift\n");
		printf("\n6.Exit\n");
		
		printf("\nEnter your choice:\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
					insert_start();
			break;
			case 2:
					insert_middle();
			break;
			case 3:
					delete_start();
			break;
			case 4:
					delete_middle();
			break;
			case 5:
					shift();
			break;
			case 6:
					printf("\nExiting....\n");
			break;
			default:
					printf("\n Invalid Choice!!!\n");
		}
		
	}while(ch!=6);
	getch();
}

void insert_start()
{
	 int data;
	 struct node *newnode;
	 newnode=malloc(sizeof(struct node));
	 
	 printf("\nEnter the data:");
	 scanf("%d",&data);
	 
	 newnode->data=data;
	 newnode->next=NULL;
	 
	 if(head==NULL)
	 {
	 	head=newnode;
	 	display();
	 	return;
	 }
	 
	 newnode->next=head;
	 head=newnode;
	 display();
}

void insert_middle()
{
	int data,pos,i=1;
	struct node *newnode,*cur;
	newnode=malloc(sizeof(struct node));
	
	cur=head;
	if(head==NULL)
	{
		insert_start();
		return;
	}
	printf("\nEnter the value for pos:");
	scanf("%d",&pos);
	
	if(pos>0 && pos<=count())
	{
		if(pos==1)
		{
			insert_start();
			return;
		}
		printf("\nEnter the data:");
		scanf("%d",&data);
		 
		newnode->data=data;
		newnode->next=NULL;
		
		while(i<pos-1)
		{
			cur=cur->next;
			i++;
		}
		newnode->next=cur->next;
		cur->next=newnode;
		display();
	}
	else
	{
			printf("\nInvalid Position!!!!");
	}
	
}

void delete_start()
{
	int data;
	if(head==NULL)
	{
		printf("\nThe Linked List is Empty!!!\n");
		return;
	}
	data=head->data;
	head=head->next;
	printf("The deleted data is:%d\n",data);
	display();
}
void delete_middle()
{
	int data,pos,i=1;
	struct node *cur;
	cur=head;
	if(head==NULL)
	{
		printf("\nThe Linked List is Empty!!!\n");
		return;
	}
	printf("\nEnter the value for pos:");
	scanf("%d",&pos);
	
	if(pos>0 && pos<=count())
	{
		//printf("\nhai!!!\n");
		if(pos==1)
		{
			delete_start();
			return;
		}
		
		while(i<pos-1)
		{
			cur=cur->next;
			i++;
		}
		data=cur->next->data;
		cur->next=cur->next->next;
		printf("The deleted data is:%d\n",data);
		display();
	}
	else
	{
			printf("\nInvalid Position!!!!");
	}
	
}

void shift()
{
	
	int k,i=1;
	
	struct node *temp;
	struct node *cur;
	
	temp=head;
	cur=head;
	if(head==NULL)
	{
		printf("\nThe Linked List is Empty!!!\n");
		return;
	}
	
	printf("\nEnter the value for k:");
	scanf("%d",&k);
	if(k>count())
	{
		printf("\nk value should be less than %d!!!\n",count());
		return;
	}
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	temp->next=head;
	while(i<k)
	{
		cur=cur->next;
		i++;
	}
	head=cur->next;
	cur->next=NULL;
	display();
}
int count()
{
	int c=0;
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		return c;
	}
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}

void display()
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nThe Linked List is Empty!!!\n");
		return;
	}
	printf("\nThe Linked List is:\n");
	while(temp!=NULL)
	{
		printf("\n%d\n",temp->data);
		temp=temp->next;
	}
}

