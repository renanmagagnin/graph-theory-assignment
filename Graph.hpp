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

typedef struct Node {
    int weight;
} Node;

typedef struct Graph {
    vector<Node> nodes;
    vector<vector<int> > adjacencyMatrix;
} Graph;

vector<int> shortestPaths(Graph graph);
void printGraph(Graph graph);

#endif /* Graph_hpp */
