//Rahul Suthar

#include <iostream>
#include <string>
using namespace std;

bool isMember(int arr[], int size, int value) {
    // if nothing s in the array it will return false
    if (size == 0) {
        return false;
    }
    // if the value is equal to the first element in the array it will return true
    if (arr[size - 1] == value) {
        return true;
    }
    // if the value is not equal to the first element in the array it will return the result
    return isMember(arr, size - 1, value);
}

void printReverse(const string &str, int index) {
    // if the index is equal to 0 it will return the string
    if (index < 0) {
        return;
    }
    cout << str[index];
    printReverse(str, index - 1);
}

int main() {
    // array
    int size = 16;
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};

    
    int value;

    cout << "Enter a value to search for in the array: ";
    cin >> value;

    if (isMember(arr, size, value)) {
        cout << value << " is in the array." << endl;
    } else {
        cout << value << " is not in the array." << endl;
    }

    string input;

    cout << "Enter a string: ";
    cin >> input;

    cout << "The string in reverse order is: ";
    printReverse(input, input.length() - 1);
    cout << endl;

    return 0;
}
