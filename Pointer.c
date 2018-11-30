#include<stdio.h>
void main()
{
	int var1=100;
	int var2[10];
	int *ptr;//pointer
	int *ptr1=NULL;
	
	ptr=&var1;
	ptr1=&var2;

	printf("The address of the variable is %x\n",&var1);
	printf("The value of the pointer is %d\n",*ptr);
	
	
	printf("The address of the pointer1 is %x\n",ptr1);
	if(ptr1)
	{
		printf("Address of the pointer is not null");
	}
	if(!ptr1)
	{
		printf("The adress of the pointer is null");
	}
	
	//printf("The address of the variable is %x\n",&var2);
	
	getch();
}
