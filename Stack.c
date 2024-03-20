#include<stdio.h>
#define max 10
int push(int[],int);
int pop (int[],int);
void display(int[],int);

void main()
{
	int s[max];
	int top=-1,choice;
	do
	{
		printf("Select your choise from below.");
		printf("\n1) PUSH\n2) POP\n3) DISPLAY\n4) EXIT\n");
		printf("Enter your choise Here : ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				top=push(s,top);
				break;
				
			case 2:
				top=pop(s,top);
				break;
				
			case 3:
				display(s,top);
				break;
				
			default:
				exit(0);
		}
	}while(choice<4);
}

int push(int s[],int top)
{
	int x;
	if(top==max-1)
	{
		printf("\nStack is Overflow...!!");
		printf("\n\n");
	}
	else
	{
		printf("\nEnter value : ");
		scanf("%d",&x);
		printf("Value %d is Inserted.",x);
		printf("\n\n");
		top++;
		s[top]=x;
	}
	return top;
}

int pop(int s[],int top)
{
	int x;
	if(top==-1)
	{
		printf("\nStack is Underflow...!!");
		printf("\n\n");
	}
	else
	{
		x=s[top];
		printf("Removed value is : %d",x);
		printf("\n\n");
		top--;
	}
	
	return top;
}

void display(int s[],int top)
{
	int i;
	if(top==-1)
	{
		printf("\nStack is Empty");
	}
	else
	{
	printf("\nStack has Following Elements : \n");
	for(i=0;i<=top;i++)
	{
		printf("%d",s[i]);
		printf("\n");
	}
}
	printf("\n");
}