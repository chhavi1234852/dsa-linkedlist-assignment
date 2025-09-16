#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = NULL;
void insertBegin(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}
void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    if (head == NULL) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next != NULL) t = t->next;
    t->next = n;
}
void insertAfter(int key, int x) {
    Node* t = head;
    while (t != NULL && t->data != key) t = t->next;
    if (t == NULL) { cout << "Key not found\n"; return; }
    Node* n = new Node;
    n->data = x;
    n->next = t->next;
    t->next = n;
}
void insertBefore(int key, int x) {
    if (head == NULL) { cout << "List empty\n"; return; }
    if (head->data == key) { insertBegin(x); return; }
    Node* t = head;
    while (t->next != NULL && t->next->data != key) t = t->next;
    if (t->next == NULL) { cout << "Key not found\n"; return; }
    Node* n = new Node;
    n->data = x;
    n->next = t->next;
    t->next = n;
}
void deleteBegin() {
    if (head == NULL) { cout << "List empty\n"; return; }
    Node* d = head;
    head = head->next;
    delete d;
}
void deleteEnd() {
    if (head == NULL) { cout << "List empty\n"; return; }
    if (head->next == NULL) { delete head; head = NULL; return; }
    Node* t = head;
    while (t->next->next != NULL) t = t->next;
    delete t->next;
    t->next = NULL;
}
void deleteNode(int key) {
    if (head == NULL) { cout << "List empty\n"; return; }
    if (head->data == key) { deleteBegin(); return; }
    Node* t = head;
    while (t->next != NULL && t->next->data != key) t = t->next;
    if (t->next == NULL) { cout << "Key not found\n"; return; }
    Node* d = t->next;
    t->next = d->next;
    delete d;
}
void search(int key) {
    Node* t = head;
    int pos = 1;
    while (t != NULL) {
        if (t->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        t = t->next;
        pos++;
    }
    cout << "Not found\n";
}
void display() {
    if (head == NULL) { cout << "List empty\n"; return; }
    Node* t = head;
    while (t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}
int main() {
    int ch, val, key;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1 Insert at beginning\n";
        cout << "2 Insert at end\n";
        cout << "3 Insert after a value\n";
        cout << "4 Insert before a value\n";
        cout << "5 Delete from beginning\n";
        cout << "6 Delete from end\n";
        cout << "7 Delete specific value\n";
        cout << "8 Search a value\n";
        cout << "9 Display list\n";
        cout << "0 Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Value: "; cin >> val; insertBegin(val); break;
            case 2: cout << "Value: "; cin >> val; insertEnd(val); break;
            case 3: cout << "Key and new value: "; cin >> key >> val; insertAfter(key,val); break;
            case 4: cout << "Key and new value: "; cin >> key >> val; insertBefore(key,val); break;
            case 5: deleteBegin(); break;
            case 6: deleteEnd(); break;
            case 7: cout << "Value to delete: "; cin >> key; deleteNode(key); break;
            case 8: cout << "Value to search: "; cin >> key; search(key); break;
            case 9: display(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (ch != 0);
    return 0;
}
