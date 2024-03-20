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
				printf("\nData Already Exits.");
				return;
			}
			else if(item>q->info)
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
		if(item>p->info)
		{
			p->rptr=newnode;
		}
		else
		{
			p->lptr=newnode;
		}
	}
}
void in_order(struct node *temp)
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
		in_order(temp->lptr);
		printf("\t%d",temp->info);
		in_order(temp->rptr);
	}
}
void pre_order(struct node *temp)
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
		printf("\t%d",temp->info);
		pre_order(temp->lptr);
		pre_order(temp->rptr);
	}
}
void post_order(struct node *temp)
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
		printf("\t%d",temp->info);
		post_order(temp->lptr);
		post_order(temp->rptr);
	}
}
void main()
{
	int item,choice;
	do
	{
		printf("\n(1)Insert \n(2)In-Order \n(3)Pre-Order \n(4)Post-Order \n(5)Exit");
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Number:");
				scanf("%d",&item);
				insert(item);
				break;
			case 2:
				in_order(root);
				break;
			case 3:
				pre_order(root);
				break;
			case 4:
				post_order(root);
				break;
		}
	}while(choice>0&&choice<5);
}