#include <iostream>
using namespace std;

class CircularQueue {
private:
    int front, rear, size;
    int* queue;

public:
    CircularQueue(int s) {
        size = s;
        queue = new int[size];
        front = rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void addRequest(int requestID) {
        if (isFull()) {
            cout << "Queue is full. Cannot add request ID: " << requestID << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        queue[rear] = requestID;
        cout << "Added request ID: " << requestID << endl;
    }

    void processRequest() {
        if (isEmpty()) {
            cout << "No requests to process." << endl;
            return;
        }
        cout << "Processing request ID: " << queue[front] << endl;
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % size;
        }
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current queue of requests: ";
        for (int i = front; i != rear; i = (i + 1) % size) {
            cout << queue[i] << " ";
        }
        cout << queue[rear] << endl; 
    }
};

int main() {
    CircularQueue cq(5); 

    cq.addRequest(101);
    cq.addRequest(102);
    cq.addRequest(103);
    cq.displayQueue();

    cq.processRequest();
    cq.displayQueue();

    cq.addRequest(104);
    cq.addRequest(105);
    cq.addRequest(106); 
    cq.displayQueue();

    cq.processRequest();
    cq.displayQueue();

    return 0;
}
