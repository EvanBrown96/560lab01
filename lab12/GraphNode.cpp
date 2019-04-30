// 4/30

#include <stdexcept>
#include "GraphNode.hpp"

GraphNode::GraphNode(int num_costs, const int* costs):
    num_costs(num_costs), costs(new int[num_costs]){

  for(int i = 0; i < num_costs; i++){
    this->costs[i] = costs[i];
  }

}

GraphNode::~GraphNode(){
  delete[] costs;
}

GraphNode::GraphNode(const GraphNode& copy){
  copyNode(copy);
}

GraphNode& GraphNode::operator=(const GraphNode& copy){
  delete[] costs;
  copyNode(copy);
  return *this;
}


int GraphNode::costTo(int node_index){
  if(node_index >= num_costs) throw std::runtime_error("Invalid Node Index");
  return costs[node_index];
}

bool GraphNode::isNeighbor(int node_index){
  return (costTo(node_index) != -1);
}

void GraphNode::copyNode(const GraphNode& copy){
  num_costs = copy.num_costs;
  costs = new int[num_costs];

  for(int i = 0; i < num_costs; i++){
    costs[i] = copy.costs[i];
  }
}
