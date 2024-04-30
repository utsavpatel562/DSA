// CODE BY UTSAV PATEL

#include<stdio.h> // Include the standard input/output library
#include<conio.h> // Include console I/O for getch()

// Function to merge two arrays in sorted order
void merge_sort(int[],int[],int,int);
void main()
{
	int a1[10],a2[10],n1,n2,i,j; // Arrays to hold the two input arrays

	// Prompt and read the size of the first array
	printf("\nEnter Size of First Array :");
	scanf("%d",&n1);

	// Read elements into the first array
	for(i=0;i<n1;i++)
	{
		printf("\nEnter %d Element :",i);
		scanf("%d",&a1[i]);
	}
	printf("\nEnter Size of Second Array :");
	scanf("%d",&n2);

	 // Read elements into the second array
	for(i=0;i<n2;i++)
	{
		printf("\nEnter %d Element :",i);
		scanf("%d",&a2[i]);
	}
	merge_sort(a1,a2,n1,n2); // Call the merge_sort function to merge the two arrays
	getch(); // Wait for a key press before exiting (useful for console-based execution)
}

// Function to merge and sort two arrays
void merge_sort(int a1[], int a2[], int n1, int n2) {
    int a3[20];  // Array to hold the merged and sorted elements
    int i = 0, j = 0, k = 0;  // Indices for a1, a2, and a3
    int size = n1 + n2;  // Total number of elements in the merged array

    // Loop to merge the two arrays
    while (k < size) {
        if (a1[i] < a2[j]) {  // If current element in a1 is smaller
            a3[k] = a1[i];   // Add it to the merged array
            k++;  // Move the index for the merged array
            i++;  // Move the index for the first array
        } else if (a1[i] > a2[j]) {  // If current element in a2 is smaller
            a3[k] = a2[j];   // Add it to the merged array
            k++;
            j++;  // Move the index for the second array
        } else {  // If elements are equal, add both but decrement the size to avoid double count
            a3[k] = a1[i];
            k++;
            i++;
            j++;
            size--;  // Adjust the total size since we added two elements at once
        }
    }

    // Add any remaining elements from the first array
    while (i < n1) {
        a3[k] = a1[i];
        k++;
        i++;
    }

    // Add any remaining elements from the second array
    while (j < n2) {
        a3[k] = a2[j];
        k++;
        j++;
    }

    // Output the merged and sorted array
    printf("\nAfter Sorting: ");
    for (i = 0; i < k; i++) {
        printf("\t%d", a3[i]);
    }
}
