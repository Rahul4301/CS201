// Rahul Suthar
// am8633

#include <iostream>
using namespace std;


// 1. Largest/Smallest Array Values
void largestSmallest(int arr[], int size) {
    int largest = arr[0];
    int smallest = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    cout << "\nLargest value: " << largest << endl;
    cout << "Smallest value: " << smallest << endl;
}

// 2. Larger Than n
void largerThanN(int arr[], int size, int n) {
    cout << "\nValues larger than " << n << " are: ";
    for (int i = 0; i < size; i++) {
        if (arr[i] > n) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// 3. Print array using regular and range-based for loops
void printArrayWithLoops(int names[], int size) {
    // Regular for loop
    cout << "\nPrinting array with a regular for loop:" << endl;
    for (int i = 0; i < size; i++) {
        cout << names[i] << "\n ";
    }
    cout << endl;
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];

    // 1. Largest/Smallest Array Values
    cout << "Enter 10 values:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }
    largestSmallest(arr, SIZE);

    // 2. Larger Than n
    int n;
    cout << "\nEnter a number n: ";
    cin >> n;
    largerThanN(arr, SIZE, n);

    // 3. Regular and Range-based For Loop to Print Array
    const int NAMES_SIZE = 20;
    int names[NAMES_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    printArrayWithLoops(names, NAMES_SIZE);

    return 0;
}