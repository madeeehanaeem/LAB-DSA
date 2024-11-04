#include <iostream>
using namespace std;
#define MAX 4

class OrderQueue {
public:
    int front, rear;
    int orders[MAX];

    OrderQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void addOrder(int orderNumber) {
        if (isFull()) {
            cout << "Order queue is full. Cannot take more orders.\n";
            return;
        }
        if (front == -1) {
            front = 0;
        }
        orders[++rear] = orderNumber;
        cout << "Added order: " << orderNumber << "\n";
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    int processOrder() {
        if (isEmpty()) {
            cout << "No orders to process.\n";
            return -1;
        }
        int orderNumber = orders[front];
        front++;
        cout << "Processed order: " << orderNumber << "\n";
        if (front > rear) {
            front = -1;
            rear = -1;
        }
        return orderNumber;
    }

    int peekOrder() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
            return -1;
        }
        return orders[front];
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders in the queue.\n";
            return;
        }
        cout << "Current orders in the queue: ";
        for (int i = front; i <= rear; i++) {
            cout << orders[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    OrderQueue queue;

    queue.addOrder(101);
    queue.addOrder(102);
    queue.addOrder(103);
    queue.addOrder(104);
    queue.displayOrders();

    cout << "Next order to process: " << queue.peekOrder() << "\n";

    queue.addOrder(105);  

    while (!queue.isEmpty()) {
        queue.processOrder();
        queue.displayOrders();
    }

    queue.processOrder();  

    return 0;
}