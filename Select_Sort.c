#include<stdio.h>
void insert_array(int *arr,int size);
void selection_sort(int *arr,int size);
void display(int *arr,int size);

void main()
{
	int a[10],size;
	
	printf("\nEnter the size of the array: ");
	scanf("%d",&size);
	
	printf("Enter the array elements:\n");
	insert_array(&a,size);
	
	printf("\nThe Unsorted array is:\n");
	display(&a,size);
	
	printf("sorting......\n");
	selection_sort(&a,size);
	
	printf("\nThe Sorted array is:\n");
	display(&a,size);
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
void display(int *arr,int size)
{
	int i;
	printf("The value of the array is:\n");
	for(i=0;i<size;i++)
	{
		printf("The value of a[%d]: %d\n",i,arr[i]);
	}
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
}

