#include<stdio.h>
#include<conio.h>
void main()
{
	int a[10],up,i,j,ch,pos,ind,data;
	char choice;
	printf("Enter The Number of elements in the array:");
	scanf("%d",&up);
	
	printf("Enter the elemnts to the array:\n");
	for(i=0;i<up;i++)
	{
		printf("Enter the value of a[%d]:",i);
		scanf("%d",&a[i]);
	}
	
	do
	{
		printf("\n1.Insert In The End!!\n");
		printf("2.Insert In The Middle!!\n");
		printf("3.Delete In The End!!\n");
		printf("4.Delete In The Middle!!\n");
		printf("5.Display All Elemets!!\n");
		printf("6.Exit\n");
		
		printf("Enter your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
					do
					{
						printf("Enter the data: ");
						scanf("%d",&data);
						a[up]=data;
						up++;
						printf("Do you want to continue (yY/nN):");
						scanf(" %c",&choice);
					}while(choice=='y'||choice=='Y');
				
			break;
			case 2:
					do
					{
						
						printf("\nEnter the position:");
						scanf("%d",&pos);
						ind=pos-1;
						if(pos>0 && pos<=up)
						{
							printf("\nEnter the data:");
							scanf("%d",&data);
							for(j=up;j>=ind;j--)
							{
								a[j+1]=a[j];
							}
							a[ind]=data;
							up++;
						}
						printf("Do you want to continue (yY/nN):");
						scanf(" %c",&choice);
					}while(choice=='y'||choice=='Y');
					
			
			break;
			
			case 3:
					do
					{
						up--;
						printf("Do you want to continue (yY/nN):");
						scanf(" %c",&choice);
					}while(choice=='y'||choice=='Y');
			break;
			case 4:
					do
					{
						printf("\nEnter the position:");
						scanf("%d",&pos);
						ind=pos-1;
						if(pos>0 && pos<=up)
						{
							for(j=ind;j<up;j++)
							{
								a[j]=a[j+1];
							}
							up--;
							printf("Do you want to continue (yY/nN):");
							scanf(" %c",&choice);
						}
					}while(choice=='y'||choice=='Y');
			
			break;
			case 5:
					printf("The value of the array is:\n");
					for(i=0;i<up;i++)
					{
						printf("Enter the value of a[%d]: %d\n",i,a[i]);
					}
			break;
			
			case 6:
					printf("\nExiting!!!!!....");
					
			break;		
			default:printf("Invalid Choice!!\n");
		}
		
	}while(ch!=6);
	
	
	
	getch();
}
