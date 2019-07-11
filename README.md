# A C++ Implementation of Dijkstra's Shortest Path Algorithm in Double-Weighted Graphs
The program receives an input file containing the description of the double-weighted graph and a list of destination nodes. The output is a list of the minimum distances from the first node to each destination node.

# Usage
A makefile is included for the compilation of all source files and a formatted .txt input file should be redirected into the ouput program.

To run the program, first run the makefile and then invoke the output program with the desired input file:
```
make
./output < inputFile.txt
```


The input file should respect the following format:
```
5                         <= Number of nodes in the graph
2 4 5                     <= List of destination nodes
1 1 100 2 2               <= Weights of the nodes, in order.
-1 2 1 3 -1               <= Weigths of the edges from Node 1 to every other node. (-1’s indicate the absence of an edge)
2 -1 3 -1 -1              <= Weigths of the edges from Node 2 to every other node. (-1’s indicate the absence of an edge)
1 3 -1 1 2                <= Weigths of the edges from Node 3 to every other node. (-1’s indicate the absence of an edge)
3 -1 1 -1 4               <= Weigths of the edges from Node 4 to every other node. (-1’s indicate the absence of an edge)
-1 -1 2 4 -1              <= Weigths of the edges from Node 5 to every other node. (-1’s indicate the absence of an edge)
```
