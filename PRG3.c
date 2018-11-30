#include<stdio.h>

void buble_sort(int *arr,int size);
void selection_sort(int *arr,int size);
void insertion_sort(int *arr,int size);

void insert(int *arr,int size);
void display(int *arr,int size);


void main()
{
	int a[100],choice,size;
	
	printf("Enter the size of the array:");
	scanf("%d",&size);
	insert(&a,size);
	do
	{
		printf("\n1.INSERT NEW ARRAY ELEMENTS\n");
		printf("\n2.DISPLAY ARRAY ELEMNTS\n");
		printf("\n3.BUBLE SORT\n");
		printf("\n4.SELECT SORT\n");
		printf("\n5.INSERTION SORT\n");
		printf("\n6.EXIT\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
					printf("Enter the size of the array:");
					scanf("%d",&size);
					insert(&a,size);
			break;
			case 2:
					display(&a,size);
			break;
			case 3:
					buble_sort(&a,size);
			break;
			case 4:
					selection_sort(&a,size);
			break;
			case 5:
					insertion_sort(&a,size);
			break;
			case 6:
					printf("Exiting....\n");
			break;
			default:printf("Invalid Choice!!\n");
		}
	}while(choice!=6);
	getch();
} 

/*void insert(int *arr,int size)
{
	int i;
	printf("Enter the elments to the array:\n");
	for(i=0;i<size;i++)
	{
		printf("Enter the value for a[%d]:",i);
		scanf("%d",&arr[i]);
	}
}*/
void insert(int *arr,int size)
{
	int i;
	//int num;
	
	for(i=0;i<size;i++)
	{
		printf("Enter the value of array[%d]:",i);
		
		while(scanf("%d",&arr[i])==0) //if scanf failed to scan an integer
		{
    		printf("\nInvalid input. Try again\n");
    		printf("Enter the value of array[%d]:",i);
    		int c;
   			while((c=getchar())!='\n' && c!=EOF); //clear the stdin
		}
		//scanf("%d",&arr[i]);
	}
}
void display(int *arr,int size)
{
	int i;
	printf("The array elments array:\n");
	for(i=0;i<size;i++)
	{
		printf("Enter the value for a[%d]:%d\n",i,arr[i]);
	}
}
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
void selection_sort(int *a,int size)
{
	int small,i,j,temp;
	
	for(i=0;i<size;i++)
	{
		small=i;
		for(j=i;j<size;j++)
		{
			if(a[small]>a[j])
			{
				small=j;
			}
		}
		temp=a[i];
		a[i]=a[small];
		a[small]=temp;
		
	}
	printf("Sorting done....\n");
}
void insertion_sort(int *a,int size)
{
	int i,j,item;
	for(i=1;i<size;i++)
	{
		item=a[i];
		j=i-1;
		while(item<a[j]&&j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=item;
	}
}
