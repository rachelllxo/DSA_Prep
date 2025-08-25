#include <iostream>
#include "Linked_List_Operations.cpp"  // your linked list functions
using namespace std;

// Stack using linked list (push, pop, display)
int main() {
    int choice, value;

    while (true) {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {  // Push
            cout << "Enter a value to push: ";
            cin >> value;
            insertAtEnd(value);
            displayList();
        } 
        else if (choice == 2) {  // Pop
            deleteAtBeginning();
                displayList();
            
        } 
        else if (choice == 3) {  // Display
            displayList();
        } 
        else if (choice == 4) {  // Exit
            cout << "Exiting..." << endl;
            return 0;
        } 
        else {
            cout << "Invalid choice, try again!" << endl;
        }
    }
}
