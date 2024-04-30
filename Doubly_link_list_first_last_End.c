#include<stdio.h>   // Standard input/output functions
#include<conio.h>   // Console input/output functions (for getch())
#include<malloc.h>  // Memory allocation functions (for malloc())

// Function declarations for inserting nodes and displaying the list
void ins_first(int item);  // Function to insert a node at the beginning of the list
void ins_last(int item);   // Function to insert a node at the end of the list
void Display();            // Function to display the doubly linked list

// Define a structure for doubly linked list nodes
struct node {
    int info;             // Data field for storing the node's value
    struct node *lptr;    // Pointer to the previous node in the list
    struct node *rptr;    // Pointer to the next node in the list
} *l, *r;                // Global pointers to the first and last nodes in the list

// Main function to control the program flow
void main() {
    int choice, item;  // Variables for user input and node values
    l = r = NULL;      // Initialize the first and last nodes to NULL
    
    // Loop to interact with the user
    do {
        printf("\nDoubly Link List: \n(1)Insert at First \n(2)Insert at Last \n(3)Display \n(4)Exit \nEnter Your choice:");
        scanf("%d", &choice);  // Get the user's menu choice

        // Perform actions based on the user's choice
        switch (choice) {
            case 1:
                printf("\nEnter Item:");  // Prompt for the value to insert at the beginning
                scanf("%d", &item);  // Get the value to insert
                ins_first(item);    // Call the function to insert at the beginning
                break;

            case 2:
                printf("\nEnter Item:");  // Prompt for the value to insert at the end
                scanf("%d", &item);  // Get the value to insert
                ins_last(item);     // Call the function to insert at the end
                break;

            case 3:
                Display();  // Call the function to display the list
                break;
        }
    } while (choice < 4);  // Continue until the user chooses to exit
}

// Function to insert a node at the beginning of the list
void ins_first(int item) {
    struct node *newnode;  // Create a new node
    newnode = (struct node *)malloc(sizeof(struct node));  // Allocate memory for the new node

    // Check if memory allocation was successful
    if (newnode == NULL) {
        printf("\nMemory Not Allocated");
        getch();  // Wait for a key press
        return;   // Exit if memory allocation failed
    }

    // Set the node's value
    newnode->info = item; 

    // If the list is empty, initialize both lptr and rptr to NULL
    if (l == NULL) {
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        l = newnode;  // The new node becomes the first node
        r = newnode;  // The new node also becomes the last node
        return;
    } else {
        // If the list is not empty, update pointers to insert at the beginning
        newnode->lptr = NULL;  // The new first node's lptr is NULL
        newnode->rptr = l;     // The new first node's rptr points to the old first node
        l->lptr = newnode;     // The old first node's lptr points to the new first node
        l = newnode;           // The new node becomes the first node
        return;
    }
}

// Function to insert a node at the end of the list
void ins_last(int item) {
    struct node *newnode;  // Create a new node
    newnode = (struct node *)malloc(sizeof(struct node));  // Allocate memory for the new node

    // Check if memory allocation was successful
    if (newnode == NULL) {
        printf("\nMemory Not Allocated");
        getch();  // Wait for a key press
        return;   // Exit if memory allocation failed
    }

    // Set the node's value
    newnode->info = item; 

    // If the list is empty, initialize both lptr and rptr to NULL
    if (l == NULL) {
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        l = newnode;  // The new node becomes the first node
        r = newnode;  // The new node also becomes the last node
        return;
    } else {
        // If the list is not empty, update pointers to insert at the end
        newnode->lptr = r;  // The new last node's lptr points to the old last node
        newnode->rptr = NULL;  // The new last node's rptr is NULL
        r->rptr = newnode;   // The old last node's rptr points to the new last node
        r = newnode;          // The new node becomes the last node
        return;
    }
}

// Function to display all nodes in the list
void Display() {
    struct node *temp;  // Temporary pointer to traverse the list

    if (l == NULL) {  // Check if the list is empty
        printf("\nEmpty Linked List...");  // Display a message if it's empty
        getch();  // Wait for a key press
        return;  // Exit the function if there's nothing to display
    }

    // Display all nodes from the first to the last
    printf("\nList is:");
    temp = l;  // Start from the first node
    while (temp != NULL) {
        printf("\t%d", temp->info);  // Display the value of the current node
        temp = temp->rptr;  // Move to the next node
    }

    getch();  // Wait for a key press after displaying the list
}
