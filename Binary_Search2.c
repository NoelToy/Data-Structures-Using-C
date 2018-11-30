#include<stdio.h>
int binary_serach(int a[],int size,int item);
void insert_array(int *arr,int size);

void main()
{
	int a[10],i,item,size,pos,c;
	int flag=0;
	char ch;
	
	printf("Enter the number of elements in array:");
	scanf("%d",&size);
	
	printf("Enter the elements to the array:\n");
	insert_array(&a,size);
	/*for(i=0;i<size;i++)
	{
		printf("Enter value for a[%d]:",i);
		scanf("%d",&a[i]);
	}*/
	do
	{
		if(flag==0)
		{
			printf("\nEnter the item to be searched:");
			scanf("%d",&item);
	
			pos= binary_serach(a,size,item);
	
			if(pos==-1)
			{
				printf("The Item Not Found!!\n");
			}
			else
			{
				printf("The Item found at position %d\n",pos+1);
			}
			flag=1;
		}
		
		printf("Do you want to continue(yY/nN)\n");
		scanf(" %c",&ch);
		if(ch=='Y'||ch=='y')
		{
				printf("1.With Same Elements\n");
				printf("2.With Different Elements\n");
				printf("3.Exit\n");				
				printf("Enter your choice:");
				scanf("%d",&c);
				
				switch(c)
				{
					case 1:
							printf("\nEnter the item to be searched:");
							scanf("%d",&item);
							pos= binary_serach(a,size,item);
	
							if(pos==-1)
							{
								printf("The Item Not Found!!\n");
							}
							else
							{
								printf("The Item found at position %d\n",pos+1);
							}
							
					break;
					case 2:
								printf("Enter the number of elements in array:");
								scanf("%d",&size);
	
								printf("Enter the elements to the array:\n");
								insert_array(&a,size);
								printf("\nEnter the item to be searched:");
								scanf("%d",&item);
								pos= binary_serach(a,size,item);
	
								if(pos==-1)
								{
									printf("The Item Not Found!!\n");
								}
								else
								{
									printf("The Item found at position %d\n",pos+1);
								}
					break;
					case 3:
							printf("Exiting!!!\n");
							//ch='N';
					break;
					default:
						printf("\n Invalid Choice!!!\n");
				}	
		}
		
	}while(ch=='Y'||ch=='y');
	
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

int binary_serach(int a[],int size,int item)
{
	int LOW=0;
	int HIGH=size-1;
	int MID;
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
