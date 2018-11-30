#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void push(char opr);
char pop();
int priority(char opr);


char expr[80];
char stack[80];
char postfix[80];

int top=-1;


void main()
{
	int i,j=0;
	char c;
	
	printf("Enter a valid expression:");
	scanf("%[^\n]",expr);
	
	for(i=0;expr[i]!='\0';i++)
	{
		
		if(expr[i]=='(')
		{
			push(expr[i]);
		}
		else if(expr[i]==')')
		{
			c=pop();
			while(c!='(' && top !=-1)
			{
				//strcat(postfix,c);
				postfix[j]=c;
				c=pop();
				j++;
			}
		}
		else if(expr[i]=='+' || expr[i]=='-' || expr[i]=='*' || expr[i]=='/')
		{
			while(priority(stack[top])>=priority(expr[i]) && stack[top]!='(' && top!=-1)
			{
				c=pop();
				postfix[j]=c;
				j++;
					//strcat(postfix,c);
					
			}
			push(expr[i]);
		}
		else
		{
			//strcat(postfix,expr[i]);
			postfix[j]=expr[i];
			j++;
		}
	}
	while(top!=-1)
	{
		c=pop();
		postfix[j]=c;
		j++;
		//strcat(postfix,c);
	}
	//printf("The expression is:%s\n",expr);
	
	printf("\nThe postfix expression is:");
	for(i=0;i<j;i++)
	{
		printf("%c",postfix[i]);
	}
	getch();
}

void push(char opr)
{
	if(top==79)
	{
		printf("\nStack Overflow\n");
		getchar();
		exit(1);
	}
	top=top+1;
	stack[top]=opr;
}

char pop()
{
	char c;
	if(top==-1)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		exit(1);
	}
	else
	{
		c=stack[top];
		top = top-1;
		return(c);
	}
}

int priority(char opr)
{
	if(opr == '*' || opr == '/')
	{
		return(2);
	}
	else if(opr == '+' || opr == '-') 
	{
		return(1);
	}
	else
	{
		return(0);
	}
}




