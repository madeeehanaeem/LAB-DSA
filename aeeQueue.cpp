#include <iostream>
using namespace std;
#define MAX 4
class Queue {
public:
    int front, rear;
    int q_arr[MAX];
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        return (rear == MAX - 1);
    }
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        q_arr[++rear] = data;
        cout << "Enqueue: " << data << "\n";
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return -1;
        }
        int value = q_arr[front];
        front++;
        cout << "Dequeue: " << value << "\n";
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return value;
    }
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return q_arr[front];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << q_arr[i] << " ";
        }
        cout << "\n";
    }
};
int main() {
    Queue q;
    q.enqueue(2);
    q.enqueue(7);
    q.enqueue(6);
    q.enqueue(4);
    q.display();
    cout << "peek element: " << q.peek() << "\n";
    q.enqueue(5);  
    while (!q.isEmpty()) {
        q.dequeue();
        q.display();
    }
    q.dequeue();  
    return 0;
}
