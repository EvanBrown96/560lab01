#include "Edge.hpp"

Edge::Edge(int n1, int n2):
    n1(n1 < n2 ? n1 : n2), n2(n1 < n2 ? n2 : n1){}

std::ostream& operator<<(std::ostream& stream, const Edge& e){
  std::cout << "(" << e.n1 << ", " << e.n2 << ")";
  return stream;
}
