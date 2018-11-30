#include<stdio.h>
void insert_array(int *arr,int size);
void insert_beginning(int *arr,int *size);
void insert_middle(int *arr,int *size);
void insert_end(int *arr,int *size);

void delete_end(int *size);
void delete_middle(int *arr,int *size);

void update(int *arr,int size);

int liner_search(int *arr,int size,int data);
int binary_search(int *a,int size,int item);

int sort_checker(int *arr,int size);
//void sorter(int *arr,int size);
void buble_sort(int *arr,int size);

void display(int *arr,int size);

void main()
{
	int a[10],i,item,data,size,pos,flag=1,choice,choice1,choice2,choice3;
	char ch;
	printf("Enter the size of th array:");
	scanf("%d",&size);
	
	printf("Enter the elements to the array\n");
	insert_array(&a,size);
	
	do
	{
		printf("\n1.Insert\n");
		printf("\n2.Update\n");
		printf("\n3.Delete\n");
		printf("\n4.Search\n");
		printf("\n5.Display\n");
		printf("\n6.Exit\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
					do
					{
						printf("\n1.Insert In Beginning\n");
						printf("\n2.Insert In Middle\n");
						printf("\n3.Insert In End\n");
						printf("\n4.Exit\n");
						
						printf("\nEnter your choice:");
						scanf("%d",&choice1);
						
						switch(choice1)
						{
							case 1:
									insert_beginning(&a,&size);	
							break;
							case 2:
									insert_middle(&a,&size);
							break;
							case 3:
									insert_end(&a,&size);
							break;
							case 4:
									printf("\n Exiting!!\n");
							break;
							default:
									printf("\n Invalid Option!!!\n");
						}
						
					}while(choice1!=4);
			break;
			case 2:
					update(&a,size);
			break;
			case 3:
					do
					{
						printf("\n1.Delete In Middle\n");
						printf("\n2.Delete In End\n");
						printf("\n3.Exit\n");
						
						printf("\nEnter your choice:");
						scanf("%d",&choice2);
						switch(choice2)
						{
							case 1:
									delete_middle(&a,&size);
							break;
							case 2:
									delete_end(&size);
							break;
							case 3:
									printf("\n Exiting!!\n");
							break;
							default:
									printf("\n Invalid Option!!!\n");
						}
						
					}while(choice2!=3);
			break;
			case 4:
					do
					{
						printf("\n1.Linear Search\n");
						printf("\n2.Binary Search\n");
						printf("\n3.Exit\n");
						
						printf("\nEnter your choice:");
						scanf("%d",&choice3);
						
						switch(choice3)
						{
							case 1:
									printf("Enter the elemet to be search:");
									scanf("%d",&data);
									pos=liner_search(&a,size,data);
									if(pos==-1)
									{
										printf("\nElement not found!!\n");
									}
									else
									{
										printf("\nThe element found on the position %d\n",pos);
									}
							break;
							case 2:
									flag=sort_checker(&a,size);
									if(flag==1)
									{
										printf("Enter the elemet to be search:");
										scanf("%d",&item);
										pos=binary_search(&a,size,item);
										if(pos==-1)
										{
											printf("\nElement not found!!\n");
										}
										else
										{
										printf("\nThe element found on the position %d\n",(pos+1));
										}
									}
									else
									{
										printf("\nThe Array is not sorted!!!!\n");
										printf("Do you want to sort the array?(y/n)");
										scanf(" %c",&ch);
										if(ch=='Y'||ch=='y')
										{
											//sorter(&a,size);
											buble_sort(&a,size);
											printf("Enter the elemet to be search:");
											scanf("%d",&item);
											pos=binary_search(&a,size,item);
											if(pos==-1)
											{
												printf("\nElement not found!!\n");
											}
											else
											{
												printf("\nThe element found on the position %d\n",(pos+1));
											}
											
										}
									}
							break;
							case 3:
									printf("\nExiting!!\n");
							break;
							default:
									printf("\nInvalid Option!!!\n");
						}
					}while(choice3!=3);
			break;
			case 5:
					display(&a,size);
			break;
			case 6:
					printf("\n Exiting!!\n");
			break;
			default:printf("\nInvalid Choice!!!!\n");
		}
		
	}while(choice!=6);
	getch();
}

void insert_array(int *arr,int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("Enter the value of array[%d]:",i);
		scanf("%d",&arr[i]);
	}
}
void insert_beginning(int *arr,int *size)
{
	int s=*size;
	int i,data;
	
	printf("Enter the data:");
	scanf("%d",&data);
	
	for(i=s;i>=0;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[0]=data;
	*size=*size+1;
}
void insert_middle(int *arr,int *size)
{
	int pos,data,ind,j;
	int s=*size;
	
	printf("\nEnter the position:");
	scanf("%d",&pos);
	ind=pos-1;
	if(pos>0 && pos<=s)
	{
		printf("\nEnter the data:");
		scanf("%d",&data);
		for(j=s;j>=ind;j--)
		{
			arr[j+1]=arr[j];
		}
		arr[ind]=data;
		*size=*size+1;
	}
	else
	{
		printf("\nInvalid Position!!!\n");
	}
}
void insert_end(int *arr,int *size)
{
	int data;
	int s=*size;
	printf("Enter the data: ");
	scanf("%d",&data);
	arr[s]=data;
	*size=*size+1;
	
}
void delete_end(int *size)
{
	*size=*size-1;
		
}
void delete_middle(int *arr,int *size)
{
	int pos,j,ind;
	int s=*size;
	
	printf("\nEnter the position:");
	scanf("%d",&pos);
	ind=pos-1;
	if(pos>0 && pos<=s)
	{
		for(j=ind;j<s;j++)
		{
			arr[j]=arr[j+1];
		}
		*size=*size-1;
	}
	else
	{
		printf("\nInvalid Position!!!\n");
	}
}

int liner_search(int *arr,int size,int data)
{
	int i,flag=0,pos;
	int s=size;

	for(i=0;i<s;i++)
	{
		if(arr[i]==data)
		{
			flag=1;
			pos=i+1;
			break;
		}
	}
	if(flag==1)
	{
		return pos;
	}
	else
	{
		return -1;
	}
}

int binary_search(int *a,int size,int item)
{
	int LOW=0;
	int HIGH=size-1;
	int MID;
	//int item;
	while(LOW<=HIGH)
	{
		MID=(HIGH+LOW)/2;
		if(a[MID]==item)
		{
			return MID;
		}
	
		if(item<a[MID])
		{
			HIGH=MID-1;
		}
		else
		{
			LOW=MID+1;
		}
	}
	return -1;
}

void update(int *arr,int size)
{
	int pos,i;
	int old_data,new_data;
	char ch;
	
	printf("Enter the elemet to be replaced:");
	scanf("%d",&old_data);
	
	pos=liner_search(arr,size,old_data);
	
	if(pos==-1)
	{
		printf("No such element!!!!!!");
		return;
	}
	else
	{
		printf("Enter the new data:");
		scanf("%d",&new_data);
		printf("Do you want to replace all occurence(y/n)?\n");
		scanf(" %c",&ch);
		
		if(ch=='Y'||ch=='y')
		{
			for(i=0;i<size;i++)
			{
				if(arr[i]==old_data)
				{
					arr[i]=new_data;
				}
			}
		}
		else
		{
			arr[pos-1]=new_data;
		}
	}
	
}
int sort_checker(int *arr,int size)
{
	int i,j;
	
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				printf("I=%d J=%d:\n",i,j);
				return -1;
			}
		}
	}
	return 1;
}
/*void sorter(int *arr,int size)
{
	int i,j,temp;
	
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
}*/


void buble_sort(int *arr,int size)
{
	int i,j,temp;
	
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
			}
		}
	}
	printf("Sorting done....\n");
}
void display(int *arr,int size)
{
	int i;
	printf("The value of the array is:\n");
	for(i=0;i<size;i++)
	{
		printf("The value of a[%d]: %d\n",i,arr[i]);
	}
}

