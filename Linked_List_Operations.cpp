#include <iostream>
#include <cstdlib> // for malloc and free
using namespace std;

// Structure for a node
struct Node {
    int data;          // data part
    struct Node* next; // pointer to next node
};

struct Node* head = NULL; // global head pointer

// Function to insert at beginning
int insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return 0; // allocation failed
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return 1;
}

// Function to insert at end
int insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return 0;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return 1;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return 1;
}

// Function to insert at a specific position (1-based index)
int insertAtPosition(int value, int position) {
    if (position < 1) return 0;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return 0;
    newNode->data = value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return 1;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return 0;

    newNode->next = temp->next;
    temp->next = newNode;
    return 1;
}

// Function to delete at beginning
int deleteAtBeginning() {
    if (head == NULL) return 0;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return 1;
}

// Function to delete at end
int deleteAtEnd() {
    if (head == NULL) return 0;

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return 1;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return 1;
}

// Function to delete at a specific position (1-based index)
int deleteAtPosition(int position) {
    if (head == NULL || position < 1) return 0;

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return 1;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) return 0;

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return 1;
}

// Function to reverse linked list
int reverseList() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;  // store next node
        current->next = prev;      // reverse link
        prev = current;            // move prev one step ahead
        current = nextNode;        // move current one step ahead
    }
    head = prev;
    return 1;
}

// Function to display the linked list
int displayList() {
    struct Node* temp = head;
    if (temp == NULL) {
        cout << "List is empty" << endl;
        return 0;
    }
    cout << "Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 1;
}