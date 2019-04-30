// 4/30

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "GraphNode.hpp"

class Graph{
public:

  Graph(int num_nodes, int** costs);
  ~Graph();
  Graph(const Graph& copy);
  Graph& operator=(const Graph& copy);

  int*** bfs() const;
  int*** dfs() const;

  static void cleanup_search(int*** search_result);

  int** kruskal() const;
  int** prim() const;

  static void cleanup_mst(int** mst_result);

private:

  void copyGraph(const Graph& copy);
  void destroyGraph();

  int num_nodes;
  GraphNode** nodes;

};

#endif // GRAPH_HPP
