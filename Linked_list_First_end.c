//Implement

//CODE:~

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void ins_first(int);
void ins_last(int);
struct node
{
	int info;
	struct node *link;
}*first;
void main()
{
	int item,choice;
	do
	{
		printf("\n(1)Insert at First\n(2)Insert at End\n(3)Display\n(4)Exit");
		printf("\n\nEnter Choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			       printf("Enter Item :");
				   scanf("%d",&item);
				   ins_first(item);
				   break;
			case 2:
			       printf("Enter Item :");
				   scanf("%d",&item);
				   ins_last(item);
				   break;
		    case 3:
			       display();
		}
	} while(choice>0&&choice<4);
}
void ins_first(int item)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if (newnode == NULL)
	{
		printf("Memory not allocated");
		return;
	}
	newnode->info = item;
	if(first == NULL)
	{
		newnode->link = NULL;
		first = newnode;
	}
	else
	{
		newnode->link = first;
		first = newnode;
	}
}
void ins_last(int item)
{
	struct node *newnode, *temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("\nMemory not allocated");
		return;
	}
	newnode->node = item;
	newnode->link = NULL;
	if(first == NULL)
	{
		first = newnode; 
		return;
	}
	temp = first;
	while(temp->link!=NULL)
	{
		temp = temp->link;
	}
	temp->link = newnode;
	return;
}
void display()
{
	struct node *temp;
	if(first == NULL)
	{
		printf("\n\nLinked List is Empty");
		return;
	}
	temp = first;
	while(temp!=NULL)
	{
		printf("\n\t%d",temp->info);
		temp = temp->link;
	}
}	

//OUTPUT:~