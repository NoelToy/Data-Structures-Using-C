#include<stdio.h>
struct node
{
	int data;
	struct node *next;
};
void insert_beginning(struct node **,int);
void display(struct node*);
void main()
{
	struct node *head;
	int item;
	char ch;
	head=NULL;
	do
	{
		printf("Enter the data:");
		scanf("%d",&item);
		insert_beginning(&head,item);
		printf("\n%x",&head);//address
		printf("\nDo you want to continue?(Yy/nN):");
		scanf(" %c",&ch);
		
	}while(ch=='y'||ch=='Y');
	display(head);
	getch();
	
}
void insert_beginning(struct node **head,int item)
{
	struct node *tempnode;
	tempnode=(struct node*)malloc(sizeof(struct node));
	
	printf("\n%d",**head);//address
	
	tempnode->data=item;
	tempnode->next=(*head);
	(*head)=tempnode;
	
}
void display(struct node *head)
{
	struct node *temp;
	temp=head;
	while(temp!=NULL)
	{
		printf("\nThe data is: %d\n",temp->data);
		temp=temp->next;
	}
}

