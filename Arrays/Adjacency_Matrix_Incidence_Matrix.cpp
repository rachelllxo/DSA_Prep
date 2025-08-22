#include <iostream>
using namespace std;

int main() {
    int noOfNodes;
    cout << "Enter number of nodes: ";  											// Ask user to enter total number of nodes
    cin >> noOfNodes;                   											// Read and store the number of nodes

    int adj[20][20] = {0};              											// Initialize adjacency matrix with zeros 
    int edgeCount = 0;                  											// Initialize edge count to zero

// Filling the adjacency matrix by asking user about each possible edge
    for (int rows = 0; rows < noOfNodes; rows++) {
        for (int columns = rows + 1; columns < noOfNodes; columns++) {
            int Answer;
            cout << "Is there a path between node " << rows + 1 
                 << " and node " << columns + 1 << "? (0/1): ";  					// Ask if edge exists between nodes
            cin >> Answer;  														// Input 0 or 1 from user

// If user inputs 1 (edge exists), update adjacency matrix accordingly
            if (Answer == 1) {
                adj[rows][columns] = 1;     										// Mark edge from row node to column node
                adj[columns][rows] = 1;     										// Mark edge from column node to row node
                edgeCount++;                										// Increment total edge count
            }
        }
    }

// Printing the adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int rows = 0; rows < noOfNodes; rows++) {
        for (int columns = 0; columns < noOfNodes; columns++) {
            cout << adj[rows][columns] << " ";  									// Print each element in adjacency matrix row
        }
        cout << endl; 
    }

// Creating the incidence matrix, initialized with zeros
    int incidence_matrix[20][50] = {0};
    int column_count = 0; 														 // Keeps track of which column (edge) we are filling

// Filling the incidence matrix based on adjacency matrix
    for (int rows = 0; rows < noOfNodes; rows++) {
        for (int columns = rows + 1; columns < noOfNodes; columns++) {
            if (adj[rows][columns] == 1) {  									// If edge exists between nodes rows and columns
                incidence_matrix[rows][column_count] = 1;   					 
                incidence_matrix[columns][column_count] = 1;					  
                column_count++;                              					 // Moving to next column for next edge
            }
        }
    }
//printing the incidence matrix
cout << "\nIncidence Matrix:\n";
for (int rows = 0; rows < noOfNodes; rows++) {
    for (int columns = 0; columns < edgeCount; columns++) {
        cout << incidence_matrix[rows][columns] << " ";
    }
    cout << endl;
}



    return 0;  
}
