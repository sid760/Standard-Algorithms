// Heap Sort Algorithm
// Siddharth Mishra

#include <bits/stdc++.h>
using namespace std;
// Function to print an array
void printArr(int *a, int n);

void heapify(int *a, int n)
{
    int i = 0;
    // till all the parents are traversed, do: 
    while(2*i + 1 <= n - 1) {
    int left = 2*i + 1, right = 2*i + 2; // left represents index of the left child
        if(a[i] < a[left])
            swap(a[i], a[left]);
        
        // if right index is greater than n-1(last index) that means 
        // no right child exists, and no swapping should occur then 
        if(right <= n-1) {
            if(a[i] < a[right])
                swap(a[i], a[right]);
        }
        i++;  
    }
}

// Function to create max heap of an array of elements
void maxHeap(int *a, int n) {
    int max = *max_element(a, a+n);
    while(a[0] != max) 
        heapify(a, n);
}

// Function to sort an array using heap sort algorithm 
void heapSort(int *a, int n)
{   // Call maxHeap once
    maxHeap(a, n);

    // Now remove and form max heap continuously till all the elements are sorted
    for(int i = 0; i < n - 1; i++) {
        swap(a[0], a[n-i-1]);
        maxHeap(a, n-i-1);
    }
}

void printArr(int *a, int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;    
}

int main() {
    int a[] = {3, 1, 2, -5, 5, 4};
    int n = sizeof(a) / sizeof(a[0]);
    printArr(a, n);

    heapSort(a, n);
    printArr(a, n);
    return 0;
}
