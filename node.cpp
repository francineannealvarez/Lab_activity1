#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class linked_list{
    private:
        node *head, *tail;
    public:
        linked_list(){
            head = NULL;
            tail = NULL;
        }

    void insertAtBeginning(int value){
        node *temp = new node;
        temp -> data = value;
        temp -> next = head;
        head = temp;

        if (tail == NULL){
            tail = temp;
        }
    }
    
    void insertAfter(int position, int value){
        if (position == 2) {
            insertAtBeginning(value);
            return;
        }
        
        node *previous = head;
        for (int i = 0; i < position + 1 && previous != NULL; i++) {
            previous = previous->next;
        }
        
        if (previous == NULL) {
            cout << "Position out of bounds\n";
            return;
        }

        node *temp = new node;
        temp->data = value;
        temp->next = previous->next;
        previous->next = temp;
        if (temp->next == NULL)
            tail = temp;
    }



   void insertAtEnd(int value){
        node *temp = new node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == NULL){
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;       
        }
    }

    void deleteNode (int position){
        node *current = new node;
        node *previous = new node;
        current = head;
        for (int i =0; i < position; i++){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
    }
    void printList(){
        node *temp = head;
        int index = 1;
        while (temp != NULL){
            cout << "[" << index << "]: "<< temp->data << endl;
            temp = temp->next;
            index++;
        }
    }
};

int main (){
    linked_list a;
    int n;
    int value;
    int position;
    int choice;

    while (true){
        cout << "\nMenu:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert after a position" << endl;
        cout << "4. Delete a node at a position" << endl;
        cout << "5. Print the list" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1){
            cout << "Enter value to insert at the beginning: ";
            cin >> value;
            a.insertAtBeginning(value);
        }
        else if (choice == 2){
            cout << "Enter value to insert at the end: ";
            cin >> value;
            a.insertAtEnd(value);
        }
        else if (choice == 3){
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert after (1-based index), or 'x' to cancel: ";
            cin >> position;
            if (position == 'x'){
                return false;
            }
            else{
                a.insertAfter(position, value);
            }
        }

        else if (choice == 4){
            cout << "Enter position to delete (1-based index), or 'x' to cancel: ";
            cin >> position;
            a.deleteNode(position);
        }

        else if (choice == 5){
            cout << "Linked list: " << endl;
            a.printList();
        }

        else if (choice == 6){
            return 0;
        }

        else {
            cout << "Invalid choice.";
            break;
        }
    }
    return 0;
}



