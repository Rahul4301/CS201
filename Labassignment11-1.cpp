#include <iostream>
#include <fstream>
#include <deque>
#include <string>
using namespace std;

void displayTail(const std::string& filename) {
    ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open the file " << filename << ".\n";
        return;
    }

    deque<string> lines;
    string line;

    // Read lines and keep only the last 10
    while (getline(file, line)) {
        lines.push_back(line);
        if (lines.size() > 10) {
            lines.pop_front();
        }
    }

    file.close();

    // Check if the file has fewer than 10 lines
    if (lines.size() < 10) {
        cout << "The file has fewer than 10 lines. Displaying the entire file:\n";
    } else {
        cout << "Displaying the last 10 lines of the file:\n";
    }

    for (const auto& l : lines) {
        std::cout << l << '\n';
    }
}

int main() {
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;

    displayTail(filename);

    return 0;
}
