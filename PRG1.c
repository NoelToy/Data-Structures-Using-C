#include<stdio.h>
int binary_serach(int a[],int size,int item);
int liner_search(int *arr,int size,int data);

void liner_search_all(int *arr,int size,int data);

void insert_array(int *arr,int size);
int sort_checker(int *arr,int size);
void sorter(int *arr,int size);

void main()
{
	int a[10],i,item,size,pos,c,data,flag=0,choice1;
	char ch;
size_enter:	
	printf("\nEnter the number of elements in array:");
	scanf("%d",&size);
	if(size>10)
	{
		printf("\nSize should be less than 10\n");
		goto size_enter;
	}
	
	printf("\nEnter the elements to the array:\n");
	insert_array(&a,size);
	
	do
	{
		printf("\n1.Enter New Elements\n");
		printf("\n2.Linear Search\n");
		printf("\n3.Binary Search\n");
		printf("\n4.Display\n");
		printf("\n5.Exit\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&c);
		
		switch(c)
		{
			case 1:
						/*printf("Enter the number of elements in array:");
						scanf("%d",&size);*/
						printf("Enter the elements to the array:\n");
						insert_array(&a,size);
			break;
			case 2:
						
						printf("Enter the elemet to be search:");
						scanf("%d",&data);
						
						do
						{
								printf("\n1.All Occurence\n");
								printf("\n2.One Occurence\n");
								printf("\n3.Exit\n");
								
								printf("\nEnter your choice:");
								scanf("%d",&choice1);
								switch(choice1)
								{
									case 1:
											liner_search_all(&a,size,data);
									break;
									case 2:
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
									case 3:printf("\nExiting....\n");
									break;
									default:printf("\nInvalid Choice!!!\n");
								}
						}while(choice1!=3);
			break;
			case 3:
						search:
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
								sorter(&a,size);
								goto search;			
							}
						}
			break;
			case 4:display(&a,size);
			break;
			case 5: printf("\nExiting.......\n");
			break;
			default:printf("\nInvalid Choice!!!!!\n");
		}
		
	}while(c!=5);
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
void liner_search_all(int *arr,int size,int data)
{
	int i,flag=0,pos;
	int s=size;

	for(i=0;i<s;i++)
	{
		if(arr[i]==data)
		{
			flag=1;
			pos=i+1;
			printf("\nThe element found on the position %d\n",pos);
		}
	}
	if(flag==0)
	{
		printf("\nElement not found!!\n");
	}
}
void insert_array(int *arr,int size)
{
	int i;
	//int num;
	
	for(i=0;i<size;i++)
	{
		value_taker:
		printf("Enter the value of array[%d]:",i);
		scanf("%d",&arr[i]);
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

int sort_checker(int *arr,int size)
{
	int i,j;
	
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j])
			{
				return -1;
			}
		}
	}
	return 1;
}
void sorter(int *arr,int size)
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












