#include <iostream>
using namespace std;

// Define Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    // Default constructor
    Node() : data(0), next(nullptr), prev(nullptr) {}

    // Parameterized constructor
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to display the linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "Linked list is empty." << endl;
        return;
    }

    cout << "Linked List Elements:" << endl;
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to delete node at the start
void deleteAtStart(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
}

// Function to delete node at the end
void deleteAtEnd(Node*& head) {
    if (head == nullptr) return;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
    } else {
        head = nullptr; // Handle case where only one node exists
    }
    delete temp;
}

int main() {
    int choice;

    // Dynamically create nodes
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* head = node1;

    // Input values for nodes
    cout << "Enter value for node 1: ";
    cin >> node1->data;
    node1->prev = nullptr;
    node1->next = node2;

    cout << "Enter value for node 2: ";
    cin >> node2->data;
    node2->prev = node1;
    node2->next = node3;

    cout << "Enter value for node 3: ";
    cin >> node3->data;
    node3->prev = node2;
    node3->next = nullptr;

    display(head);

    // Menu-driven deletion
    cout << "Press 1 to delete at start" << endl;
    cout << "Press 2 to delete at end" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            deleteAtStart(head);
            display(head);
            break;
        case 2:
            deleteAtEnd(head);
            display(head);
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    // Clean up remaining nodes
    while (head != nullptr) {
        deleteAtStart(head);
    }

    return 0;
}
