#include "Edge.hpp"

Edge::Edge():
    n1(-1), n2(-1), cost(-1){}

Edge::Edge(int n1, int n2):
    n1(n1 < n2 ? n1 : n2), n2(n1 < n2 ? n2 : n1), cost(-1){}

Edge::Edge(int n1, int n2, int cost):
    n1(n1 < n2 ? n1 : n2), n2(n1 < n2 ? n2 : n1), cost(cost){}

bool Edge::operator<(const Edge& compare) const{
  return cost < compare.cost;
}

std::ostream& operator<<(std::ostream& stream, const Edge& e){
  std::cout << "(" << e.n1 << ", " << e.n2 << ")";
  if(e.cost > -1) std::cout << "{" << e.cost << "}";
  return stream;
}
