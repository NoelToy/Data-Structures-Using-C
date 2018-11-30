#include<stdio.h>

void update(int *ptr);
void insert_array(int *arr,int size);

void main()
{
	int a;
	
	a=5;
	int ar[10];
	int size;
	printf("\nEnter the size:");
	scanf("%d",&size);
	insert_array(&ar,size);
	/*printf("The value of a is:%d\n",a);
	update(&a);
	printf("The value of a is:%d\n",a);*/
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
	for(i=0;i<size;i++)
	{
			printf("The value of array[%d]:%d\n",i,arr[i]);
			//scanf("%d",&arr[i]);
	}
}

void update(int *a)
{
	*a=*a+1;
}
