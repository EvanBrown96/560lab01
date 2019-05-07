// 5/5

#include "PriQueue.hpp"
#include "Graph.hpp"
#include "DJS.hpp"
#include "EmptyStructure.hpp"
#include "Set.hpp"

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

  for(int i = 0; i < num_nodes; i++){
    delete edge_marked[i];
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

    for(int i = 0; i < num_nodes; i++){
      delete edge_marked[i];
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


void Graph::cleanup_search(Edge*** search_result){

  int iter = 0;
  while(search_result[0][iter] != nullptr){
    delete search_result[0][iter];
    iter++;
  }
  delete[] search_result[0];

  iter = 0;
  while(search_result[1][iter] != nullptr){
    delete search_result[1][iter];
    iter++;
  }
  delete[] search_result[1];

  delete[] search_result;

}

Edge** Graph::kruskal() const{

  // setup disjoint set
  DJS<int> node_set;
  for(int i = 0; i < num_nodes; i++){
    node_set.makeSet(i);
  }

  // setup queue
  PriQueue<Edge> edges;
  int c;
  for(int i = 0; i < num_nodes; i++){
    for(int j = i+1; j < num_nodes; j++){
      c = nodes[i]->costTo(j);
      if(c != -1){
        Edge e(i, j, c);
        edges.push(e);
      }
    }
  }

  // make empty list of edges to start
  QuickQueue<Edge> qq(10);

  Edge* cur;
  while(qq.getSize() != num_nodes-1){

    // get next lowest edge
    try{
      cur = new Edge(edges.pop());
    }
    catch(EmptyStructure& e){
      break;
    }

    // find subset each node of the edge is in
    Set<int>* f1 = node_set.find(cur->n1);
    Set<int>* f2 = node_set.find(cur->n2);

    // if they are in different sets
    if(f1->getRootItem() != f2->getRootItem()){
      qq.push(*cur);
      node_set.setUnion(f1, f2);
    }

    delete cur;

  }

  if(qq.getSize() != num_nodes-1) throw std::runtime_error("No Solution");

  int num_edges = qq.getSize();
  Edge** ret = new Edge*[num_edges+1];
  ret[num_edges] = nullptr;
  for(int i = 0; i < num_edges; i++){
    ret[i] = new Edge(qq.pop());
  }

  return ret;

}

Edge** Graph::prim() const{

  int num_visited = 1;
  bool visited[num_nodes];
  visited[0] = true;
  for(int i = 1; i < num_nodes; i++){
    visited[i] = false;
  }

  int minimums[num_nodes];
  int others[num_nodes];
  others[0] = -1;
  for(int i = 1; i < num_nodes; i++){
    minimums[i] = nodes[0]->costTo(i);
    others[i] = 0;
  }

  QuickQueue<Edge> qq(10);

  while(num_visited != num_nodes){
    // initialize minimum as infinity
    int cur_min = -1;
    int cur_node = -1;
    for(int i = 1; i < num_nodes; i++){
      // skip if the tested node has already been visited
      if(!visited[i]){
        // minimum for this node must not be infinity
        if(minimums[i] >= 0){
          // current min must be infinity or more than tested min
          if(cur_min < 0 || minimums[i] < cur_min){
            cur_min = minimums[i];
            cur_node = i;
          }
        }
      }
    }

    if(cur_node < 0) throw std::runtime_error("No Solution");

    num_visited++;
    visited[cur_node] = true;
    Edge e(cur_node, others[cur_node], nodes[cur_node]->costTo(others[cur_node]));
    qq.push(e);

    for(int i = 1; i < num_nodes; i++){
      // skip if tested not has already been visited
      if(!visited[i]){
        int cost_between = nodes[cur_node]->costTo(i);
        // skip if nodes are not adjacent
        if(cost_between > 0){
          // old min must be infinity or more than new min
          if(minimums[i] == -1 || minimums[i] > cost_between){
            minimums[i] = cost_between;
            others[i] = cur_node;
          }
        }
      }
    }
    minimums[cur_node] = -1;
  }

  int num_edges = qq.getSize();
  Edge** ret = new Edge*[num_edges+1];
  ret[num_edges] = nullptr;
  for(int i = 0; i < num_edges; i++){
    ret[i] = new Edge(qq.pop());
  }

  return ret;

}

void Graph::cleanup_mst(Edge** mst_result){

  int iter = 0;
  while(mst_result[iter] != nullptr){
    delete mst_result[iter];
    iter++;
  }
  delete[] mst_result;

}

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
