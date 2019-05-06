// 5/5

#ifndef EDGE_HPP
#define EDGE_HPP

#include <iostream>

struct Edge{

  Edge();
  
  Edge(int n1, int n2);

  int n1, n2;

  friend std::ostream& operator<<(std::ostream& stream, const Edge& e);

};

#endif // EDGE_HPP
