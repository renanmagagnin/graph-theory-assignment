//
//  main.cpp
//  GraphTheoryAssignment
//
//  Created by Renan Magagnin on 13/06/19.
//  Copyright © 2019 Renan Magagnin. All rights reserved.
//

#include <vector>
#include "Data Types/Graph.hpp"
#include "Modules/InputHandler.hpp"

using namespace std;

void printResult(vector<int> shortestPaths, vector<int> destinationIndexes);
void receiveFromInput(Graph *graph, vector<int> *destinationIndexes);

int main(int argc, const char * argv[]) {
    
    Graph graph;
    vector<int> destinationIndexes;
    
    receiveFromInput(&graph, &destinationIndexes);
    
    // Print out results
    printResult(shortestPaths(graph), destinationIndexes);
    
    return 0;
}


/**
 Prints to the terminal the shortest path to each of the destination nodes received

 @param shortestPaths the vector of shortest paths for each node of a given graph
 @param destinationIndexes the vecotr containing the indexes of all destination nodes
 */
void printResult(vector<int> shortestPaths, vector<int> destinationIndexes) {
    int pathIndex;
    for(int i=0; i<destinationIndexes.size(); i++) {
        pathIndex = destinationIndexes[i] - 1;
        cout << shortestPaths[pathIndex] << " ";
    }
    cout << endl;
}



