#include <iostream>
using namespace std;

struct Node {
    int bookingID;
    Node* next;
};

class BookingQueue {
public:
    Node* front;  
    Node* rear;   

    BookingQueue() {
        front = rear = NULL;
    }

    void addBooking(int bookingID) {
        Node* newNode = new Node();
        newNode->bookingID = bookingID;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Added booking: " << bookingID << "\n";
    }

    bool isEmpty() {
        return front == NULL;
    }

    int processBooking() {
        if (isEmpty()) {
            cout << "No bookings to process.\n";
            return -1;
        }

        int bookingID = front->bookingID;
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == NULL) {
            rear = NULL;
        }

        cout << "Processed booking: " << bookingID << "\n";
        return bookingID;
    }

    void displayBookings() {
        if (isEmpty()) {
            cout << "No current bookings.\n";
            return;
        }
        cout << "Current bookings in the queue: ";
        Node* current = front;
        while (current != NULL) {
            cout << current->bookingID << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

int main() {
    BookingQueue queue;

    queue.addBooking(1001);
    queue.addBooking(1002);
    queue.addBooking(1003);
    queue.displayBookings();

    queue.addBooking(1004);
    queue.displayBookings();

    queue.processBooking();
    queue.displayBookings();

    queue.processBooking();
    queue.displayBookings();

    queue.processBooking();
    queue.displayBookings();

    queue.processBooking();
    queue.displayBookings();

    queue.processBooking(); 

    return 0;
}