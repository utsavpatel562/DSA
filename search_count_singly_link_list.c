// Implement search & count alogrithm on singly link list //

//CODE:-

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void create(int);
void search(int);
void display();
struct node{
	int info;
	struct node *link;
}*first;
void main()
{
	int item, choice,N;
	do
	{
		printf("\n(1)Create \n(2)Search \n(3)Count & Display \n(4)Exit \nEnter Your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter value for Insert:");
				scanf("%d",&item);
				create(item);
				break;
			case 2:
				printf("\nEnter node for search:");
				scanf("%d",&N);
				search(N);
				break;
			case 3:
				display();
				break;
		}
	}while(choice<4);
}
void create(int item)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=item;
	newnode->link=NULL;
	if(first==NULL)
	{
		first=newnode;
	}
	else
	{
		temp=first;
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newnode;
	}
	return;
}
void search(int N)
{
	struct node *temp;
	int pos=0; 
	int flag=0;
	if(first==NULL)
	{
		printf("\n\nLink List is Empty");
		getch();
		return;
	}
	temp=first;
	while(temp!=NULL)
	{
		pos++;
		if(temp->info==N)
		{
			printf("\nNode Found at %d",pos);
			flag=1;
			break;
		}
		temp=temp->link;
	}
	if(flag==0)
	{
		printf("\nNode not found in list");
	}
	return;
}
void display()
{
	struct node *temp;
	int count=0;
	if(first==NULL)
	{
		printf("\nLink list is Empty");
	}
	else
	{
		temp=first;
		printf("\nLink List:");
		while(temp!=NULL)
		{
			printf("\t%d",temp->info);
			temp=temp->link;
			count++;
		}
	}
	printf("\nTotal Number of node found %d",count);
	return;
}
/*
OUTPUT:-

(1)Create
(2)Search
(3)Count & Display
(4)Exit
Enter Your choice:1

Enter value for Insert:23

(1)Create
(2)Search
(3)Count & Display
(4)Exit
Enter Your choice:1

Enter value for Insert:56

(1)Create
(2)Search
(3)Count & Display
(4)Exit
Enter Your choice:1

Enter value for Insert:67

(1)Create
(2)Search
(3)Count & Display
(4)Exit
Enter Your choice:1

Enter value for Insert:34

(1)Create
(2)Search
(3)Count & Display
(4)Exit
Enter Your choice:3

Link List:      23      56      67      34
Total Number of node found 4

(1)Create
(2)Search
(3)Count & Display
(4)Exit
Enter Your choice:2

Enter node for search:56

Node Found at 2

(1)Create
(2)Search
(3)Count & Display
(4)Exit
Enter Your choice:2

Enter node for search:34

Node Found at 4

(1)Create
(2)Search
(3)Count & Display
(4)Exit
Enter Your choice:4
*/
