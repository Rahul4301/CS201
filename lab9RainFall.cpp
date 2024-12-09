#include <iostream>
using namespace std;

int main() {
    const int NUM_MONTHS = 12;  // Number of months in a year
    double rainfall[NUM_MONTHS]; // Array to store rainfall for each month
    double totalRainfall = 0;    // Variable to store total rainfall
    double avgRainfall;          // Variable to store average monthly rainfall
    int highestMonth = 0, lowestMonth = 0; // Indices for months with highest and lowest rainfall

    double temp[NUM_MONTHS];     // Array to store temperature for each month
    double annualtemp = 0;       // Variable to store total temperature
    double avgtemp;              // Variable to store average monthly temperature
    int highesttemp = 0, lowesttemp = 0; // Indices for months with highest and lowest temperature

    // Input rainfall for each month with validation
    for (int i = 0; i < NUM_MONTHS; i++) {
        do {
            cout << "Enter the rainfall (in inches) for month " << i + 1 << ": ";
            cin >> rainfall[i];

            if (rainfall[i] < 0) {
                cout << "Rainfall cannot be negative. Please enter a valid number.\n";
            }
        } while (rainfall[i] < 0); // Repeat if user enters a negative number

        totalRainfall += rainfall[i]; // Add to the total rainfall

        // Check if current month has highest or lowest rainfall so far
        if (rainfall[i] > rainfall[highestMonth]) {
            highestMonth = i; // Update highest month index
        }
        if (rainfall[i] < rainfall[lowestMonth]) {
            lowestMonth = i; // Update lowest month index
        }
    }

    // Calculate average monthly rainfall
    avgRainfall = totalRainfall / NUM_MONTHS;

    // Input temperature for each month
    for (int i = 0; i < NUM_MONTHS; i++) {
        do {
            cout << "Enter the temperature for month " << i + 1 << ": ";
            cin >> temp[i];
        } while (temp[i] < 0); // Repeat if user enters a negative number

        annualtemp += temp[i]; // Add to the total temperature

        // Check if current month has highest or lowest temperature so far
        if (temp[i] > temp[highesttemp]) {
            highesttemp = i; // Update highest temperature month index
        }
        if (temp[i] < temp[lowesttemp]) {
            lowesttemp = i; // Update lowest temperature month index
        }
    }

    // Calculate average monthly temperature
    avgtemp = annualtemp / NUM_MONTHS;

    // Display rainfall results
    cout << "\nTotal rainfall for the year: " << totalRainfall << " inches" << endl;
    cout << "Average monthly rainfall: " << avgRainfall << " inches" << endl;
    cout << "Month with the highest rainfall: Month " << highestMonth + 1
         << " (" << rainfall[highestMonth] << " inches)" << endl;
    cout << "Month with the lowest rainfall: Month " << lowestMonth + 1
         << " (" << rainfall[lowestMonth] << " inches)" << endl;

    // Display temperature results
    cout << "Average monthly temperature: " << avgtemp << " degrees" << endl;
    cout << "Month with the highest temperature: Month " << highesttemp + 1
         << " (" << temp[highesttemp] << " degrees)" << endl;
    cout << "Month with the lowest temperature: Month " << lowesttemp + 1
         << " (" << temp[lowesttemp] << " degrees)" << endl;

    return 0;
}
