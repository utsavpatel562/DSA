// Implement algorithm of insert a newnode in sorted Link List //

//CODE:~

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void insert_sorted(int);
void display();
struct node
{
	int info;
	struct node *link;
}*first;
void main()
{
	int item,choice,pos;
	do
	{
		printf("\n(1)Insert \(2)Display \n(3)Exit \n\nEnter Choice :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			    printf("\nEnter value for Insert :");
				scanf("%d",&item);
				insert_sorted(item);
				break;
			case 2:
                display();
				break;
		}
	}while(choice < 3);
}
void insert_sorted(int item)
{
	struct node *newnode,*temp,*next;
	int flag = 0;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->info = item;
	if(first==NULL)
	{
		newnode->link = NULL;
		first = newnode;
	}
	else
	{
		if(item<first->info)
		{
			newnode->link = first;
			first = newnode;
		}
		else
		{
			temp = first;
			while(temp->link!=NULL)
			{
				next = temp->link;
				if(item>temp->info && item<=next->info)
				{
					newnode->link=next;
					temp->link=newnode;
					flag=1;
				}
				temp = temp->link;
			}
			if(flag==0)
			{
				temp->link=newnode;
				newnode->link=NULL;
			}
		}
	}
	return;
}
void display()
{
	struct node * temp;
	if(first==NULL)
	{
		printf("\nLink list is Empty");
	}
	else
    {
		temp = first;
		printf("\n\Link List :");
		while(temp!=NULL)
		{
			printf("\t%d",temp->info);
			temp=temp->link;
		}
	}
	return;
}

//OUTPUT:~
