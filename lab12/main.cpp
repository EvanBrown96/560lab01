#include "Graph.hpp"
#include "Edge.hpp"

int main(int argc, char** argv){

  // int* thing = new int*[3];
  // thing[0] = {0, 1, 4};
  // thing[1] = {-1, 0, 10};
  // thing[2] = {14, 2, 0};
  //
  // Graph(3, thing);

  int** vals = new int*[5];
  vals[0] = new int[5];
  vals[0][0] = 0;
  vals[0][1] = 5;
  vals[0][2] = 7;
  vals[0][3] = 11;
  vals[0][4] = 8;
  vals[1] = new int[5];
  vals[1][0] = 5;
  vals[1][1] = 0;
  vals[1][2] = 6;
  vals[1][3] = -1;
  vals[1][4] = 12;
  vals[2] = new int[5];
  vals[2][0] = 7;
  vals[2][1] = 6;
  vals[2][2] = 0;
  vals[2][3] = 9;
  vals[2][4] = -1;
  vals[3] = new int[5];
  vals[3][0] = 11;
  vals[3][1] = -1;
  vals[3][2] = 9;
  vals[3][3] = 0;
  vals[3][4] = 7;
  vals[4] = new int[5];
  vals[4][0] = 8;
  vals[4][1] = 12;
  vals[4][2] = -1;
  vals[4][3] = 7;
  vals[4][4] = 0;

  Graph g(5, vals);
  Edge*** dfs_res = g.bfs();


  int iter = 0;
  while(dfs_res[0][iter] != nullptr){
    std::cout << *dfs_res[0][iter] << ", ";
    iter++;
  }
  std::cout << "\n";

  iter = 0;
  while(dfs_res[1][iter] != nullptr){
    std::cout << *dfs_res[1][iter] << ", ";
    iter++;
  }
  std::cout << "\n";

  // DJS<int> x;
  // x.makeSet(12);
  // x.makeSet(19);
  // x.makeSet(45);
  // x.makeSet(2);
  // x.makeSet(99);
  // x.makeSet(43);
  // x.setUnion(19, 45);
  // std::cout << x.find(19)->getRootItem() << "\n";

  return 0;
}
