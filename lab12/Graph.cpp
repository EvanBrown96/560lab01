// 4/30

#include "PriQueue.hpp"
#include "Graph.hpp"

Graph::Graph(int num_nodes, int** costs):
    num_nodes(num_nodes), nodes(new GraphNode*[num_nodes]){

  for(int i = 0; i < num_nodes; i++){
    nodes[i] = new GraphNode(num_nodes, costs[i]);
  }

}

Graph::~Graph(){
  destroyGraph();
}

Graph::Graph(const Graph& copy){
  copyGraph(copy);
}

Graph& Graph::operator=(const Graph& copy){
  destroyGraph();
  copyGraph(copy);
  return *this;
}

int*** bfs() const;
int*** dfs() const;

static void cleanup_search(int*** search_result);

int** kruskal() const;
int** prim() const;

static void cleanup_mst(int** mst_result);

void Graph::copyGraph(const Graph& copy){

  num_nodes = copy.num_nodes;
  nodes = new GraphNode*[num_nodes];

  for(int i = 0; i < num_nodes; i++){
    *nodes[i] = *copy.nodes[i];
  }
}

void Graph::destroyGraph(){

  for(int i = 0; i < num_nodes; i++){
    delete nodes[i];
  }
  delete[] nodes;

}
