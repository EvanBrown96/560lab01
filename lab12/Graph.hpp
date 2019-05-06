// 5/5

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "GraphNode.hpp"
#include "Edge.hpp"
#include "QuickQueue.hpp"

class Graph{
public:

  Graph(int num_nodes, int** costs);
  ~Graph();
  Graph(const Graph& copy);
  Graph& operator=(const Graph& copy);

  Edge*** bfs() const;
  Edge*** dfs() const;

  static void cleanup_search(Edge*** search_result);

  Edge** kruskal() const;
  Edge** prim() const;

  static void cleanup_mst(Edge** mst_result);

private:

  void copyGraph(const Graph& copy);
  void destroyGraph();

  int num_nodes;
  GraphNode** nodes;

  void dfsHelper(bool* node_marked, bool** edge_marked, QuickQueue<Edge>& tree_edges, QuickQueue<Edge>& back_edges, int index) const;


};

#endif // GRAPH_HPP
