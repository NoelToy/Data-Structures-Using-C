#include<stdio.h>
#include<stdlib.h>

void main()
{
	char *c,*p;
	c=malloc(256);
	scanf("%255s", c); // Don't read more than 255 chars
  	printf("%s", c);
  	getch();
}
