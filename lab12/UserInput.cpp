/**
 * @author: Evan Brown
 * @file: UserInput.cpp
 * @date: 2/19/19
 * @brief: implementation of UserInput functions
 *         adapted from 560 lab03
 */

#include "UserInput.hpp"
#include <iostream>
#include <limits>
#include "Edge.hpp"
#include "Set.hpp"

UserInput::UserInput(Graph* g):
    g(g){}

void UserInput::clearCin(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UserInput::start(){

  int choice = 0;

  while(true){

    std::cout << "Choose one operation from the options below:\n\n";
    std::cout << "\t1. BFS\n";
    std::cout << "\t2. DFS\n";
    std::cout << "\t3. Kruskal MST\n";
    std::cout << "\t4. Prim MST\n";
    std::cout << "\t5. Exit\n";

    while(!(std::cin >> choice && choice > 0 && choice < 6)){
      clearCin();
      std::cout << "Invalid choice, try again: ";
    }

    if(choice == 5){
      break;
    }

    switch(choice){
      case 1: {
        userBFS();
        break;
      }
      case 2: {
        userDFS();
        break;
      }
      case 3: {
        userKruskal();
        break;
      }
      default: {
        userPrim();
        break;
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::userBFS(){

  Edge*** search_res = g->bfs();

  std::cout << "Tree edges: ";
  int iter = 0;
  while(search_res[0][iter] != nullptr){
    std::cout << *search_res[0][iter] << ", ";
    iter++;
  }

  std::cout << "\nCross edges: ";
  iter = 0;
  while(search_res[1][iter] != nullptr){
    std::cout << *search_res[1][iter] << ", ";
    iter++;
  }
  std::cout << "\n";

  Graph::cleanup_search(search_res);

}

void UserInput::userDFS(){

  Edge*** search_res = g->dfs();

  std::cout << "Tree edges: ";
  int iter = 0;
  while(search_res[0][iter] != nullptr){
    std::cout << *search_res[0][iter] << ", ";
    iter++;
  }

  std::cout << "\nBack edges: ";
  iter = 0;
  while(search_res[1][iter] != nullptr){
    std::cout << *search_res[1][iter] << ", ";
    iter++;
  }
  std::cout << "\n";

  Graph::cleanup_search(search_res);

}

void UserInput::userKruskal(){

  try{

    Edge** mst_res = g->kruskal();
    int iter = 0;
    int total_cost = 0;
    while(mst_res[iter] != nullptr){
      std::cout << *mst_res[iter] << ", ";
      total_cost += mst_res[iter]->cost;
      iter++;
    }
    std::cout << "\ncost: " << total_cost << "\n";

    Graph::cleanup_mst(mst_res);

  }
  catch(std::runtime_error& e){
    std::cout << e.what() << "\n";
  }

}

void UserInput::userPrim(){

  try{
    
    Edge** mst_res = g->prim();
    int iter = 0;
    int total_cost = 0;
    while(mst_res[iter] != nullptr){
      std::cout << *mst_res[iter] << ", ";
      total_cost += mst_res[iter]->cost;
      iter++;
    }
    std::cout << "\ncost: " << total_cost << "\n";

    Graph::cleanup_mst(mst_res);

  }
  catch(std::runtime_error& e){
    std::cout << e.what() << "\n";
  }

}
