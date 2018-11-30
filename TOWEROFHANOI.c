#include<stdio.h>
void TOH(int n,int A,int B,int C);

void main()
{
	int n;
	
	printf("Enter the number of disks: ");
	scanf("%d",&n);
	
	TOH(n,1,2,3);
	getch();
}

void TOH(int n,int A,int B,int C)
{
	if(n>0)
	{
		TOH(n-1,A,C,B);
		printf("Move a Disk from %d --> %d\n",A,C);
		TOH(n-1,B,A,C);
	}
}
