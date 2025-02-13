// Implement Postfix Evaluation using Stack. DSA

#include<stdio.h>
#define max 20
void push(int[],int);
int pop (int[]);
int top=-1;
void display(int[],int);

void main()
{
	int s[max],x1,x2,result,i=0,ans,len;
	char p[50];
	
	printf("Enter Postfix Expression : ");
	gets(p);
	
	len=strlen(p);
	p[len]=')';
	
	puts(p);
	while(p[i]!=')')
	{	
		switch(p[i])
		{
			case '+':
				x1=pop(s);
				x2=pop(s);
				result=x2+x1;
				push(s,result);
				break;
				
			case '-':
				x1=pop(s);
				x2=pop(s);
				result=x2-x1;
				push(s,result);
				break;
				
			case '*':
				x1=pop(s);
				x2=pop(s);
				result=x2*x1;
				push(s,result);
				break;
				
			case '/':
				x1=pop(s);
				x2=pop(s);
				result=x2/x1;
				push(s,result);
				break;
				
			case '$':
				x1=pop(s);
				x2=pop(s);
				result=pow(x2,x1);
				push(s,result);
				break;
				
			default:
				push(s,p[i]-48);
				break;
		}
		display(s,top);
		i++;
	}
	ans=pop(s);
	printf("Postfix Evaulation is : %d",ans);
}

void push(int s[],int y)
{
	
	if(top>=max)
	{
		printf("\nStack is Overflow...!!");
		printf("\n\n");
	}
	else
	{
		top++;
		s[top]=y;
	}
}

int pop(int s[])
{
	int x;
	if(top<0)
	{
		printf("\nStack is Underflow...!!");
		printf("\n\n");
	}
	else
	{
		x=s[top];
		top--;
		return x;
	}
}

void display(int s[],int top)
{
	int i;
	printf("\nStack has Following Elements : \n");
	for(i=0;i<=top;i++)
	{
		printf("\t%d",s[i]);
		printf("\n");
	}
	printf("\n");
}
