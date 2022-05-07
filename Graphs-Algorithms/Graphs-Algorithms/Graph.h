//
//  Graph.h
//  Graphs-Algorithms
//
//  Created by Daniel Villacis on 2022-05-06.
//

#pragma once
#include <vector>
class Graph1 {
public:
    Graph1(std::vector<int> &vec, std::vector<std::pair<int,int>> &edges)
        : v(vec), e(edges) {}
    bool IsEulerWalkable();
    std::vector<int>v;
    std::vector<std::pair<int, int>>e;
};
    
//  Function to verify if the graph is Eulerian
//  
bool Graph1::IsEulerWalkable() {
    // Initializing our degrees vector to the size of the degrees (or nodes) in our graph
    std::vector<int> degrees(v.size());
    // Iterate through each connecting node and for each node, increase the degrees of the first and the sec.
    for(auto edges : e) {           // For a 4 node graph, our degree vector should look like this : [2,2,2,2]
        degrees[edges.first]++;
        degrees[edges.second]++;
    }
    int countOddDegrees = 0;
    for(auto d : degrees) {
        if(d % 2 == 1){
            countOddDegrees++;
        }
    }
    
    return (countOddDegrees == 0 || countOddDegrees == 2);  // Eularian graph : returns true if each node contains 0 or 2 degrees.
}
