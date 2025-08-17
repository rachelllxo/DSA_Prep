#include <iostream>															
#include <cstdlib>
using namespace std;

// Function to fill adjacency matrix and return number of edges
int fillAdjacencyMatrix(int **adj, int noOfNodes) {
    int edgeCount = 0;														// variable to store the number of edges, starts at 0
    for (int rows = 0; rows < noOfNodes; rows++) {							// loop through rows
        for (int columns = rows + 1; columns < noOfNodes; columns++) {		// loop through columns after current row (no duplicate edges)
            int Answer;														// to store user input for whether a path exists
            cout << "Is there a path between node " << rows + 1
                 << " and node " << columns + 1 << "? (0/1): ";
            cin >> Answer;
            if (Answer == 1) {												// 1 means a path exists
                adj[rows][columns] = 1;										// mark both directions since it's undirected
                adj[columns][rows] = 1;
                edgeCount++;												// increase edge count
            }
        }
    }
    return edgeCount;		
}

// Function to print adjacency matrix
void printAdjacencyMatrix(int **adj, int noOfNodes) {
    cout << "\nAdjacency Matrix:\n";
    for (int rows = 0; rows < noOfNodes; rows++) {							// loop through each row
        for (int columns = 0; columns < noOfNodes; columns++) {				// loop through each column
            cout << adj[rows][columns] << " ";								// print element
        }
        cout << endl;
    }
}

// Function to create incidence matrix from adjacency matrix
int** fillIncidenceMatrix(int **adj, int noOfNodes, int edgeCount) {
    int **incidence_matrix = (int **)malloc(sizeof(int*) * noOfNodes);		// allocate rows for incidence matrix
    for (int rows = 0; rows < noOfNodes; rows++) {							
        incidence_matrix[rows] = (int *)malloc(sizeof(int) * edgeCount);		// allocate columns for each row
        for (int columns = 0; columns < edgeCount; columns++) {				
            incidence_matrix[rows][columns] = 0;								// initialise all values to 0
        }
    }

    int column_count = 0;													// keeps track of which edge column we're filling
    for (int rows = 0; rows < noOfNodes; rows++) {							
        for (int columns = rows + 1; columns < noOfNodes; columns++) {		
            if (adj[rows][columns] == 1) {									// if an edge exists in adjacency matrix
                incidence_matrix[rows][column_count] = 1;					// mark edge at both connected nodes
                incidence_matrix[columns][column_count] = 1;
                column_count++;												// move to next edge column
            }
        }
    }
    return incidence_matrix;												// return filled matrix
}

// Function to print incidence matrix
void printIncidenceMatrix(int **incidence_matrix, int noOfNodes, int edgeCount) {
    cout << "\nIncidence Matrix:\n";
    for (int rows = 0; rows < noOfNodes; rows++) {							
        for (int columns = 0; columns < edgeCount; columns++) {				
            cout << incidence_matrix[rows][columns] << " ";					
        }
        cout << endl;
    }
}

int main() {
    int noOfNodes;															// number of nodes in the graph
    cout << "Enter number of nodes: ";										
    cin >> noOfNodes;														

    // Allocate memory for adjacency matrix
    int **adj = (int **)malloc(sizeof(int*) * noOfNodes);					
    for (int rows = 0; rows < noOfNodes; rows++) {							
        adj[rows] = (int *)malloc(sizeof(int) * noOfNodes);					
        for (int columns = 0; columns < noOfNodes; columns++) {				
            adj[rows][columns] = 0;											// start with no edges
        }
    }
    
    int edgeCount = fillAdjacencyMatrix(adj, noOfNodes);					// fill adjacency matrix
    printAdjacencyMatrix(adj, noOfNodes);									// print adjacency matrix
    
    int **incidence_matrix = fillIncidenceMatrix(adj, noOfNodes, edgeCount);	// create incidence matrix
    printIncidenceMatrix(incidence_matrix, noOfNodes, edgeCount);			// print incidence matrix
    
    return 0;
}
