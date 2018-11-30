#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int stack[80];
int top=-1;
char expr[80];
void push(int item);
int pop();


void main()
{
	int i,val1,val2,result,temp;
	const char s[2] = " ";
   	char *token;
	printf("Enter the valid expression:");
	//scanf("%[^\n]",expr);
	gets(expr);
	token = strtok(expr, s);
	
	//for(i=0;expr[i]!='\0';i++)
	while(token != NULL)
	{
		if(isdigit(*token))
		{
			temp=atoi (token);
			push(temp);
		}
		if(*token=='+'||*token=='-'||*token=='*'||*token=='/')
		{
			val1=pop();
			val2=pop();
			
			switch(*token)
			{
				case '+': push(val2 + val1); break;
	            case '-': push(val2 - val1); break;
	            case '*': push(val2 * val1); break;
	            case '/': push(val2 / val1); break;
			}
		}
		token = strtok(NULL, s);
	}
	
	result=pop();	
	printf("The result is: %d",result);
	getch();
}

void push(int item)
{
	top=top+1;
	stack[top]=item;
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("\nExited\n");
		return;
	}
	item=stack[top];
	top=top-1;
	return item;
}


