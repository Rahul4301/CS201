#include <iostream>
#include <string>
using namespace std;

// Define Car structure
struct Car {
    string carMake;
    string carModel;
    int yearModel;
    double cost;
};

int main() {
    // Initialize Car structure with given data
    Car car = {"Ford", "Mustang", 1968, 20000.00};

    // Display car information
    cout << "Car Make: " << car.carMake << endl;
    cout << "Car Model: " << car.carModel << endl;
    cout << "Year Model: " << car.yearModel << endl;
    cout << "Cost: $" << car.cost << endl;

    return 0;
}
