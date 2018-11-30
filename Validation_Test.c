#include<stdio.h>

void main()
{
	/*int a;
	while(scanf("%d", &a)==0) //if scanf failed to scan an integer
	{
    	printf("Invalid input. Try again\n");
    	int c;
   		while((c=getchar())!='\n' && c!=EOF); //clear the stdin
	}*/
	int input ;
	A:
	if (scanf("%d", (&input)) == 0)
	{
    	while (getchar() != '\n');    // Removes the offending characters that causes 
                                    // scanf to struck at error occured on future 
                                    // operations.
    	printf(" \n Invalid value.\n") ;
    	goto A;
	}
	
}


