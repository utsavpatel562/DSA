#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void ins_first(int);
void ins_last(int);
void Display();
struct node
{
	int info;
	struct node *lptr;
	struct node *rptr;
}*l,*r;
void main()
{
	int choice,item;
	l=r=NULL;
	do
	{
		printf("\nDoubly Link List: \n(1)Insert at First \n(2)Insert at Last \n(3)Display \n(4)Exit \nEnter Your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("\nEnter Item:");
			scanf("%d",&item);
			ins_first(item);
			break;

			case 2:
			printf("\nEnter Item:");
			scanf("%d",&item);
			ins_last(item);
			break;

			case 3:
			Display();
			break;
		}
	}while(choice < 4);
}
void ins_first(int item)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMemory Not Allocated");
		getch();
		return;
	}
	newnode->info=item;
	if(l==NULL)
	{
		newnode->lptr=NULL;
		newnode->rptr=NULL;
		l=newnode;
		r=newnode;
		return;
	}
	else
	{
		newnode->lptr=NULL;
		newnode->rptr=l;
		l->lptr=newnode;
		l=newnode;
		return;
	}
}
void ins_last(int item)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMemory Not Allocated" );
		getch();
		return;
	}
	newnode->info=item;
	if(l==NULL)
	{
		newnode->lptr=NULL;
		newnode->rptr=NULL;
		l=newnode;
		r=newnode;
		return;
	}
	else
	{
		newnode->lptr=r;
		newnode->rptr=NULL;
		r->rptr=newnode;
		r=newnode;
		return;
	}
}
void Display()
{
	struct node *temp;
	if(l==NULL)
	{
		printf("\nEmpty Linked List...");
		getch();
		return;
	}
	printf("\nList is:");
	temp=l;
	while(temp!=NULL)
	{
		printf("\t%d",temp->info);
		temp=temp->rptr;
	}
	getch();
}
