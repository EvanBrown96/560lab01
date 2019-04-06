#include "MinHeap.hpp"
#include "MaxHeap.hpp"
#include "QuickQueue.hpp"

bool compare(const int& v1, const int& v2){
  return (v1 < v2);
}

int main(int argc, char** argv){

  int vals[] = {100, 205, 150, 44, 95, 117, 402, 317, 82, 66, 11, 17, 1, 70, 87, 99};
  int num = 16;

  QuickQueue<int> qq(num);

  for(int i = 0; i < num; i++){
    qq.push(vals[i]);
  }

  MaxHeap<5, int> h(qq);
  h.levelOrder();

  h.deleteMin();

  h.levelOrder();
}
