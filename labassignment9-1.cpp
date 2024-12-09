#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void displayFile(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Error: Could not open file " << fileName << endl;
        return;
    }

    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        cout << line << endl;
        lineCount++;

        // Pause after every 24 lines
        if (lineCount == 24) {
            cout << "\nPress Enter to continue..." << endl;
            cin.ignore();  // Wait for the user to press Enter
            lineCount = 0;      // Reset line count after pause
        }
    }

    file.close();
    cout << "\nEnd of file reached." << endl;
}

int main() {
    string fileName;
    fileName = "lab9-1.txt";
    

    displayFile(fileName);
    return 0;
}
