// CODE BY UTSAV PATEL
#include<stdio.h>  // Standard I/O library for input/output operations
#include<conio.h>  // Console I/O for getch() function

// Function prototype for bubble sort
void Bubble_sort(int[], int);

// Main function to accept user input and sort the array
void main() {
   int i;           // Loop variable
   int a[50];       // Array to hold the numbers
   int N;           // Number of elements in the array

   // Prompt the user to enter the size of the list
   printf("Enter the size of List: ");
   scanf("%d", &N);  // Read the size of the array from the user

   printf("\nEnter the Numbers\n");  // Prompt to enter the array elements

   // Read the array elements from the user
   for (i = 0; i < N; i++) {
       scanf("%d", &a[i]);  // Store each input element in the array
   }

   // Call the bubble sort function to sort the array
   Bubble_sort(a, N);

   getch();  // Wait for a key press before exiting (useful for console-based programs)
}

// Bubble sort function to sort the array in ascending order
void Bubble_sort(int array[], int N) {
   int i, j;       // Loop variables
   int temp;       // Temporary variable for swapping

   // Outer loop: controls the number of passes
   for (i = 1; i < N; i++) {
       // Inner loop: compares adjacent elements and swaps if necessary
       for (j = 0; j < N - i; j++) {
           if (array[j] > array[j + 1]) {  // If the current element is greater than the next one
               // Swap the elements
               temp = array[j];
               array[j] = array[j + 1];
               array[j + 1] = temp;
           }
       }
   }

   // Output the sorted array
   printf("\nSorted Array is Given Below:");
   for (i = 0; i < N; i++) {  // Loop to print each element in the sorted array
       printf("\n%d", array[i]);
   }
}
