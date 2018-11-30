#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};

void insert_end(struct node **,int);
void insert_beginning(struct node **,int);
void insert_middle(struct node **,int,int pos);

void update(struct node**,int);

void delete_beginning(struct node **);
void delete_middle(struct node **,int);

int length(struct node *);
void display(struct node *);

void main()
{
	struct node *head;
	head=NULL;
	int item,pos,len,choice,choice1,choice2;
	
	do
	{
		printf("\n1.Insert\n");
		printf("\n2.Delete\n");
		printf("\n3.Update\n");
		printf("\n4.Display\n");
		printf("\n5.Exit\n");
		
		printf("Enter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
					do
					{
						printf("\n1.Insert At Beginning\n");
						printf("\n2.Insert At Middle\n");
						printf("\n3.Insert At End\n");
						printf("\n4.Exit\n");						
						printf("Enter your choice:");
						scanf("%d",&choice1);
						
						switch(choice1)
						{
							case 1:
									printf("Enter the data:");
									scanf("%d",&item);
									insert_beginning(&head,item);
							break;
							case 2:
									printf("Enter the position:");
									scanf("%d",&pos);
									printf("Enter the data:");
									scanf("%d",&item);
									insert_middle(&head,item,pos);
							break;
							case 3:
									printf("Enter the data:");
									scanf("%d",&item);
									insert_end(&head,item);
							break;
							case 4:printf("Exiting!!!\n");
							break;
							default:printf("\n Invalid Option!!!\n");
								
						}
						
					}while(choice1!=4);
			break;
			case 2:
					do
					{
						printf("\n1.Delete From Beginning\n");
						printf("\n2.Delete Form Middle\n");
						printf("\n3.Exit\n");
						printf("Enter your choice:");
						scanf("%d",&choice2);
						
						switch(choice2)
						{
							case 1:
									delete_beginning(&head);
							break;
							case 2:
									printf("Enter the position:");
									scanf("%d",&pos);
									delete_middle(&head,pos);
							break;
							case 3:printf("Exiting!!!\n");
							break;
							default:printf("\n Invalid Option!!!\n");
						}
						
						
					}while(choice2!=3);
			break;
			case 3:
					printf("Enter the position:");
					scanf("%d",&pos);
					update(&head,pos);
			break;
			case 4:display(head);
			break;
			case 5:printf("Exiting!!!\n");
			break;
			default:printf("\n Invalid Option!!!\n");
		}
	}while(choice!=5);
	getch();
}

void insert_beginning(struct node **head,int item)
{
	struct node *tempnode;
	tempnode=(struct node*)malloc(sizeof(struct node));
		
	tempnode->data=item;
	tempnode->next=(*head);
	(*head)=tempnode;
	
}
void insert_end(struct node **head,int item)
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

void insert_middle(struct node **head,int item,int pos)
{
	int count=1;
	struct node *tempnode;
	tempnode=malloc(sizeof(struct node));
	struct node *temp=*head;
	struct node *cur=*head;
	struct node *pre=*head;
	
	if(temp==NULL)
	{
		printf("\nThe List is Empty, Creating List\n");
		insert_end(head,item);
		return;
	}
	
	int len=length(temp);
	//printf("Length is %d!!!\n",len);
	if(pos>0 && pos<=len)
	{		
		while(count<pos)
		{
			pre=cur;
			cur=temp->next;
			temp=temp->next;
			count++;
		}
	//	printf("Length is %d!!!\n",count);
		tempnode->data=item;
		pre->next=tempnode;
		tempnode->next=cur;
	}
	else
	{
		printf("\nInvalid Position!!!\n");
		return;
	}
	
}
void delete_beginning(struct node **head)
{
	struct node *temp=*head;
	if(temp==NULL)
	{
		printf("\nThe Linked List Empty\n");
		return;
	}
	int item;
	item=temp->data;
	printf("\nThe Deleted Element is:%d\n",item);
	*head=temp->next;
}
void delete_middle(struct node **head,int pos)
{
	int count=1;
	struct node *temp=*head;
	struct node *cur=*head;
	struct node *pre=*head;
	
	int len=length(temp);
	int item;
	if(temp==NULL)
	{
		printf("\nThe Linked List Empty\n");
		return;
	}
	if(pos>0 && pos<=len)
	{		
		while(count<pos)
		{
			pre=cur;
			cur=temp->next;
			temp=temp->next;
			count++;
		}
		item=cur->data;
		printf("The Deleted Element is:%d",item);
		if(pos==1)
		{
			*head=temp->next;
		}
		else
		{
			pre->next=cur->next;
		}	
	}
	else
	{
		printf("\nInvalid Position!!!\n");
		return;
	}
}
void update(struct node **head,int pos)
{
	struct node *temp=*head;
	int count=1,item;
	int len=length(temp);
	if(temp==NULL)
	{
		printf("\nThe Linked List Empty\n");
		return;
	}
	printf("Enter the new data:");
	scanf("%d",&item);
	if(pos==1)
	{
		temp->data=item;
		return;
	}
	if(pos<=len)
	{
		while(count<=pos)
		{
			temp=temp->next;
			count++;
		}
		
		temp->data=item;
	}
	else
	{
		printf("\nInvalid Position!!!\n");
		return;
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

void display(struct node *head)
{
	struct node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nThe List Is Empty\n");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("X");
}



