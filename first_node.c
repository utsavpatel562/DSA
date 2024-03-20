#include<stdio.h>
#include<conio.h>
void create_link_list(int);
void Display();
struct node
{
	int info;
	struct node *link;
}*first;
void main()
{
	int ch,item;
	do
	{
		printf("\n(1)Insert Element into list\n(2)View Inserted Element\n(3)Exit\n\nEnter choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter items:");
				scanf("%d",&item);
				create_link_list(item);
				break;
			case 2:
				Display();
				break;
		}
	} while(ch<=2);
}
void create_link_list(int item)
{
	struct node *newnode, *temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMemory not allocated");
		getch();
		return;
	}
	newnode->info=item;
	newnode->link=NULL;
	if(first==NULL)
	{
		first=newnode;
		return;
	}
	temp=first;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=newnode;
	return;
}
void Display()
{
	struct node *temp;
	temp=first;
	while(temp!=NULL)
	{
		printf("\t %d",temp->info);
		temp=temp->link;
	}
	getch();
}
