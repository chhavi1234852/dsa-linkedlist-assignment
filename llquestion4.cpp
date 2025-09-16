 #include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
void insertEnd(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) { head = newNode; return; }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}
void reverseList() {
    Node *prevnode = NULL, *currentnode = head, *nextnode = NULL;
    while (currentnode != NULL) {
        nextnode = currentnode->next;  
        currentnode->next = prevnode;  
        prevnode = currentnode;         
        currentnode = nextnode;         
    }
    head = prevnode; 
}
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}
int main() {
    insertEnd(5);
    insertEnd(6);
    insertEnd(7);
    cout << "Original List: ";
    display();
    reverseList();
cout << "Reversed List: ";
    display();
}
