#include <iostream>
#include <cstdlib>  
using namespace std;

struct Node {								//created a structure for node
    int data;       						// data part to store the values
    Node* next; 						   	// pointer to next node
};

Node* head = nullptr;					  	// head pointer
Node* temp= nullptr;					 	//temporary pointer 	
int Value;									//declaring a variable to store the values of the linked list

//Push operation of stack using linked list 
int Push(int Value) {						
    Node* NewNode = (Node*)malloc(sizeof(Node)); // allocate memory for new node
    if (NewNode == NULL) return -1;			   // malloc failed
    NewNode->data = Value;   					 // set data
    NewNode->next = head;    					// link new node to previous head
    head = NewNode;          					// update head pointer to point it to new node
    return 0;									//success
}

// Function to print the list
int Print(int Value) {							
    if (head == nullptr) {						//if head is NULL, list is empty
        cout << "No values inserted" << endl;	//prints this
        return 0;
    }
    temp = head;								//temp points to the node where head points
    while (temp != nullptr) {					//the temp traverses the data part of each node until it’s NULL
        cout << temp->data << " -> ";			//prints the data part of the nodes
        temp = temp->next;						//temp points to the next node
    }
    cout << "NULL" << endl;						//to display NULL at the end of list
    return 0;
}

//Function to free the node
int Free(){										
    Node* temp = head;							//temp points to where head is pointing
    while (temp != nullptr) {					//temp traverses until NULL
        Node* next = temp->next;				//next points to the temp's next node 
        free(temp);								//free the node
        temp = next;							//temp points to the next 
    }
    head = nullptr;								//head is set to NULL
    return 0;
}

int main() {									
    cout << "Enter values:" << endl;

    while (cin >> Value) {						// keep reading values until input ends
        Push(Value);
    }

    Print(Value);								//print linked list
    Free();										//free nodes
    
	return 0;									
}
