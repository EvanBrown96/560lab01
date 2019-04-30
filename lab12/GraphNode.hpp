// 4/30

#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP

class GraphNode{
public:

  GraphNode(int num_costs, const int* costs);
  ~GraphNode();
  GraphNode(const GraphNode& copy);
  GraphNode& operator=(const GraphNode& copy);

  int costTo(int node_index);

  bool isNeighbor(int node_index);

private:

  void copyNode(const GraphNode& copy);

  int num_costs;
  int* costs;

};

#endif // GRAPHNODE_HPP
