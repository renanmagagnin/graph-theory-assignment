//
//  main.cpp
//  GraphTheoryAssignment
//
//  Created by Renan Magagnin on 13/06/19.
//  Copyright © 2019 Renan Magagnin. All rights reserved.
//

#include <iostream>
#include <vector>

#include <sstream>

#include "Graph.hpp"

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



/**
 Constructs a given graph and a given vector containing the indexes of all desination nodes from input

 @param graph the graph to be constructed from the input
 @param destinationIndexes the vector of destination indexes to be constructed from the input
 */
void receiveFromInput(Graph *graph, vector<int> *destinationIndexes) {
    int n, i, j, w;
    
    graph->nodes.clear();
    graph->adjacencyMatrix.clear();
    (*destinationIndexes).clear();
    
    // 1. Receive number of nodes
    //    cout << "Input number of nodes: ";
    cin >> n;
    
    // 2. Receive indexes of the destination nodes
    //    cout << "Input the indexes of the destination nodes: \n";
    
    string line;
    getline(cin, line, '\n');       // This is a stupid fix
    getline(cin, line, '\n');
    
    stringstream lineStream(line);
    
    while (lineStream >> i)
        (*destinationIndexes).push_back(i);
    
    
    // 3. Receive weights of the nodes
    //    cout << "Input the weights of the nodes: ";
    for(i=0; i<n; i++) {
        Node node;
        cin >> node.weight;
        graph->nodes.push_back(node);
    }
    
    // 4. Receive the adjacency matrix
    //    cout << "Input the adjacency matrix: \n";
    vector<int> nodeEdges;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin >> w;
            nodeEdges.push_back(w);
        }
        graph->adjacencyMatrix.push_back(nodeEdges);
        nodeEdges.clear();
    }
}
