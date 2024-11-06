#include <iostream>
using namespace std;
#define MAX 4
class CircularQueue {
public:
    int front, rear;
    int q_arr[MAX];
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        return ((rear + 1) % MAX == front);  
    }
    bool isEmpty() {
        return (front == -1);  
    }
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue overflow\n";
            return;
        }
        if (isEmpty()) {
            front = 0;  
        }
        rear = (rear + 1) % MAX;  
        q_arr[rear] = data;
        cout << "Enqueue: " << data << "\n";
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow\n";
            return -1;
        }
        int value = q_arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;  
        }
        cout << "Dequeue: " << value << "\n";
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
        int i = front;
        while (true) {
            cout << q_arr[i] << " ";
            if (i == rear) 
			break;  
            i = (i + 1) % MAX;  
        }
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
    q.enqueue(5);  
    q.dequeue();
    q.enqueue(5);
    q.display();  
    while (!q.isEmpty()) {
        q.dequeue();
        q.display();
    }
    return 0;
}
