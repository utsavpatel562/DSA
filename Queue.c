#include<stdio.h>  // Include the standard I/O header for input/output functions
#include<conio.h>  // Include console I/O header (specific to certain compilers, not portable)
#define MAX 5      // Define a constant for the maximum queue size

// Queue array, with front (F) and rear (R) indicators
int Q[MAX], F = -1, R = -1;
int x;  // Variable to hold user input for pushing into the queue

// Function prototypes for queue operations
void push();  
void pop();
void display();

// Main function to run the queue operations
void main() {
    int choice;  // Variable to store the user's menu choice

    // Loop for displaying menu and processing user choice
    do {
        // Display the menu
        printf("\n(1) Push into Queue\n(2) Pop From Queue\n(3) Display");
        printf("\n(4) Exit \nEnter Choice: ");
        
        // Get the user's choice
        scanf("%d", &choice);
        
        // Handle the user's choice with a switch statement
        switch (choice) {
            case 1:
                push();  // Push an element into the queue
                break;
            case 2:
                pop();   // Pop an element from the queue
                break;
            case 3:
                display();  // Display the contents of the queue
                break;
        }
    } while (choice > 0 && choice < 4);  // Continue until the user chooses to exit
}

// Function to push an element into the queue
void push() {
    // Check if the queue is full
    if (R == MAX - 1) {
        printf("\nQueue is Overflow!!!");  // Notify that the queue is full
        return;  // Return early
    }

    // Get the value to be pushed into the queue
    printf("\nEnter Value to be Pushed: ");
    scanf("%d", &x);

    // If the queue is empty, initialize front and rear
    if (F == -1) {
        F = 0;
        R = 0;
    } else {
        R++;  // Otherwise, move rear to the next position
    }

    // Insert the new element at the rear
    Q[R] = x;
}

// Function to pop an element from the queue
void pop() {
    // Check if the queue is empty
    if (F == -1) {
        printf("\nQueue is Underflow!!!");  // Notify that the queue is empty
        return;  // Return early
    }

    // Display the element being popped
    printf("\n%d is Popped.", Q[F]);

    // If there's only one element, reset front and rear
    if (F == R) {
        F = -1;
        R = -1;
    } else {
        F = F + 1;  // Otherwise, move front to the next position
    }
}

// Function to display the queue contents
void display() {
    int i;  // Variable for loop iteration

    // Check if the queue is empty
    if (F == -1) {
        printf("\nQueue is Empty.");  // Notify that the queue has no elements
        return;  // Return early
    }

    // Display the contents of the queue
    printf("\nQueue is Printed Below:");
    for (i = F; i <= R; i++) {  // Loop through the queue from front to rear
        printf("%d\n", Q[i]);  // Print each element
    }
}
