#include<stdio.h>  // Include standard I/O header for input/output functions
#define max 10     // Define a constant for the maximum stack size

// Function prototypes for stack operations
int push(int[], int);   // Push a value onto the stack
int pop(int[], int);    // Pop a value from the stack
void display(int[], int);  // Display the stack's contents

// Main function to handle the stack operations
void main() {
    int s[max];  // Declare the stack array with a size of 10
    int top = -1;  // Initialize the top of the stack to -1 (indicating an empty stack)
    int choice;  // Variable to store the user's menu choice
    
    // Loop to allow user interaction with the stack operations
    do {
        // Display the menu for stack operations
        printf("Select your choice from below.");
        printf("\n1) PUSH\n2) POP\n3) DISPLAY\n4) EXIT\n");
        printf("Enter your choice Here: ");
        scanf("%d", &choice);  // Get the user's choice
        
        // Switch case to handle the user's menu choice
        switch (choice) {
            case 1:
                // Push an element onto the stack
                top = push(s, top);
                break;
            case 2:
                // Pop an element from the stack
                top = pop(s, top);
                break;
            case 3:
                // Display the stack contents
                display(s, top);
                break;
            default:
                // Exit the program for any other choice (like 4)
                exit(0);
        }
    } while (choice < 4);  // Continue until the user chooses to exit
}

// Function to push a value onto the stack
int push(int s[], int top) {
    int x;  // Variable to hold the new value to be pushed

    // Check if the stack is full (overflow)
    if (top == max - 1) {
        printf("\nStack is Overflow...!!");  // Indicate that the stack is full
        printf("\n\n");
    } else {
        // Get the new value from the user
        printf("\nEnter value: ");
        scanf("%d", &x);
        
        // Insert the new value onto the stack
        printf("Value %d is Inserted.", x);  // Confirm the insertion
        printf("\n\n");
        top++;  // Increment the top to point to the new position
        s[top] = x;  // Store the value at the new top position
    }

    return top;  // Return the updated top index
}

// Function to pop a value from the stack
int pop(int s[], int top) {
    int x;  // Variable to hold the value being popped

    // Check if the stack is empty (underflow)
    if (top == -1) {
        printf("\nStack is Underflow...!!");  // Indicate that the stack is empty
        printf("\n\n");
    } else {
        // Get the top value and reduce the top index
        x = s[top];  // Store the value being popped
        printf("Removed value is: %d", x);  // Display the popped value
        printf("\n\n");
        top--;  // Decrement the top to remove the top element
    }

    return top;  // Return the updated top index
}

// Function to display the stack's contents
void display(int s[], int top) {
    int i;  // Loop variable to iterate through the stack
    
    // Check if the stack is empty
    if (top == -1) {
        printf("\nStack is Empty");  // Indicate the stack is empty
    } else {
        // Print all the elements in the stack
        printf("\nStack has Following Elements: \n");
        for (i = 0; i <= top; i++) {
            printf("%d", s[i]);  // Display each element
            printf("\n");       // Newline for readability
        }
    }

    printf("\n");  // Additional newline for formatting
}
