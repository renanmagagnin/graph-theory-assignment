//
//  Graph.hpp
//  GraphTheoryAssignment
//
//  Created by Renan Magagnin on 13/06/19.
//  Copyright © 2019 Renan Magagnin. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <vector>

using namespace std;

/**
 Definition of a Node/Vertice in the Graph.
 */
typedef struct Node {
    int weight;
} Node;


/**
 Definition of a Graph, the vector of node sit 
 */
typedef struct Graph {
    vector<Node> nodes;
    vector<vector<int> > adjacencyMatrix;
} Graph;

vector<int> shortestPaths(Graph graph);
void printGraph(Graph graph);

#endif /* Graph_hpp */
