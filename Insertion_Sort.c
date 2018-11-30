#include<stdio.h>

void insert_array(int *arr,int size);
void display(int *arr,int size);

void insertion_sort(int *arr,int size);


void main()
{
	int a[10],size;
	
	printf("Enter the size of the array:");
	scanf("%d",&size);
	
	printf("\nEnter the elemnts to the array:\n");
	insert_array(&a,size);
	
	printf("\nThe unsorted array is:\n");
	display(&a,size);
	//sorting algorithm
	insertion_sort(&a,size);
	
	
	printf("\nThe sorted array is:\n");
	display(&a,size);
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
