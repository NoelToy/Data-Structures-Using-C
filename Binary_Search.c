#include<stdio.h>
int binary_serach(int a[],int low,int up,int item);

void main()
{
	int a[10],i,item,up,pos;
	
	printf("Enter the number of elements in array:");
	scanf("%d",&up);
	
	printf("Enter the elements to the array:\n");
	
	for(i=0;i<up;i++)
	{
		printf("Enter value for a[%d]:",i);
		scanf("%d",&a[i]);
	}
	
	printf("\nEnter the item to be searched:");
	scanf("%d",&item);
	
	pos= binary_serach(a,0,up-1,item);
	
	if(pos==-1)
	{
		printf("The Item Not Found!!\n");
	}
	else
	{
		printf("The Item found at position %d\n",pos+1);
	}
	getch();
	
}


int binary_serach(int a[],int low,int up,int item)
{
	if(up>=low)
	{
		int mid=(up+low)/2;
		
		if(a[mid]==item)
		{
			return mid;
		}
		if(item<a[mid])
		{
			return	binary_serach(a,low,mid-1,item);
		}
			return	binary_serach(a,mid+1,up,item);
	}
	else
	{
		return -1;
	}
}




