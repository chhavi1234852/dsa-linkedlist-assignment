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
void deleteOccurrences(int key) {
    int count = 0;
    while (head != NULL && head->data == key) {
        Node* del = head;
        head = head->next;
        delete del;
        count++;
    }
    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            count++;
        } else {
            temp = temp->next;
        }
    }
    cout << "Count: " << count << endl;
}
 void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}
int main() {
    int arr[] = {1,2,1,2,1,3,1};
    for (int x : arr) insertEnd(x);

    cout << "Original List: ";
    display();

    deleteOccurrences(1);

    cout << "Updated List: ";
    display();
}
