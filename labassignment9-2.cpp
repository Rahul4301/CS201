#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayFileHead(const string& fileName) {
    ifstream file(fileName);
    if (!file) {
        cerr << "Error: Could not open file " << fileName << endl;
        return;
    }

    string line;
    int lineCount = 0;
    while (getline(file, line) && lineCount < 10) {
        cout << line << endl;
        lineCount++;
    }

    if (lineCount < 10) {
        cout << "\nEntire file displayed (fewer than 10 lines)." << endl;
    }

    file.close();
}

int main() {
    string fileName;
    fileName = "lab9-2.txt";

    displayFileHead(fileName);
    return 0;
}
