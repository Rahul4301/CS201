#include <iostream>
using namespace std;

// Function to perform bubble sort and count the number of exchanges
void bubbleSort(int arr[], int size, int &exchangeCount) {
    exchangeCount = 0;
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                swap(arr[j], arr[j + 1]);
                exchangeCount++;  // Increment exchange count
                swapped = true;
            }
        }
        // If no elements were swapped, array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to perform selection sort and count the number of exchanges
void selectionSort(int arr[], int size, int &exchangeCount) {
    exchangeCount = 0;
    for (int i = 0; i < size - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first unsorted element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            exchangeCount++;  // Increment exchange count
        }
        
    }
}

int main() {
    // Create two identical arrays of at least 20 integers
    const int size = 20;
    int arr1[size] = {34, 12, 25, 47, 50, 7, 39, 17, 45, 10, 22, 54, 29, 1, 38, 26, 42, 31, 9, 18};
    int arr2[size];

    // Copy arr1 to arr2 for sorting with selection sort
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }

    // Variables to store the exchange count
    int bubbleExchanges = 0, selectionExchanges = 0;

    // Sort arr1 using bubble sort
    bubbleSort(arr1, size, bubbleExchanges);

    // Sort arr2 using selection sort
    selectionSort(arr2, size, selectionExchanges);

    // Output the results
    cout << "Bubble Sort completed with " << bubbleExchanges << " exchanges." << endl;
    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr1[i] << " ";  // Print each element of arr1
    }
    cout << endl;

    cout << "Selection Sort completed with " << selectionExchanges << " exchanges." << endl;
    cout << "The sorted array is: ";
    for (int i = 0; i < size; i++) {
        cout << arr2[i] << " ";  // Print each element of arr2
    }
    cout << endl;

    return 0;
}
