#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
class CircularQueue {
private:
    Node* front;
    Node* rear;
public:
    CircularQueue() {
        front = NULL;
        rear = NULL;
    }
    bool isEmpty() {
        return front == NULL;
    }
    void enqueue(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
            rear->next = front;  
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;  
        }
        cout << "Enqueue: " << data << "\n";
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return -1;
        }
        int value = front->data;
        Node* temp = front;
        if (front == rear) {
            front = NULL;
            rear = NULL;
        } else {
            front = front->next;
            rear->next = front;  
        }
        delete temp;
        cout << "Dequeue: " << value << "\n";
        return value;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        Node* current = front;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != front);
        cout << "\n";
    }
};
int main() {
    CircularQueue q;
    q.enqueue(2);
    q.enqueue(7);
    q.enqueue(6);
    q.enqueue(4);
    q.display();
    cout << "peek element: " << q.peek() << "\n";
    q.dequeue();
    q.dequeue();
    q.display();
    q.enqueue(46);
    while (!q.isEmpty()) {
        q.dequeue();
        q.display();
    }
    return 0;
}
