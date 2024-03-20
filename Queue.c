

#include<stdio.h>
#include<conio.h>
#define MAX 5
int Q[MAX],F=-1,R=-1,x;
void push();
void pop();
void dispay();
void main()
{
	int choice;
	do
	{
		printf("\n(1) Push into Queue\n(2) Pop From Queue\n(3) Display");
		printf("\n(4) Exit \nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			   push();
			   break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
		}
	} while(choice>0 && choice<4);
}
void push()
{
	if(R==MAX-1)
	{
		printf("\nQueue is Overflow!!!");
		return;
	}
	printf("\nEnter Value to ne Pushed : ");
	scanf("%d",&x);
	if(F==-1)
	{
		F=0;
		R=0;
	}
	else
	{
		R++;
	}
	Q[R]=x;
}
void pop()
{
	if(F==-1)
	{
		printf("\nQueue is Underflow!!!");
		return;
	}
	printf("\n%d is Popped.",Q[F]);
	if(F==R)
	{
		F=-1;
		R=-1;
	}
	else
	{
		F=F+1;
	}
}
void display()
{
	int i;
	if(F==-1)
	{
		printf("\nQueue is Empty.");
		return;
	}
	printf("\nQueue is Printed Below:");
	for(i=F;i<R;i++)
	{
		printf("%d\n",Q[i]);
	}
}
