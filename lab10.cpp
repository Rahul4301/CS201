#include <iostream>
using namespace std;

// Define a node in the doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}  // Constructor to initialize the node
};

// Define the doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}  // Default constructor initializes an empty list

    // Copy constructor for deep copying a DoublyLinkedList
    DoublyLinkedList(const DoublyLinkedList& other) : head(nullptr), tail(nullptr) {
        Node* current = other.head;      // Start at the head of the other list
        while (current) {                 // Traverse the other list
            append(current->data);        // Append each value to the new list
            current = current->next;
        }
    }

    // Destructor to delete all nodes in the list
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Function to append a node to the end of the list
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {  // If the list is empty
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to insert a node at the beginning of the list
    void prepend(int value) {
        Node* newNode = new Node(value);
        if (!head) {  // If the list is empty
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to delete the first occurrence of a node with a given value
    void remove(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {    // Found the node with the given value
                if (current == head) {       // If it's the head node
                    head = head->next;
                    if (head) head->prev = nullptr;
                } else if (current == tail) { // If it's the tail node
                    tail = tail->prev;
                    if (tail) tail->next = nullptr;
                } else {                    // If it's a middle node
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Function to reverse the list
    void reverse() {
        Node* current = head;
        Node* temp = nullptr;
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp) {
            head = temp->prev;
        }
    }

    // Print function to display all values in the list
    void print() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Driver program to demonstrate the DoublyLinkedList class
int main() {
    DoublyLinkedList list;

    // Start with an empty list and add elements
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Original list: ";
    list.print();

    // Insert a node at the beginning
    list.prepend(5);
    cout << "After prepending 5: ";
    list.print();

    // Remove a node with value 20
    list.remove(20);
    cout << "After removing 20: ";
    list.print();

    // Reverse the list
    list.reverse();
    cout << "After reversing the list: ";
    list.print();

    // Test copy constructor
    DoublyLinkedList copyList = list;
    cout << "Copy of the list: ";
    copyList.print();

    return 0;
}
