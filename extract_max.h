#include <iostream>
//in collab with prog partner Lexi Bobb!

void heapifyDown(int arr[], int index, int size) {
    int left_child_index = (index * 2) + 1;
    int right_child_index = (index * 2) + 2;
    int left_child;
    int right_child;
    int largest_num = arr[size - 1];

    //1. if index is a leaf or children of index are greater than index -> stop
    if (left_child_index > size - 1 && right_child_index > size - 1) {
        return;
    }
    //else if there's a left child but not a right child, initialize it
    else if (left_child_index <= size - 1 && right_child_index > size - 1) {
        left_child = arr[left_child_index];
        //if the left child is bigger than the parent, swap
        if (left_child > arr[index]) {
            int temp = arr[index];
            arr[left_child_index] = temp;
            arr[index] = left_child; //swap
            index = left_child_index;            
            heapifyDown(arr, index, size);
            return;
        }

    }
    //if there is a right child but no left, initialize it
    else if (right_child_index <= size - 1 && left_child_index > size - 1) {
        right_child = arr[right_child_index];
        //and if right child is greater than parent, swap them
        if (right_child > arr[index]) {
            int temp = arr[index];
            arr[right_child_index] = temp;
            arr[index] = right_child; //swap
            index = right_child_index;
            heapifyDown(arr, index, size);
            return;
        }
    }
    //otherwise there's 2 children
    else { 
        left_child = arr[left_child_index];
        right_child = arr[right_child_index];

        //2. Find the largest child of node at index
        if (left_child > right_child && left_child > arr[index]) {
            largest_num = left_child;
        }
        else if (left_child < right_child && right_child > arr[index]) {
            largest_num = right_child;
        }

        //3. Swap node at index with largest_child_index
        if (largest_num == left_child) {
            int temp = arr[index];
            arr[left_child_index] = temp;
            arr[index] = left_child; //swap
            index = left_child_index;
            heapifyDown(arr, index, size);
        }
        else if (largest_num == right_child) {
            int temp = arr[index];
            arr[right_child_index] = temp;
            arr[index] = right_child; //swap
            index = right_child_index;
            heapifyDown(arr, index, size);
            return;
        }
    }

}
int* extractMax(int arr[], int size)
{    
    arr[0] = arr[--size];
    heapifyDown(arr, 0, size);
    return arr;
}
