#include "Graph.hpp"
#include "PriQueue.hpp"
#include "DJS.hpp"

int main(int argc, char** argv){

  // int* thing = new int*[3];
  // thing[0] = {0, 1, 4};
  // thing[1] = {-1, 0, 10};
  // thing[2] = {14, 2, 0};
  //
  // Graph(3, thing);

  DJS<int> x;
  x.makeSet(12);
  x.makeSet(19);
  x.makeSet(45);
  x.makeSet(2);
  x.makeSet(99);
  x.makeSet(43);
  x.setUnion(19, 45);
  std::cout << x.find(19)->getRootItem() << "\n";

  return 0;
}
