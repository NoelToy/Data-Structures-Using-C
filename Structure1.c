#include<stdio.h>
typedef struct
{
	char title[50];
	char author[50];
	int pages;
	float price;
}book_bank;

void main()
{
	book_bank book1;
	book_bank book2= {"I Too Had A Love Story","Ravidhra S",500,250};
	
	printf("Enter the book title:");
	scanf(" %s",&book1.title);
	printf("Enter the author name:");
	scanf(" %s",&book1.author);
	printf("Enter the number of pages:");
	scanf("%d",&book1.pages);
	printf("Enter the price:");
	scanf("%f",&book1.price);
	
	printf("\n\nBook1 Details are:");
	printf("\nThe Book Title is: %s",book1.title);
	printf("\nThe Author Name is: %s",book1.author);
	printf("\nThe Number of Pages is: %d",book1.pages);
	printf("\nThe Price of the Book is: %f\n",book1.price);
	
	printf("\n\nBook2 Details are:");
	printf("\nThe Book Title is: %s",book2.title);
	printf("\nThe Author Name is: %s",book2.author);
	printf("\nThe Number of Pages is: %d",book2.pages);
	printf("\nThe Price of the Book is: %f\n",book2.price);
	getch();
}
