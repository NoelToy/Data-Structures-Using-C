#include<stdio.h>
int binary_search(int a[],int size,int item,int fs);
void insert_array(int *arr,int size);

void main()
{
	int a[10],i,item,size,pos_first,pos_last;
	printf("Enter the number of elements in array:");
	scanf("%d",&size);
	
	printf("Enter the elements to the array in sorted order:\n");
	insert_array(&a,size);
	printf("\nEnter the item to be searched:");
	scanf("%d",&item);
	pos_first= binary_serach(a,size,item,1);
	pos_last=binary_serach(a,size,item,0);
	if(pos_first==-1)
	{
		printf("The Item Not Found!!\n");
	}
	else
	{
		printf("The Item found at position %d\n",pos_first);
		printf("The Item found at position %d\n",pos_last);
	}
	
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
int binary_serach(int a[],int size,int item,int fs)
{
	int LOW=0;
	int HIGH=size-1;
	int MID;
	int result;
	while(LOW<=HIGH)
	{
		MID=(HIGH+LOW)/2;
		if(a[MID]==item)
		{
			result=MID;
			if(fs==1)
			{
				HIGH=MID-1;
			}
			else
			{
				LOW=MID+1;
			}
		}
	
		if(item<a[MID])
		{
			HIGH=MID-1;
		}
		if(item>a[MID])
		{
			LOW=MID+1;
		}
	}
	return result;
}
