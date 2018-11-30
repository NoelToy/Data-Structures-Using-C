#include<stdio.h>
int partition(int a[],int low,int high);
void main()
{
	int a[10];
	int i,size,pivot_location;
	
	
	printf("\nEnter the number of elements:");
	scanf("%d",&size);
	
	printf("\nEnter the elements:\n");
	for(i=0;i<size;i++)
	{
		printf("\nEnter the value for a[%d]:",i);
		scanf("%d",&a[i]);
	}
	
	
	pivot_location=partition(a,0,size);
	
	printf("\nThe location of pivot element in the array is: %d\n",pivot_location);
	getch();	
}
int partition(int a[],int low,int high)
{
	int pivot=a[high-1],i=low-1,j,temp,k;
	
	for(j=0;j<high;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[high-1];
	a[high-1]=temp;
	/*for(k=0;k<high;k++)
	{
		printf("\nThe value for a[%d]:%d\n",k,a[k]);
	}*/
	return (i);
}
