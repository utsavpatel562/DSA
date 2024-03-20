//Implement insertion algorithm for insert new node before or after given node in Doubly Linked List // 

//CODE:-

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void create_doubly_list(int);
void ins_before(int);
void ins_after(int);
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
		printf("\nDoubly Linke List \n(1)Create List \n(2)Insert Before node \n(3)Insert After Node \n(4)Display \n(5)Exit");
		printf("\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter Item:");
				scanf("%d",&item);
				create_doubly_list(item);
				break;
			case 2:
				printf("\nEnter Item:");
				scanf("%d",&item);
				ins_before(item);
				break;
			case 3:
				printf("\nEnter Item:");
				scanf("%d",&item);
				ins_after(item);
				break;
			case 4:
				Display();
				break;
	    }
	}while(choice>0&&choice<5);
}
void create_doubly_list(int item)
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
		newnode->rptr=NULL;
		newnode->lptr=r;
		r->rptr=newnode;
		r=newnode;
		return;
	}
}
void ins_before(int item)
{
	struct node *newnode,*ptr,*preptr;
	int N;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMemory Not Allocated");
		return;
	}
	newnode->info=item;
	printf("\nEnter Node where you insert before:");
	scanf("%d",&N);
	ptr=l;
	while(ptr->info != N && ptr->rptr!=NULL)
	{
		ptr=ptr->rptr;
	}
	if(ptr->info==N)
	{
		if(ptr==l)
		{
			newnode->lptr=ptr->lptr;
			newnode->rptr=ptr;
			ptr->lptr=newnode;
			l=newnode;
		}
		else
		{
			newnode->lptr=ptr->lptr;
			newnode->rptr=ptr;
			ptr->lptr->rptr=newnode;
			ptr->lptr=newnode;
		}
	}
	else
	{
		printf("\n Node Not Found");
	}
	return;
}
void ins_after(int item)
{
	struct node *newnode,*ptr;
	int N;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMemory Not Allocated");
		return;
	}
	newnode->info=item;
	printf("\nEnter Node where you insert after:");
	scanf("%d",&N);
	ptr=l;
	while(ptr->info != N && ptr->rptr!=NULL)
	{
		ptr=ptr->rptr;
	}
	if(ptr->info==N)
	{
		if(ptr==r)
		{
			newnode->rptr=ptr->rptr;
			newnode->lptr=ptr;
			ptr->rptr=newnode;
			r=newnode;
		}
		else
		{
			newnode->rptr=ptr->rptr;
			newnode->lptr=ptr;
			ptr->rptr->lptr=newnode;
			ptr->rptr=newnode;
		}
	}
	else
	{
		printf("\nNode is Not Found");
	}
	return;
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
	printf("List is :");
	temp=l;
	while(temp!=NULL)
	{
		printf("\t%d",temp->info);
		temp=temp->rptr;
	}
	getch();
}


OUTPUT:-

Doubly Linke List
(1)Create List
(2)Insert Before node
(3)Insert After Node
(4)Display
(5)Exit
Enter Your Choice:1
Enter Item:10

Doubly Linke List
(1)Create List
(2)Insert Before node
(3)Insert After Node
(4)Display
(5)Exit
Enter Your Choice:1
Enter Item:20

Doubly Linke List
(1)Create List
(2)Insert Before node
(3)Insert After Node
(4)Display
(5)Exit
Enter Your Choice:1
Enter Item:30

Doubly Linke List
(1)Create List
(2)Insert Before node
(3)Insert After Node
(4)Display
(5)Exit
Enter Your Choice:4
List is :       10      20      30

Doubly Linke List
(1)Create List
(2)Insert Before node
(3)Insert After Node
(4)Display
(5)Exit
Enter Your Choice:2

Enter Item:15

Enter Node where you insert before:20

Doubly Linke List
(1)Create List
(2)Insert Before node
(3)Insert After Node
(4)Display
(5)Exit
Enter Your Choice:4
List is :       10      15      20      30

Doubly Linke List
(1)Create List
(2)Insert Before node
(3)Insert After Node
(4)Display
(5)Exit
Enter Your Choice:3

Enter Item:35

Enter Node where you insert after:30

Doubly Linke List
(1)Create List
(2)Insert Before node
(3)Insert After Node
(4)Display
(5)Exit
Enter Your Choice:4
List is :       10      15      20      30      35

Doubly Linke List
(1)Create List
(2)Insert Before node
(3)Insert After Node
(4)Display
(5)Exit
Enter Your Choice:5