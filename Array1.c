#include<stdio.h>

void main()
{
	int a[10],i=0,up,l;
	
	printf("Enter the number of elements:\n");
	scanf("%d",&up);
	
	printf("Enter the elemts is the array:\n");
	
	while(i<up)
	{
		printf("Enter the value of a[%d]: ",i);
		scanf("%d",&a[i]);
		if(i==0)
		{
			l=a[i];
		}
		if(l<a[i])
		{
			l=a[i];
		}
		i++;
	}
	
	i=0;
	printf("The array elemets are:\n");
	while(i<up)
	{
			printf("Enter the value of a[%d]: %d\n",i,a[i]);
			i++;
	}
	printf("\n\nThe Greatest number is: %d",l);
	getch();
}
