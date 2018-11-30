#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,j,temp;
	int arr[10]={5,7,50,8,4,81,72,10,102,57};
	
	for(i=0;i<3-1;i++)
	{
		for(j=0;j<10-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
			}
		}
	}
	printf("%d",arr[10-2]);
}
