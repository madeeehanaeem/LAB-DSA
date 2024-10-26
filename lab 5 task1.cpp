#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void display(Node* head) {
    if (head == NULL) {
        cout << "Link list is empty";
        return;
    }
    cout << "Link List Elements" << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtStart(Node*& head, int val) {
    Node* n = new Node(val);
    n->next = head;
    if (head != NULL)
        head->prev = n;
    head = n;
}

void insertAtEnd(Node*& head, int val) {
    Node* n = new Node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

int main() {
    Node node1, node2;
    Node* head = &node1;

    int value;
    cout << "Enter value for node 1: ";
    cin >> node1.data;
    node1.prev = NULL;
    node1.next = &node2;

    cout << "Enter value for node 2: ";
    cin >> node2.data;
    node2.prev = &node1;
    node2.next = NULL;

    display(head);

    cout << endl << "Press 1 to insert at start" << endl;
    cout << "Press 2 to insert at end" << endl;
    int ch;
    cin >> ch;

    switch (ch) {
        case 1: {
            insertAtStart(head, 4);
            display(head);
            break;
        }
        case 2: {
            insertAtEnd(head, 4);
            display(head);
            break;
        }
    }

    return 0;
}

