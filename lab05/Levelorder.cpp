#include "QuickQueue.hpp"

template <typename T>
Levelorder<T>::Levelorder(const BinarySearchTree<T>& bst):
  Traversal<T>(bst){

  int index = 0;
  creationHelper(bst.root, index);
}

template <typename T>
void Levelorder<T>::creationHelper(BSTNode<T>* st, int& index){

  QuickQueue<BSTNode<T>> qq((this->size)*2);
  qq.push(*st);

  while(!qq.isEmpty()){
    BSTNode<T> next = qq.pop();

    //if(next != nullptr){
      this->values[index] = new T(next.getValue());
      index += 1;

      if(next.getLeft() != nullptr) qq.push(*next.getLeft());
      if(next.getRight() != nullptr) qq.push(*next.getRight());
    //}
  }

}
