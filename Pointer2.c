#include<stdio.h>
int main()
{
	int arr[]={10,20,30};
	int i,*ptr;
	
	ptr=&arr;
	
	for(i=1;i<=3;i++)
	{
		printf("The address of arr[%d] is: %x\n",i,ptr);
		printf("The value of arr[%d] is: %d\n\n",i,*ptr);
		ptr++;
	}
	getch();
	return 0;
}
