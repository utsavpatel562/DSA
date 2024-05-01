//Implement insertion algorithm for insert new node before or after given node in Doubly Linked List // 

//CODE:-

#include<stdio.h>   // Include standard input/output library
#include<conio.h>   // Include console I/O library (specific to certain compilers)
#include<malloc.h>  // Include library for dynamic memory allocation

// Function prototypes for creating, inserting, and displaying doubly linked list
void create_doubly_list(int);  // Create a doubly linked list with an initial node
void ins_before(int);          // Insert a node before a specified node
void ins_after(int);           // Insert a node after a specified node
void Display();                // Display the entire doubly linked list

// Node structure for the doubly linked list
struct node {
    int info;                   // Data held by the node
    struct node *lptr;          // Pointer to the previous node
    struct node *rptr;          // Pointer to the next node
} *l, *r; // 'l' points to the head and 'r' to the tail of the list

// Main function for user interaction with the doubly linked list
void main() {
    int choice, item; // User choice and item to insert
    l = r = NULL;     // Initialize head and tail to NULL
    
    do {
        // Display menu for user interaction
        printf("\nDoubly Linked List Menu:");
        printf("\n(1) Create List \n(2) Insert Before Node \n(3) Insert After Node \n(4) Display \n(5) Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice); // Get user's choice
        
        switch (choice) { // Handle user choice with a switch case
            case 1:
                // Create a new doubly linked list with the given item
                printf("Enter Item: ");
                scanf("%d", &item);
                create_doubly_list(item);
                break;
                
            case 2:
                // Insert a node before a specified node
                printf("\nEnter Item to Insert: ");
                scanf("%d", &item);
                ins_before(item);
                break;
                
            case 3:
                // Insert a node after a specified node
                printf("\nEnter Item to Insert: ");
                scanf("%d", &item);
                ins_after(item);
                break;
                
            case 4:
                // Display the doubly linked list
                Display();
                break;
                
            default:
                // Exit the loop and program
                exit(0);
        }
    } while (choice > 0 && choice < 5); // Continue the loop while choice is between 1 and 4
}

// Function to create a new doubly linked list
void create_doubly_list(int item) {
    struct node *newnode; // Pointer to a new node
    
    // Allocate memory for the new node
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) { // Check if memory allocation failed
        printf("\nMemory Not Allocated");
        getch(); // Wait for user input (specific to some compilers)
        return; // Return early if allocation failed
    }
    
    newnode->info = item; // Set the data for the new node
    
    if (l == NULL) { // If the list is empty, initialize it
        newnode->lptr = NULL; // No previous node
        newnode->rptr = NULL; // No next node
        l = newnode;          // Set the head to the new node
        r = newnode;          // Set the tail to the new node
        return; // Exit the function
    } else {
        // Add the new node to the end of the list
        newnode->rptr = NULL;  // No next node
        newnode->lptr = r;     // Previous node is the current tail
        r->rptr = newnode;     // Update the current tail to point to the new node
        r = newnode;           // Set the tail to the new node
        return; // Exit the function
    }
}

// Function to insert a node before a specified node in the doubly linked list
void ins_before(int item) {
    struct node *newnode, *ptr, *preptr; // Pointers for new node and traversal
    int N; // Node value where the new node is to be inserted before
    
    // Allocate memory for the new node
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) { // Check if memory allocation failed
        printf("\nMemory Not Allocated");
        return; // Return early if allocation failed
    }
    
    newnode->info = item; // Set the data for the new node
    
    printf("\nEnter Node where you insert before: ");
    scanf("%d", &N); // Node value to insert before
    
    ptr = l; // Start from the head of the list
    
    // Traverse the list to find the specified node
    while (ptr->info != N && ptr->rptr != NULL) {
        ptr = ptr->rptr; // Move to the next node
    }
    
    if (ptr->info == N) { // If the node is found
        if (ptr == l) { // If the specified node is the head
            newnode->lptr = ptr->lptr;  // Previous pointer of new node
            newnode->rptr = ptr;        // Next pointer of new node
            ptr->lptr = newnode;        // Update the head's previous pointer
            l = newnode;                // Set the new node as the new head
        } else {
            newnode->lptr = ptr->lptr;  // Previous pointer of new node
            newnode->rptr = ptr;        // Next pointer of new node
            ptr->lptr->rptr = newnode;  // Link the previous node to new node
            ptr->lptr = newnode;        // Update the previous pointer of specified node
        }
    } else {
        printf("\n Node Not Found"); // If the node isn't found in the list
    }
    
    return; // Exit the function
}

// Function to insert a node after a specified node in the doubly linked list
void ins_after(int item) {
    struct node *newnode, *ptr; // Pointers for new node and traversal
    int N; // Node value where the new node is to be inserted after
    
    // Allocate memory for the new node
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) { // Check if memory allocation failed
        printf("\nMemory Not Allocated");
        return; // Return early if allocation failed
    }
    
    newnode's info = item; // Set the data for the new node
    
    printf("\nEnter Node where you insert after: "); // Node to insert after
    scanf("%d", &N);
    
    ptr = l; // Start from the head
    
    // Traverse the list to find the specified node
    while (ptr->info != N && ptr->rptr != NULL) {
        ptr = ptr's rptr; // Move to the next node
    }
    
    if (ptr's info == N) { // If the node is found
        if (ptr == r) { // If the specified node is the tail
            newnode's rptr = NULL;       // Next pointer for the new node
            newnode's lptr = ptr;       // Previous pointer for the new node
            ptr's rptr = newnode;        // Link the tail to the new node
            r = newnode;                 // Set the new node as the new tail
        } else { 
            newnode's rptr = ptr's rptr; // Link the new node's next to the specified node's next
            newnode's lptr = ptr;       // Previous pointer for the new node
            ptr's rptr's lptr = newnode; // Update the next node's previous pointer
            ptr's rptr = newnode;        // Update the current node's next pointer
        }
    } else {
        printf("\nNode Not Found"); // If the node isn't found
    }
    
    return; // Exit the function
}

// Function to display the doubly linked list
void Display() {
    struct node *temp; // Temporary pointer for traversal
    
    if (l == NULL) { // If the list is empty
        printf("\nEmpty Linked List..."); // Indicate that the list is empty
        getch(); // Wait for user input (specific to some compilers)
        return; // Return early if list is empty
    }
    
    printf("List is:"); // Start of the list output
    
    temp = l; // Start from the head
    
    while (temp != NULL) { // Traverse the list
        printf("\t%d", temp's info); // Display each node's data
        temp = temp's rptr;         // Move to the next node
    }
    
    getch(); // Wait for user input (specific to some compilers)
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
