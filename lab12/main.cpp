#include "Graph.hpp"
#include "InputParser.hpp"
#include "ParseError.hpp"
#include "UserInput.hpp"
#include <fstream>

int main(int argc, char** argv){

  // int* thing = new int*[3];
  // thing[0] = {0, 1, 4};
  // thing[1] = {-1, 0, 10};
  // thing[2] = {14, 2, 0};
  //
  // Graph(3, thing);

  if(argc <= 1){
    std::cout << "No input file provided, exiting.\n";
    return -1;
  }

  QuickQueue<int> input_data(10);

  std::ifstream f;
  f.open(argv[1]);

  int num_nodes;

  try{
    InputParser::parse(f, num_nodes, input_data);
  }
  catch(ParseError& err){
    f.close();
    std::cout << "Data could not be imported from " << argv[1] << "; error at position " << err.getErrPos() << "\n";
    return -1;
  }

  f.close();

  int** vals = new int*[num_nodes];
  for(int i = 0; i < num_nodes; i++){
    vals[i] = new int[num_nodes];
    for(int j = 0; j < num_nodes; j++){
      vals[i][j] = input_data.pop();
    }
  }

  Graph g(num_nodes, vals);

  UserInput ui(&g);
  ui.start();

  return 0;

  // Edge*** dfs_res = g.bfs();
  //
  //
  // int iter = 0;
  // while(dfs_res[0][iter] != nullptr){
  //   std::cout << *dfs_res[0][iter] << ", ";
  //   iter++;
  // }
  // std::cout << "\n";
  //
  // iter = 0;
  // while(dfs_res[1][iter] != nullptr){
  //   std::cout << *dfs_res[1][iter] << ", ";
  //   iter++;
  // }
  // std::cout << "\n";
  //
  // Graph::cleanup_search(dfs_res);

  Edge** krusk = g.kruskal();

  int iter = 0;
  int total_cost = 0;
  while(krusk[iter] != nullptr){
    std::cout << *krusk[iter] << ", ";
    total_cost += krusk[iter]->cost;
    iter++;
  }
  std::cout << "\ncost: " << total_cost << "\n";

  Graph::cleanup_mst(krusk);

  for(int i = 0; i < 5; i++){
    delete[] vals[i];
  }
  delete[] vals;

  return 0;
}
