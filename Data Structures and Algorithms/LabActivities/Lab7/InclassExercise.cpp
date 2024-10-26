/*

Question

A binary heap is represented using a complete binary tree. A complete binary tree is a binary tree in which all the nodes at each level are completely filled except for the leaf nodes and the nodes in the last level are at the far left. While representing a heap as an array, assuming the index starts at 0, the root element is stored at 0. In general, if a parent node is at position i, then the left child node is at position (2*i + 1) and the right node is at (2*i +2).

Implement Heapsort by creating max-heap in C++. Use the given program for your implementation.

In the given program, the function heapify() converts the elements into a heap using recursion.
The function heapSort() sorts the array elements using heap sort. It starts from the non-leaf nodes and calls heapify() on each of them. This converts the array into a binary max heap.

Sample code */

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    //initialize the largest value as root
    int largest_value = root;
    
    //initializing left child and right child
    int left_child = 2 * root + 1; 
    int right_child = 2 * root + 2; 
 
    // If left child is larger than root the assign left child as largest value
    if (left_child < n && arr[left_child] > arr[largest_value])
        largest_value = left_child;
 
    // If right child is larger than root the assign right child as largest value
    if (right_child < n && arr[right_child] > arr[largest_value])
        largest_value = right_child;
 
    //if largest value is not the root swap it with the root
    if (largest_value != root) {
        swap(arr[root], arr[largest_value]);
 
        // Recursive section
        heapify(arr, n, largest_value);
    }
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
    // Build heap by using the heapify function
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    
    //Extract an element from a heap one by one
    for (int i = n - 1; i >= 0; i--) {
        
        // Move current root to end by swapping
        swap(arr[0], arr[i]);
 
        // calling max heapify 
        heapify(arr, i, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    string input;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> heap_arr;

    while (ss >> num) {
        heap_arr.push_back(num);
    }

    int n = heap_arr.size();
  
    heapSort(heap_arr.data(), n);
   
    displayArray(heap_arr.data(), n);
}