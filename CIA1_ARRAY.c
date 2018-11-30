#include<stdio.h>
void main()
{
	int a[10],i,j,size,item;
	
	printf("\nEnter the size of the array:");
	scanf("%d",&size);
	
	printf("\nEnter the array elements:\n");
	for(i=0;i<size;i++)
	{
		printf("\nEnter the value of a[%d]:",i);
		scanf("%d",&a[i]);
	}	
	for(i=0;i<size;i=i+2)
	{
		item=a[size-1];
		
		for(j=size-1;j>=i;j--)
		{
			a[j+1]=a[j];
		}
		a[i]=item;
	}
	for(i=0;i<size;i++)
	{
		printf("\nEnter the value for a[%d]:%d\n",i,a[i]);
	}
	getch();
	
}
