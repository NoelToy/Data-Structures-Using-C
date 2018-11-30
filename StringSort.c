/*#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	char name[25][25],temp[25];
	int i,j,size;
	
	printf("Enter the number of names:");
	scanf("%d",&size);
	printf("\nEnter the names :\n");
	for(i=0;i<=size;i++)
	{
		gets(name[i]);
	}
	
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			 if (strcmp(name[j], name[j + 1]) > 0)
			{
	            strcpy(temp, name[j]);
	            strcpy(name[j], name[j + 1]);
	            strcpy(name[j + 1], temp);
			}
		}
	}
	printf("Order of Sorted Strings:");
    for(i=0;i<=size;i++)
    puts(name[i]);
	
}*/
#include<stdio.h>
#include<string.h>
int main(){
   int i,j,count;
   char str[25][25],temp[25];
   puts("How many strings u are going to enter?: ");
   scanf("%d",&count);

   puts("Enter Strings one by one: ");
   for(i=0;i<=count;i++)
      gets(str[i]);
   for(i=0;i<count;i++)
      for(j=0;j<count-1;j++){
         if(strcmp(str[j],str[j+1])>0){
            strcpy(temp,str[j]);
            strcpy(str[j],str[j+1]);
            strcpy(str[j+1],temp);
         }
      }
   printf("Order of Sorted Strings:");
   for(i=0;i<=count;i++)
      puts(str[i]);
   
   return 0;
}
