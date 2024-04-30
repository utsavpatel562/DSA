// Implement search & count alogrithm on singly link list //

#include<stdio.h>   // Standard input/output functions
#include<conio.h>   // Console input/output functions (for getch())
#include<malloc.h>  // Memory allocation functions (for malloc())

// Function declarations
void create(int item);  // Function to create a new node and add it to the list
void search(int N);     // Function to search for a node in the list by its value
void display();         // Function to display all nodes in the list

// Define a structure for the linked list node
struct node {
    int info;             // Data field for storing the node's value
    struct node *link;    // Pointer to the next node in the list
} *first = NULL;          // Global pointer to the first node in the list, initialized to NULL

// Main function
void main() {
    int item, choice, N;  // Variables for menu choice, item to insert, and node to search
    do {
        // Display menu and get user input
        printf("\n(1)Create \n(2)Search \n(3)Count & Display \n(4)Exit \nEnter Your choice:");
        scanf("%d", &choice);  // Get the user's choice from the menu
        
        switch (choice) {  // Perform action based on user's choice
            case 1:
                // Create a new node
                printf("\nEnter value for Insert:");
                scanf("%d", &item);  // Get the value for the new node
                create(item);        // Add the new node to the list
                break;

            case 2:
                // Search for a node in the list
                printf("\nEnter node for search:");
                scanf("%d", &N);  // Get the value to search for
                search(N);        // Search for the node with the specified value
                break;

            case 3:
                // Display all nodes in the list and count them
                display();  // Display the list and count the nodes
                break;
        }
    } while (choice < 4);  // Continue until the user chooses to exit
}

// Function to create a new node and add it to the end of the list
void create(int item) {
    struct node *newnode, *temp;  // New node and temporary pointer
    newnode = (struct node*)malloc(sizeof(struct node));  // Allocate memory for the new node
    newnode->info = item;  // Set the node's value
    newnode->link = NULL;  // Initialize the next pointer to NULL

    if (first == NULL) {  // If the list is empty
        first = newnode;  // The new node becomes the first node
    } else {
        // Traverse to the end of the list
        temp = first;  
        while (temp->link != NULL) {
            temp = temp->link;  // Move to the next node
        }
        // Add the new node at the end
        temp->link = newnode;
    }
}

// Function to search for a node in the list by its value
void search(int N) {
    struct node *temp;  // Temporary pointer to traverse the list
    int pos = 0;        // Position counter
    int flag = 0;       // Flag to indicate if the node is found

    if (first == NULL) {  // Check if the list is empty
        printf("\n\nLink List is Empty");  // Display message if empty
        getch();  // Wait for a key press
        return;   // Exit the function
    }

    // Traverse the list to find the node
    temp = first;  
    while (temp != NULL) {
        pos++;  // Increment the position
        if (temp->info == N) {  // Check if the current node has the search value
            printf("\nNode Found at %d", pos);  // Display the position if found
            flag = 1;  // Set the flag to indicate the node was found
            break;  // Exit the loop once the node is found
        }
        temp = temp->link;  // Move to the next node
    }

    if (flag == 0) {  // If the node wasn't found
        printf("\nNode not found in list");  // Display an appropriate message
    }
}

// Function to display all nodes in the list and count them
void display() {
    struct node *temp;  // Temporary pointer to traverse the list
    int count = 0;      // Node counter

    if (first == NULL) {  // Check if the list is empty
        printf("\nLink list is Empty");  // Display message if empty
    } else {
        // Display all nodes in the list
        temp = first;  
        printf("\nLink List:");
        while (temp != NULL) {
            printf("\t%d", temp->info);  // Print the node's value
            temp = temp->link;  // Move to the next node
            count++;  // Increment the node counter
        }
    }

    printf("\nTotal Number of node found %d", count);  // Display the total number of nodes
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
