#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
  int i;
  char num[55];
  printf ("Enter a number: ");
  //gets(num);
  scanf("%s",num);
  i = num[1] - '0';
  printf ("The value entered is %d.\n",i);

  getch();
}
