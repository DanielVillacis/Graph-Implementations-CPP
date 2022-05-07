//
//  Vertex.h
//  Graphs-Algorithms
//
//  Created by Daniel Villacis on 2022-05-07.
//

// Implementation of a graphs using a vector of vertices and a adjacency list (most intuitive approach)
#pragma once
#include <set>
#include <vector>
struct Vertex {
    Vertex(int vecs, std::set<double> &a) : vertexNumber(vecs), adjacents(a) {}
    double vertexNumber;
    std::set<double> adjacents;
};
class Graph2 {
public:
    struct Vertex {
        Vertex(int vecs, std::set<double> &a) : vertexNumber(vecs), adjacents(a) {}
        double vertexNumber;
        std::set<double> adjacents;
    };
    Graph2(std::vector<Vertex> &vecs) : v(vecs) {}
    std::vector<Vertex> v;
    bool isEulerian();
};

bool Graph2::isEulerian() {
    std::vector<int> degrees(v.size());

    // We already have the degree each node (is equal to the length of each node's adjacency list)
    for(auto vecs : v) {
        degrees[vecs.vertexNumber] = vecs.adjacents.size();
    }
    int countOddDegrees = 0;
    for(auto d : degrees) {
        if(d % 2 == 1){
            countOddDegrees++;
        }
    }
    return (countOddDegrees == 0 || countOddDegrees == 2);
}
