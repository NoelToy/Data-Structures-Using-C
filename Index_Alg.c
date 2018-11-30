#include<stdio.h>
#include<stdlib.h>

void main()
{
	int i,j;
	
	int a[]={4,8,10,11};
	int b[]={9,13,5};
	
	int A=33;
	int B=27;
	
	for(i=0;i<sizeof(a)/sizeof(int);i++)
	{
		for(j=0;j<sizeof(b)/sizeof(int);j++)
		{
			if(A-a[i]+b[j]==B-b[j]+a[i])
			{
				printf("%d,%d",i+1,j+1);
			}
		}
	}
	
}
