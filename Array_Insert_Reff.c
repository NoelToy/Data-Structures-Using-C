#include<stdio.h>
void insert_array(int *arr);

void main()
{
	int array[10];
	int i;
	insert_array(&array);
	printf("The array elements are:\n");
	for(i=0;i<10;i++)
	{
		printf("The value of a[%d] is: %d\n",i,array[i]);
	}
	getch();
}
void insert_array(int *arr)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("Enter the value of array[%d]:",i);
		scanf("%d",&arr[i]);
	}
}
