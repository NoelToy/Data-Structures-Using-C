#include<stdio.h>

void main()
{
	char line[80];
	
	printf("Enter the string:");
	scanf("%[^\n]",line);
	printf("%s",line);
}
