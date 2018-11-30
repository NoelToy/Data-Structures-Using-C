#include<stdio.h>
struct node
{
	int data;
	struct node *pre;
	struct node *nxt;
}*head;


void insert_middle();
void insert_front();

void delete_middle();
void delete_front();
void delete_data();

void update_data();

void display();
int count();


void main()
{
	int ch;
	head=NULL;
	do
	{
		printf("\n1.Insert Data in Front\n");
		printf("\n2.Insert Data in Middle\n");
		printf("\n3.Delete Data form Front\n");
		printf("\n4.Delete Data form Middle\n");
		printf("\n5.Delete Data from List\n");
		printf("\n6.Update Data from List\n");
		printf("\n7.Display Doubly Linked List\n");
		printf("\n8.Exit\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
					insert_front();
			break;
			case 2:
					insert_middle();
			break;
			case 3:
					delete_front();
			break;
			case 4:
					delete_middle();
			break;
			case 5:
					delete_data();
			break;
			case 6:
					update_data();
			break;
			case 7:
					display();
			break;
			case 8:
					printf("\nExiting!!!\n");
			break;
			default:
					printf("Invalid Choice!!!\n");
				
		}
	}while(ch!=8);
	getch();
}


void insert_front()
{
	int data;
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	
	printf("\nEnter the data:");
	scanf("%d",&data);
	
	newnode->data=data;
	newnode->pre=NULL;
	newnode->nxt=NULL;
	
	if(head==NULL)
	{
		newnode->nxt=NULL;
		head=newnode;
	}
	else
	{
		newnode->nxt=head;
		head->pre=newnode;
		head=newnode;
	}
	
}
void insert_middle()
{
	int data,pos,j=1;
	struct node *cur;
	cur=head;
	
	if(head==NULL)
	{
		insert_front();
	}
	else
	{
		struct node *newnode;
		newnode=malloc(sizeof(struct node));
		
		printf("\nEnter the position:");
		scanf("%d",&pos);
		if(pos<=0 || pos >count())
		{
			printf("\nInvalid Position!!!\n");
			return;
		}
		
		if(pos==1)
		{
			insert_front();
			return;
		}
		
		printf("\nEnter the data:");
		scanf("%d",&data);
		
		newnode->data=data;
		newnode->pre=NULL;
		newnode->nxt=NULL;
		
		while(j<pos-1)
		{
			cur=cur->nxt;
			j++;
		}
		
		//newnode->pre=cur->nxt->pre;
		newnode->pre=cur;
		newnode->nxt=cur->nxt;
		
		cur->nxt->pre=newnode;
		cur->nxt=newnode;
		
	}
}
/*void display()
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->nxt;
	}
}*/

void display()
{
	if(head==NULL)
	{
		printf("\nEmpty\n");
		return;
	}
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->nxt;
	}
	printf("X\n");
}
int count()
{
	int count=0;
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->nxt;
	}
	return count;
}


void delete_middle()
{
	int pos,j=1;
	struct node *cur;
	cur=head;
	if(count()==0)
	{
		printf("\nThe List is Empty!!!\n");
		return;
	}
	printf("\nEnter the position:");
	scanf("%d",&pos);
	if(pos<=0 || pos >count())
	{
		printf("\nInvalid Position!!!\n");
		return;
	}
	if(pos==1)
	{
		delete_front();
		return;
	}
	
	while(j<pos)
	{
		cur=cur->nxt;
		j++;
	}
	printf("\nThe data deleted is: %d\n",cur->data);
	
	if(cur->nxt!=NULL)
	{
		cur->nxt->pre=cur->pre;
	}
	if(cur->pre!=NULL)
	{
		cur->pre->nxt=cur->nxt;
	}
	//free(cur);
	//return;
	//printf("/nhaiii\n");
	//cur->pre->nxt=cur->nxt;
	
}

void delete_data()
{
	int pos,data,j=1,flag=0;
	//struct node *cur;
	struct node *temp;
	temp=head;
	if(count()==0)
	{
		printf("\nThe List is Empty!!!\n");
		return;
	}
	printf("\nEnter the data:");
	scanf("%d",&data);
	while(temp->nxt!=NULL)
	{
		if(temp->data==data)
		{
			flag=1;
			pos=j;
			break;
		}
		temp=temp->nxt;
		j++;
	}
	if(flag==0)
	{
		printf("\nElement Not Present!!!\n");
		return;
	}
	if(pos==1)
	{
		delete_front();
		return;
	}
	if(temp->nxt!=NULL)
	{
		temp->nxt->pre=temp->pre;
	}
	if(temp->pre!=NULL)
	{
		temp->pre->nxt=temp->nxt;
	}
	
}
void update_data()
{
	int pos,data_old,data_new,j=1,flag=0;
	//struct node *cur;
	struct node *temp;
	temp=head;
	if(count()==0)
	{
		printf("\nThe List is Empty!!!\n");
		return;
	}
	printf("\nEnter the data to be updated:");
	scanf("%d",&data_old);
	while(temp->nxt!=NULL)
	{
		if(temp->data==data_old)
		{
			flag=1;
			break;
		}
		temp=temp->nxt;
	}
	if(flag==0)
	{
		printf("\nElement Not Present!!!\n");
		return;
	}
	printf("\nEnter the new data:");
	scanf("%d",&data_new);
	temp->data=data_new;
	
}
void delete_front()
{
	if(head!=NULL)
	{
		printf("\nThe deleted data is: %d\n",head->data);
		head=head->nxt;
	}
	else
	{
		printf("\nThe List is Empty!!!\n");
	}
}
