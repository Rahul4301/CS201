#include <iostream>
#include <string>
#include <stdexcept>

class Date {
private:
    int month;
    int day;
    int year;

    static std::string getMonthName(int month) {
        const std::string monthNames[] = {"January", "February", "March", "April", "May", "June",
                                          "July", "August", "September", "October", "November", "December"};
        return monthNames[month - 1];
    }

public:
    // Exception classes
    class InvalidDay : public std::runtime_error {
    public:
        InvalidDay() : std::runtime_error("Invalid day! Day must be between 1 and 31.") {}
    };

    class InvalidMonth : public std::runtime_error {
    public:
        InvalidMonth() : std::runtime_error("Invalid month! Month must be between 1 and 12.") {}
    };

    // Constructor
    Date(int m, int d, int y) {
        if (m < 1 || m > 12)
            throw InvalidMonth();
        if (d < 1 || d > 31)
            throw InvalidDay();

        month = m;
        day = d;
        year = y;
    }

    // Display in "12/25/2014" format
    void displayNumeric() const {
        std::cout << month << "/" << day << "/" << year << std::endl;
    }

    // Display in "December 25, 2014" format
    void displayTextual() const {
        std::cout << getMonthName(month) << " " << day << ", " << year << std::endl;
    }

    // Display in "25 December 2014" format
    void displayEuropean() const {
        std::cout << day << " " << getMonthName(month) << " " << year << std::endl;
    }
};

// Main function to demonstrate the class
int main() {
    try {
        // Valid date example
        Date date1(12, 25, 2014);
        std::cout << "Date 1:\n";
        date1.displayNumeric();
        date1.displayTextual();
        date1.displayEuropean();
        std::cout << std::endl;

        // Invalid month example
        std::cout << "Attempting to create a date with an invalid month:\n";
        Date date2(13, 10, 2023); // This will throw InvalidMonth exception
        date2.displayNumeric();
    }
    catch (const Date::InvalidDay &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Date::InvalidMonth &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        // Invalid day example
        std::cout << "\nAttempting to create a date with an invalid day:\n";
        Date date3(10, 32, 2023); // This will throw InvalidDay exception
        date3.displayNumeric();
    }
    catch (const Date::InvalidDay &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const Date::InvalidMonth &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
