#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += 1;
        if (arr[i] == target) {
            cout<<total<<" comparisons \n";
            return i; // Return the index of the target
            
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    int arr[] = {10, 23, 19, 5, 42, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 19;
    int result = linearSearch(arr, n, target);

    if (result != -1)
        cout << "Element " << target << " found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
