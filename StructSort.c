#include<stdio.h>
 
struct cricket {
   char name[20];
   char subname[20];
   int mark;
} stud[10], temp;
 
void main() {
   int i, j, n;
   printf("Enter the number of students:");
   scanf("%d",&n);
   for (i = 0; i < n; i++) {
      printf("\nEnter Student Name : ");
      scanf(" %s", stud[i].name);
      printf("\nEnter Subject Name : ");
      scanf(" %s", stud[i].subname);
      printf("\nEnter Mark : ");
      scanf("%d", &stud[i].mark);
      printf("\n");
   }
   //n = 10;
 
   for (i = 1; i < n; i++)
      for (j = 0; j < n - i; j++) {
         if (stud[j].mark > stud[j + 1].mark) {
            temp = stud[j];
            stud[j] = stud[j + 1];
            stud[j + 1] = temp;
         }
      }
 
   for (i = 0; i < n; i++) {
      printf("\n%s\t%s\t%d",stud[i].name,stud[i].subname,stud[i].mark);
   }
   getch();
}
