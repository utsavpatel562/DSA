#include<stdio.h>   // Standard I/O for input/output operations
#include<conio.h>   // Console I/O for getch()
#include<malloc.h>  // Memory allocation for malloc()

// Definition of a binary tree node
struct node {
    int info;            // Data stored in the node
    struct node *lptr;   // Pointer to the left child
    struct node *rptr;   // Pointer to the right child
};

// Global pointers
struct node *root = NULL;  // Root node of the tree
struct node *p = NULL, *q = NULL;  // Temporary pointers used for traversal

// Function to insert a node into the binary tree
void insert(int item) {
    struct node *newnode;  // Pointer for new node
    newnode = (struct node*) malloc(sizeof(struct node));  // Allocate memory for new node
    newnode->info = item;  // Store the item in the node
    newnode->lptr = NULL;  // Initialize left pointer to NULL
    newnode->rptr = NULL;  // Initialize right pointer to NULL

    // If the tree is empty, set the root to the new node
    if (root == NULL) {
        root = newnode;
        return;  // Exit function
    } else {
        // If the tree is not empty, find the correct position to insert
        p = root;  // Start from the root
        q = root;

        // Traverse the tree to find the correct insertion point
        while (q != NULL) {
            if (q->info == item) {  // If item already exists
                printf("\nData Already Exists.");  // Notify user
                return;  // Exit function
            } else if (q->info < item) {  // If current node's info is less than item
                p = q;  // Store current node
                q = q->rptr;  // Move to the right child
            } else {  // If current node's info is greater than item
                p = q;  // Store current node
                q = q->lptr;  // Move to the left child
            }
        }

        // Insert the new node at the correct position
        if (p->info < item) {  // Insert to the right
            p->rptr = newnode;
        } else {  // Insert to the left
            p->lptr = newnode;
        }
    }
}

// Function to search for an item in the binary tree
void search(int item) {
    struct node *temp;  // Pointer to traverse the tree
    int flag = 0;       // Flag to indicate if item is found

    // If the tree is empty, return early
    if (root == NULL) {
        printf("\nNode is not found");  // Notify user
        return;  // Exit function
    } else {
        temp = root;  // Start from the root

        // Traverse the tree to search for the item
        while (temp != NULL) {
            if (temp->info == item) {  // If item is found
                printf("\nNode is found");  // Notify user
                flag = 1;  // Set flag to indicate item is found
                return;  // Exit function
            } else if (temp->info < item) {  // If current node's info is less than item
                temp = temp->rptr;  // Move to the right child
            } else {  // If current node's info is greater than item
                temp = temp->lptr;  // Move to the left child
            }
        }

        // If item is not found
        if (flag == 0) {
            printf("\nNode is not found");  // Notify user
        }
    }
}

// Function to display the elements of the binary tree in-order
void display(struct node *temp) {
    // If the tree is empty, return early
    if (root == NULL) {
        printf("\nTree is Empty");  // Notify user
        return;  // Exit function
    }

    if (temp == NULL) {  // Base case for recursion
        return;
    }

    // In-order traversal: left child, current node, right child
    display(temp->lptr);  // Recur to the left child
    printf("\t%d", temp->info);  // Print current node's info
    display(temp->rptr);  // Recur to the right child
}

// Main function to interact with the user and perform operations on the tree
void main() {
    int item;  // Item to be inserted or searched
    int choice;  // User's menu choice

    // Main loop for user input and performing operations
    do {
        // Display menu options to the user
        printf("\n(1) Insert \n(2) Display \n(3) Search \n(4) Exit");
        printf("\nEnter Choice:");  // Prompt user for choice
        scanf("%d", &choice);  // Read user choice

        // Perform action based on user's choice
        switch (choice) {
            case 1:  // Insert a new item into the tree
                printf("Enter Number:");  // Prompt user for item
                scanf("%d", &item);  // Read item from the user
                insert(item);  // Call insert function to add item to the tree
                break;

            case 2:  // Display the tree
                display(root);  // Call display function to print the tree in-order
                break;

            case 3:  // Search for an item in the tree
                printf("Enter search Number:");  // Prompt user for item to search
                scanf("%d", &item);  // Read item from the user
                search(item);  // Call search function to find the item in the tree
                break;

            case 4:  // Exit the program
                break;  // Exit switch statement
        }

    } while (choice > 0 && choice < 4);  // Continue until user chooses to exit
}
