#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *lptr;
	struct node *rptr;
	
}*root,*p,*q;
void insert(int item)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=item;
	newnode->lptr=NULL;
	newnode->rptr=NULL;
	if(root==NULL)
	{
		root=newnode;
		return;
	}
	else
	{
		p=root;
		q=root;
		while(q!=NULL)
		{
			if(q->info==item)
			{
				printf("\nData Already Exist.");
				return;
			}
			else if(q->info<item)
			{
				p=q;
				q=q->lptr;
			}
			else
			{
				p=q;
				q=q->lptr;
			}
		}
		if(p->info<item)
		{
			p->lptr=newnode;
		}
		else
		{
			p->lptr=newnode;
		}
	}
}
void search(int item)
{
	struct node *temp;
	int flag=0;
	if(root==NULL)
	{
		printf("\nNode is not found");
		return;
	}
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			if(temp->info==item)
			{
				printf("\nNode is not found");
				flag=1;
				return;
			}
			else if(temp->info<item)
			{
				temp=temp->rptr;
			}
			else
			{
				temp=temp->lptr;
			}
		}
		if(flag==0)
		{
			printf("\nNode is not found");
		}
	}
}
void display(struct node *temp)
{
	if(root==NULL)
	{
		printf("\nTree is Empty");
		return;
	}
	if(temp==NULL)
	   return;
	else
	{
		display(temp->lptr);
		printf("\t%d",temp->info);
		display(temp->rptr);
	}
}
void main()
{
	int item,choice;
	do
	{
		printf("\n(1)Insert \n(2)Display \n(3)Search \n(4)Exit");
		printf("\nEnter Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Number:");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
			    display(root);
			    break;
			case 3:
				printf("Enter search Number:");
				scanf("%d",&item);
				search(item);
				break;
		}
	}while(choice>0 && choice<4);
}
