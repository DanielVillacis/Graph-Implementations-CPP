//
//  main.cpp
//  Graphs-Algorithms
//
//  Created by Daniel Villacis on 2022-05-06.
//
//  Implementation of a graph to solve the following graph problems :
//      - Shortest path (Dijakstra algorithm)
//      -
//      -
//

//#include <iostream>
//#include "Graph.h"
//#include "Vertex.h"
//#include <vector>
//
//int main(int argc, const char * argv[]) {
//
//    /* Representing a graph using a vector of vertices and vector of pairs */
//    std::vector<int> v = {0,1,2,3};
//    std::vector<std::pair<int,int>> a = {{0,1}, {1,2}, {2,3}, {3,0}};
//    Graph1 g1(v,a);
//    std::cout<< g1.IsEulerWalkable() << std::endl;
//
//    /* Representing a graph using a vector of vertices and adjacency list (set) */
//
//    return 0;
//}

#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>

struct Vertex {
    Vertex(int v, std::set<int> a) : vertex_number(v), adjacents(a) {}
    int vertex_number;
    std::set<int> adjacents;
};

class Graph {
public:
  Graph() {}
  Graph(std::vector<Vertex> v) : v_(v) {}
  std::vector<Vertex> v_;
  void afficher(const std::set<int> &input){
      std::cout<< "{";
      unsigned int count = 0;
      for (auto n : input) {
          count++;
          std::cout << n;
          if (count < input.size()) std::cout << ", ";
      }
      std::cout << "}" << std::endl;
  }
};

int main() {
    
  Graph g1({Vertex(1, {2, 3}), Vertex(2, {1, 3, 4, 5}), Vertex(3, {1, 2, 4}),
            Vertex(4, {2, 4, 4})});

  Graph g2;
  g2.v_.push_back(Vertex(1, {2, 3}));
  g2.v_.push_back(Vertex(2, {1, 3, 4, 5}));
  g2.v_.push_back(Vertex(3, {1, 2, 4}));
  g2.v_.push_back(Vertex(4, {2, 4}));
  for (const auto &v : g2.v_) {
    std::cout << "Vertex: " << v.vertex_number << ", Adjacents: ";
    g2.afficher(v.adjacents);
  }
  return 0;
}
