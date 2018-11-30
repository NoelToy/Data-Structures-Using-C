#include<stdio.h>
#include<conio.h>
void myfun();
void main()
{
	myfun();
	myfun();
	myfun();
	
	getch();
}

void myfun()
{
	int a=10;
	static int s=10;
	
	a=a+1;
	s=s+1;
	
	printf("Local Variable %d \n",a);
	printf("Static variable %d \n",s);
	
}
