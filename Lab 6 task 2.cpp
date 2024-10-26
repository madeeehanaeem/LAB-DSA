#include <iostream>
using namespace std;
class node {
public:
 int data;
 node* next;
 node* pre;
 node(int value) {
 data = value;
 next = NULL;
 pre = NULL;
 }
};
void insertAtPosition(node*& head, int value, int position) {
 node* n = new node(value);
 
 
 if (head == NULL) {
 head = n;
 n->next = head; 
 n->pre = head; 
 return;
 }
 
 if (position == 1) {
 node* last = head->pre; 
 
 n->next = head; 
 n->pre = last; 
 last->next = n; 
 head->pre = n; 
 head = n; 
 return;
 }
 
 node* temp = head;
 int currentPosition = 1;
 
 while (currentPosition < position - 1 && temp->next != head) {
 temp = temp->next;
 currentPosition++;
 }
 
 if (currentPosition == position - 1 && temp->next == head) {
 node* last = head->pre; 
 n->next = head; 
 n->pre = last; 
 last->next = n; 
 head->pre = n; 
 } 
 
 else if (currentPosition == position - 1) {
 n->next = temp->next; 
 n->pre = temp; 
 
 if (temp->next != head) {
 temp->next->pre = n;
 }
 
 temp->next = n; 
 } else {
 cout << "Position is out of bounds." << endl;
 delete n; 
 }
}
void display(node* head) {
 if (head == NULL) {
 cout << "List is empty." << endl;
 return;
 }
 node* temp = head;
 
 cout << temp->data << " <-> ";
 temp = temp->next;
 while (temp != head) {
 cout << temp->data << " <-> ";
 temp = temp->next;
 }
 cout << "(back to head)" << endl;
}
int main() {
 node* head = NULL;
 int value, position;
 
 insertAtPosition(head, 10, 1);
 insertAtPosition(head, 20, 2);
 insertAtPosition(head, 30, 3);
 display(head);
 cout << "Enter value to insert: ";
 cin >> value;
 cout << "Enter position to insert at: ";
 cin >> position;
 insertAtPosition(head, value, position);
 display(head);
 return 0;
}