# Data Structure and Algorithm

This repository contains implementations of various data structures and algorithms in the C programming language. These implementations serve as educational resources and examples for understanding fundamental concepts in computer science.

## Data Structures

### Linked List

The linked list is a linear data structure where elements are stored in a sequence and each element points to the next one. It includes:

- **Singly Linked List**: Each node contains data and a pointer to the next node.
- **Doubly Linked List**: Each node contains data, a pointer to the next node, and a pointer to the previous node.
- **Circular Linked List**: The last node points to the first node, forming a circle.

### Queue

A queue is a linear data structure that follows the FIFO (First In, First Out) principle. It includes:

- **Circular Queue**: A fixed-size queue where the last element is connected to the first element, forming a circle.

## Sorting Algorithms

### Insertion Sort

Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. It takes an element from the array and inserts it into the correct position in the sorted part of the array.

### Bubble Sort

Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.

### Selection Sort

Selection sort is a simple sorting algorithm that repeatedly selects the minimum element from the unsorted part of the array and puts it at the beginning.

### Merge Sort

Merge sort is a divide and conquer algorithm that divides the array into two halves, sorts them separately, and then merges the sorted halves.

### Radix Sort

Radix sort is a non-comparative sorting algorithm that sorts numbers by processing individual digits.

## Usage

Each data structure or algorithm implementation is contained in its own C file. To use a particular implementation:

1. Clone the repository: `git clone https://github.com/your-username/Data-Structure-and-Algorithm.git`
2. Navigate to the directory of the implementation you're interested in.
3. Compile the C file using a C compiler like GCC: `gcc filename.c -o filename`.
4. Run the executable file: `./filename`.

## Contributing

Contributions are welcome! If you would like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/my-feature`.
3. Make your changes and commit them: `git commit -m 'Add some feature'`.
4. Push to the branch: `git push origin feature/my-feature`.
5. Submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
