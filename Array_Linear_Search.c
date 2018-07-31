/*******                     
Author: Noel Toy
Date: 21/03/2018
Contact:noeltoy21@gmail.com
Discription: This program will search a specified element in an array and returns it's index as result. Time Complexity of this algorithm is O(n).
********/
#include<stdio.h>

void main()
{
	int a[100],up,i,pos,data,flag=0;
	
	printf("Enter the number of elements in the array:");
	scanf("%d",&up);
	
	printf("Enter the elements into the array:\n\n");
	for(i=0;i<up;i++)
	{
		printf("Value for a[%d]:",i);
		scanf("%d",&a[i]);
	}
	
	printf("Enter the elemet to be search:");
	scanf("%d",&data);
	
	for(i=0;i<up;i++)
	{
		if(a[i]==data)
		{
			flag=1;
			pos=i+1;
			break;
		}
	}
	
	if(flag==1)
	{
		printf("\nThe element %d found on the position %d\n",data,pos);
	}
	else
	{
		printf("\nElement not found!!\n");
	}
	getch();
}
