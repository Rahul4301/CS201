// Rahul Suthar
// am8633

#include <iostream>
#include <string>     
#include <cstdlib>  

using namespace std;

// Function that counts the occurrences of 'w' in a C-string
int countW(const char* str) {
    int count = 0;
    while (*str != '\0') {  // Traverse until the null terminator is found
        if (*str == 'w') {
            count++;
        }
        str++;  // Move to the next character
    }
    return count;
}

int main() {
    // 1. Convert a C-string to a double
    char str[] = "237.89";
    double value;
    value = atof(str);  // Convert the C-string to double using atof()
    cout << "The converted double value is: " << value << endl;

    // 2. Compare two string objects
    string str1 = "Hello";
    string str2 = "Hello";
    if (str1 == str2) {
        cout << "They are the same!" << endl;
    } else {
        cout << "They are different!" << endl;
    }

    // 3. Count the occurrences of 'w' in a C-string
    const char* cString = "Hello world";
    int wCount = countW(cString);
    cout << "The character 'w' appears " << wCount << " times in the string." << endl;

    return 0;
}
