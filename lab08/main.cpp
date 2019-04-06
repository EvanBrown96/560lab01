#include "MinHeap.hpp"

bool compare(const int& v1, const int& v2){
  return (v1 < v2);
}

int main(int argc, char** argv){
  MinHeap<5, int> h;

  int vals[] = {100, 205, 150, 44, 95, 117, 402, 317, 82, 66, 11, 17, 1, 70, 87, 99};
  int num = 16;

  for(int i = 0; i < num; i++){
    h.insert(vals[i]);
  }

  h.levelOrder();

  h.deleteMin();

  h.levelOrder();
}
