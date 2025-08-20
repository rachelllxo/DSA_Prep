#include <iostream>
#include <cstdlib>
using namespace std;


int noOfNodes;                 // number of nodes in the graph
int edgeCount;                 // number of edges
int **adj;                     // adjacency matrix
int **incidence_matrix;        // incidence matrix
int Answer;                    // to store user input

// Function to fill adjacency matrix and return number of edges
int fillAdjacencyMatrix() {
    edgeCount = 0;															//edge count set to 0                                             
    for (int rows = 0; rows < noOfNodes; rows++) {                          //traversing rows
        for (int columns = rows + 1; columns < noOfNodes; columns++) {      //traversing columns
            cout << "Is there a path between node " << rows + 1				//taking user input to know if a path exists
                 << " and node " << columns + 1 << "? (0/1): ";
            cin >> Answer;													//storing user input
            if (Answer == 1) {                                       		//if a path exists 
                adj[rows][columns] = 1;                             		//set specific row and column as 1
                adj[columns][rows] = 1;										//set reverse direction also as 1 (undirected graph)
                edgeCount++;           										//increment edgecount                              
            }
        }
    }
    return edgeCount;        												//return final edge count
}

// Function to print adjacency matrix
void printMatrix(int **temp,int row_count,int column_count) {
   																		//display adjacency matrix
    for (int rows = 0; rows < row_count; rows++) {                          //traverse rows
        for (int columns = 0; columns < column_count; columns++) {             //traverse columns
            cout << temp[rows][columns] << " ";								//print adjacency value
        }
        cout << endl;														//next row
    }
}

// Function to create incidence matrix from adjacency matrix
void fillIncidenceMatrix() {
    incidence_matrix = (int **)malloc(sizeof(int*) * noOfNodes);       		//allocate memory for rows
    for (int rows = 0; rows < noOfNodes; rows++) {                           
        incidence_matrix[rows] = (int *)malloc(sizeof(int) * edgeCount);     //allocate memory for columns
        for (int columns = 0; columns < edgeCount; columns++) {              
            incidence_matrix[rows][columns] = 0;                             //initialise all values to 0
        }
    }

    int column_count = 0;                                                    //track edge column
    for (int rows = 0; rows < noOfNodes; rows++) {                           
        for (int columns = rows + 1; columns < noOfNodes; columns++) {       
            if (adj[rows][columns] == 1) {                                   //if an edge exists
                incidence_matrix[rows][column_count] = 1;                    //mark row for edge
                incidence_matrix[columns][column_count] = 1;					//mark column for edge
                column_count++;                                              //go to next edge column
            }
        }
    }
}


int main() {
    cout << "Enter number of nodes: ";                                       //ask user for number of nodes
    cin >> noOfNodes;                                                        //store number of nodes

    // Allocate memory for adjacency matrix
    adj = (int **)malloc(sizeof(int*) * noOfNodes);                    		//allocate memory for rows
    for (int rows = 0; rows < noOfNodes; rows++) {                           
        adj[rows] = (int *)malloc(sizeof(int) * noOfNodes);                  //allocate memory for columns
        for (int columns = 0; columns < noOfNodes; columns++) {              
            adj[rows][columns] = 0;                                          //initialise with 0 (no edge)
        }
    }
    
    fillAdjacencyMatrix();                          							//fill adjacency matrix
    cout<<"Adjacency Matrix\n";
    printMatrix(adj,noOfNodes,noOfNodes);														
    
    fillIncidenceMatrix();                          							//fill incidence matrix
    cout<<"\nIncidence Matrix\n";
    printMatrix(incidence_matrix,noOfNodes,edgeCount);
    
    free(adj);
    free(incidence_matrix);
	return 0;																//end program
    
}
