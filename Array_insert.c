/*******                     

Author: Noel Toy
Date: 





********/

#include<stdio.h>

void main()
{
	int a[10],i=1,up,data,pos,j,k=0;
	
	printf("Enter the number of elements:\n");
	scanf("%d",&up);
	
	printf("Enter the elemts is the array:\n");
	
	while(i<=up)
	{
		printf("Enter the value of a[%d]: ",i);
		scanf("%d",&a[i]);
		i++;
	}
	printf("Enter the position: ");
	scanf("%d",&pos);
	
	if(pos>=1 && pos<=10)
	{
		printf("Enter the data: ");
		scanf("%d",&data);
		
		if(pos==up)
		{
			a[up+1]=data;
			up++;
		}
		
		else
		{
			for(j=up;j>=pos;j--)
			{
				a[j+1]=a[j];
			}
			a[pos]=data;
			up++;
		}
		
		i=1;
		printf("value of up %d\n",up);
		printf("The array after insertion is:\n");
		while(i<=up)
		{
			printf("Enter the value of a[%d]: %d\n",i,a[i]);
			i++;
		}
	
	}
	else
	{
		printf("Please enter a valid position!!");
	}
}
