#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void searchStringInFile(const std::string& filename, const std::string& searchString) {
    ifstream file(filename);

    if (!file) {
       cerr << "Error: Could not open the file " << filename << ".\n";
        return;
    }

    string line;
    int lineNumber = 0;
    int occurrences = 0;

    while (getline(file, line)) {
        lineNumber++;
        if (line.find(searchString) != string::npos) {
            cout << "Line " << lineNumber << ": " << line << '\n';
            occurrences++;
        }
    }

    file.close();

    if (occurrences > 0) {
        cout << "\nThe string \"" << searchString << "\" was found " << occurrences << " times in the file.\n";
    } else {
        std::cout << "\nThe string \"" << searchString << "\" was not found in the file.\n";
    }
}

int main() {
    string filename, searchString;

    cout << "Enter the name of the file: ";
    cin >> filename;
    cin.ignore(); // To handle the newline character left in the input buffer
    cout << "Enter the string to search for: ";
    getline(cin, searchString);

    searchStringInFile(filename, searchString);

    return 0;
}
