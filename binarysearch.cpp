#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target)
            return mid; // Return the index of the target
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Return -1 if the target is not found
}

int main() {
    int arr[] = {5, 10, 13, 19, 23, 42}; // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 19;
    int result = binarySearch(arr, n, target);

    if (result != -1)
        cout << "Element " << target << " found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
