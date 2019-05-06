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

Edge*** Graph::bfs() const{

  bool* edge_marked[5];
  bool node_marked[num_nodes];
  for(int i = 0; i < num_nodes; i++){
    node_marked[i] = false;
    edge_marked[i] = new bool[num_nodes];
    for(int j = 0; j < num_nodes; j++){
      edge_marked[i][j] = false;
    }
  }
  node_marked[0] = true;

  QuickQueue<Edge> tree_edges(10);
  QuickQueue<Edge> cross_edges(10);

  // do bfs
  QuickQueue<int> node_queue(10);
  node_queue.push(0);
  int index;

  while(!node_queue.isEmpty()){

    index = node_queue.pop();
    GraphNode* cur = nodes[index];

    for(int i = 0; i < num_nodes; i++){
      if(i == index) continue;
      if(!cur->isNeighbor(i)) continue;
      if(edge_marked[index][i] || edge_marked[i][index]) continue;

      if(node_marked[i]){
        // add a cross edge
        cross_edges.push(Edge(index, i));
        edge_marked[i][index] = true;
      }
      else{
        // add a tree edge & enqueue next node
        node_marked[i] = true;
        edge_marked[i][index] = true;
        tree_edges.push(Edge(index, i));
        node_queue.push(i);
      }
    }

  }

  Edge*** ret = new Edge**[2];

  int num_tree_edges = tree_edges.getSize();
  ret[0] = new Edge*[num_tree_edges+1];
  ret[0][num_tree_edges] = nullptr;
  for(int i = 0; i < num_tree_edges; i++){
    ret[0][i] = new Edge(tree_edges.pop());
  }

  int num_cross_edges = cross_edges.getSize();
  ret[1] = new Edge*[num_cross_edges+1];
  ret[1][num_cross_edges] = nullptr;
  for(int i = 0; i < num_cross_edges; i++){
    ret[1][i] = new Edge(cross_edges.pop());
  }

  return ret;

}

Edge*** Graph::dfs() const{

    bool* edge_marked[5];
    bool node_marked[num_nodes];
    for(int i = 0; i < num_nodes; i++){
      node_marked[i] = false;
      edge_marked[i] = new bool[num_nodes];
      for(int j = 0; j < num_nodes; j++){
        edge_marked[i][j] = false;
      }
    }
    node_marked[0] = true;

    QuickQueue<Edge> tree_edges(10);
    QuickQueue<Edge> back_edges(10);

    dfsHelper(node_marked, edge_marked, tree_edges, back_edges, 0);

    Edge*** ret = new Edge**[2];

    int num_tree_edges = tree_edges.getSize();
    ret[0] = new Edge*[num_tree_edges+1];
    ret[0][num_tree_edges] = nullptr;
    for(int i = 0; i < num_tree_edges; i++){
      ret[0][i] = new Edge(tree_edges.pop());
    }

    int num_back_edges = back_edges.getSize();
    ret[1] = new Edge*[num_back_edges+1];
    ret[1][num_back_edges] = nullptr;
    for(int i = 0; i < num_back_edges; i++){
      ret[1][i] = new Edge(back_edges.pop());
    }

    return ret;

}

void Graph::dfsHelper(bool* node_marked, bool** edge_marked, QuickQueue<Edge>& tree_edges, QuickQueue<Edge>& back_edges, int index) const{

  GraphNode* cur = nodes[index];
  for(int i = 0; i < num_nodes; i++){
    if(i == index) continue;
    if(!cur->isNeighbor(i)) continue;
    if(edge_marked[index][i] || edge_marked[i][index]) continue;

    if(node_marked[i]){
      // add a back edge
      back_edges.push(Edge(index, i));
      edge_marked[i][index] = true;
    }
    else{
      // add a tree edge & recurse dfs
      node_marked[i] = true;
      edge_marked[i][index] = true;
      tree_edges.push(Edge(index, i));
      dfsHelper(node_marked, edge_marked, tree_edges, back_edges, i);
    }
  }

}


void Graph::cleanup_search(int*** search_result){}

int** Graph::kruskal() const{}
int** Graph::prim() const{}

void Graph::cleanup_mst(int** mst_result){}

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
