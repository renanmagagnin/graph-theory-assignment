//
//  Graph.cpp
//  GraphTheoryAssignment
//
//  Created by Renan Magagnin on 13/06/19.
//  Copyright © 2019 Renan Magagnin. All rights reserved.
//

#include "Graph.hpp"

#include <iostream>
#include <algorithm>
#include <limits.h>

vector<int> shortestPaths(Graph graph) {
    
    int i, j;
    
    // Step 1: Setup of set S containg only the source node.
    vector<int> s;
    s.push_back(0); // Index of source node

    
    // Step 2: Setup of set containing the distance labels for each node.
    vector<int> distances;
    distances.push_back(graph.nodes[0].weight);
    for(i=0; i<graph.nodes.size()-1; i++)
        distances.push_back(INT_MAX);    // INT_MAX means infinite
    
    
    int indexW;                 // The most recently node added to S
    int indexOfLowestCost;      // Varible used to determine the next node to be added to S
    int lowestCost;
    
    // Step 3(core): Updates value of W and updates labels of every neighbour of W. (optimize by testing if S contains all destination nodes)
    while(s.size() < graph.nodes.size()) { // && !s.contain(destinations)
        
        indexW = s[s.size()-1];
        
        lowestCost = INT_MAX;
        
        // For every neighbour of W:
        for(j=0; j<graph.nodes.size(); j++) {
            
            bool isAlreadyInS = false;
            if (std::find(s.begin(), s.end(), j) != s.end())
                isAlreadyInS = true;
            
            if(graph.adjacencyMatrix[indexW][j] != -1 && !isAlreadyInS) {
                distances[j] = min(distances[j], distances[indexW] + graph.adjacencyMatrix[indexW][j] + graph.nodes[j].weight);
            }
            
            if(distances[j] <= lowestCost && !isAlreadyInS) { // Optimize this later
                indexOfLowestCost = j;
                lowestCost = distances[j];
            }
        }
        
        // Step 4: Add the node with lowest cost to S (otimize by choosing destination on draws)
        s.push_back(indexOfLowestCost);
    }
    
    return distances;
}


void printGraph(Graph graph) {
    int i, j;
    
    // Print out the resulting graph information
    cout << "Number of nodes: " << graph.nodes.size() << endl;
    
    cout << "The weights of the nodes are: ";
    for(int i=0; i<graph.nodes.size(); i++)
        cout << graph.nodes[i].weight << ' ';
    cout << endl;
    
    cout << "The Adjacency Matrix is: \n";
    for(i=0; i<graph.nodes.size(); i++) {
        for(j=0; j<graph.nodes.size(); j++) {
            cout << graph.adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
