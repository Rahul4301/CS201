#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Node structure representing each order
struct Node {
    std::string name;
    std::string drink;
    int preparationTime;
    Node* next;
};

// CoffeeShopQueue class to manage the queue
class CoffeeShopQueue {
private:
    Node* head;
    Node* tail;

public:
    // Constructor
    CoffeeShopQueue() : head(nullptr), tail(nullptr) {}

    // Add an order to the queue
    void addOrder(const std::string& name, const std::string& drink) {
    srand(time(0)); // Initialize random seed
    int prepTime = rand() % 10 + 1; // Generate random prep time (1-10 minutes)

    Node* newNode = new Node();
    newNode->name = name;
    newNode->drink = drink;
    newNode->preparationTime = prepTime;
    newNode->next = nullptr;

    if (!tail) { // If the queue is empty
        head = tail = newNode;
    } else { // Add to the end of the queue
        tail->next = newNode;
        tail = newNode;
    }
    std::cout << name << "'s order for " << drink << " has been added with a prep time of "
              << prepTime << " minutes.\n";
}


    // Retrieve an order by name
    void retrieveOrder(const std::string& name) {
        if (!head) {
            std::cout << "No orders in the queue.\n";
            return;
        }

        Node* current = head;
        Node* previous = nullptr;
        int totalWaitTime = 0;
        int position = 0;

        while (current) {
            position++;
            totalWaitTime += current->preparationTime;

            if (current->name == name) {
                if (!previous) {
                    std::cout << name << "'s order is ready! Here's your " 
                              << current->drink << ".\n";
                    head = current->next;
                    if (!head) tail = nullptr;
                    delete current;
                } else {
                    std::cout << name << ", your " << current->drink 
                              << " will be ready in " << totalWaitTime 
                              << " minutes. There are " << position - 1 
                              << " orders ahead of you.\n";
                }
                return;
            }

            previous = current;
            current = current->next;
        }

        std::cout << "No order found for " << name << ".\n";
    }

    // Display all orders in the queue (optional for debugging)
    void displayQueue() {
        if (!head) {
            std::cout << "The queue is empty.\n";
            return;
        }

        Node* current = head;
        std::cout << "Current orders in the queue:\n";
        while (current) {
            std::cout << "- " << current->name << ": " << current->drink 
                      << " (" << current->preparationTime << " minutes)\n";
            current = current->next;
        }
    }

    // Destructor to clean up memory
    ~CoffeeShopQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Menu display function
void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Coffee - $5.00\n";
    std::cout << "2. Apple Juice - $6.00\n";
    std::cout << "3. Milkshake - $6.50\n";
    std::cout << "4. Tea - $6.50\n";
    std::cout << "5. Ethnic Drink - $7.00\n";
}

// Main function
int main() {
    CoffeeShopQueue queue;
    int choice;
    std::string name, drink;

    do {
        std::cout << "\nCoffee Shop Order Queue System\n";
        std::cout << "1. Add an order\n";
        std::cout << "2. Retrieve an order\n";
        std::cout << "3. Display all orders\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Add an order
                displayMenu();
                std::cout << "Enter your name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter your drink choice: ";
                std::getline(std::cin, drink);
                queue.addOrder(name, drink);
                break;

            case 2: // Retrieve an order
                std::cout << "Enter your name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                queue.retrieveOrder(name);
                break;

            case 3: // Display all orders
                queue.displayQueue();
                break;

            case 4: // Exit
                std::cout << "Thank you for using the Coffee Shop Order Queue System. Goodbye!\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
