/*******                     

Author: Noel Toy
Date: 21/03/2018
Contact:noeltoy21@gmail.com
Discription: This program will take the array values from the user and allows the user to insert a new element at any specified position.

********/

#include<stdio.h>

void main()
{
	int a[10],i=1,up,data,pos,j,k=0; //up variable is the upperlimit 
	
	printf("Enter the number of elements:\n"); //reading upperlimit
	scanf("%d",&up);
	
	printf("Enter the elemts is the array:\n");
	
	while(i<=up)//reading the array elements
	{
		printf("Enter the value of a[%d]: ",i);
		scanf("%d",&a[i]);
		i++;
	}
	printf("Enter the position: ");//reading the place where new element will be inserted
	scanf("%d",&pos);
	
	if(pos>=1 && pos<=10)
	{
		printf("Enter the data: ");
		scanf("%d",&data);//reading the data for the new element
		
		if(pos==up)//Insertion at the end
		{
			a[up+1]=data;
			up++;
		}
		
		else//Insertion at anywhere else
		{
			for(j=up;j>=pos;j--)
			{
				a[j+1]=a[j];
			}
			a[pos]=data;
			up++;
		}
		
		i=1;
		printf("value of up %d\n",up);//printing new limit value
		printf("The array after insertion is:\n");
		while(i<=up)//printing updated array
		{
			printf("Enter the value of a[%d]: %d\n",i,a[i]);
			i++;
		}
	
	}
	else//error as the given position is invalid
	{
		printf("Please enter a valid position!!");
	}
}
