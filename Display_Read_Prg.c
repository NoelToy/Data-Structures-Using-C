#include<stdio.h>
#include<conio.h>
void main()
{
	int a,b,c;
	printf("Enter the value for a:");
	scanf("%d",&a);
	
	printf("Enter the value for b:");
	scanf("%d",&b);
	
	printf("The Value of a is: %d \n",a);
	printf("The Value of b is: %d \n",b);
	
	c=a+b;
	
	printf("The sum of %d and %d is: %d \n",a,b,c);
	getch();
}
