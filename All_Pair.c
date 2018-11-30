#include<stdio.h>
#include<conio.h>

int adj[10][10],n;
void print_array();

void main()
{
	int i,j,k;
	printf("\nEnter the number of vertex:");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("\nEnter the edge weight from vertex %d to %d:",i,j);
			scanf("%d",&adj[i][j]);
		}
	}
	
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(adj[i][j]>(adj[i][k]+adj[k][j]))
				{
					adj[i][j]=adj[i][k]+adj[k][j];
				}
			}
		}
		printf("When k=%d\n",k);
		print_array();
	}
}

void print_array()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",adj[i][j]);
		}
		printf("\n");
	}
	
}
