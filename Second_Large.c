#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,large,large2;
	int a[10]={5,7,50,8,4,81,72,10,102,57};
	
	large=a[0];
	for(i=0;i<10;i++)
	{
		if(a[i]>large)
		{
			large=a[i];
		}
	}
	large2=a[0];
	for(i=0;i<10;i++)
	{
		if(a[i]>large2 && a[i]!=large)
		{
			large2=a[i];
		}
	}
	printf("%d",large2);
}
