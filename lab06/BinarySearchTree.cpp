/**
 * @author: Evan Brown
 * @file: BinarySearchTree.cpp
 * @date: 2/27/19
 * @brief: implementation of binary search tree
 *         adapted from 560 lab 5
 */

#include "quicksort.cpp"
#include "LinkedList.hpp"
#include <cmath>

template <typename T>
BinarySearchTree<T>::BinarySearchTree():
  root(nullptr), size(0){}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
  destroySubtree(root);
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& bst){
  root = copySubtree(bst.root);
  size = bst.size;
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& bst){
  destroySubtree(root);
  root = copySubtree(bst.root);
  size = bst.size;

  return *this;
}

template <typename T>
BinarySearchTree<T> BinarySearchTree<T>::OptimalBSTFactory(T** data, int size, bool print_info){

  // first sort the data
  quicksort<T>(data, size);

  // now count the frequencies of everyrhing
  int unique = 1;
  T* unique_data[size];
  int freqs[size];

  unique_data[0] = data[0];
  freqs[0] = 1;

  for(int i = 1; i < size; i++){
    if(*unique_data[unique-1] == *data[i]) freqs[unique-1]++;
    else{
      unique_data[unique] = data[i];
      freqs[unique] = 1;
      unique++;
    }
  }

  // create arrays of costs and choices
  int costs[unique][unique];
  int** choices = new int*[unique];
  for(int i = 0; i < unique; i++){
    choices[i] = new int[unique];
  }

  // initialize costs and choices for trees of size 1
  for(int i = 0; i < unique; i++){
    costs[i][i] = freqs[i];
    choices[i][i] = i;
  }

  // go through each amount of nodes in tree (minus 1): from 2 to 4, since size 1 is already calculated
  for(int i = 1; i < unique; i++){
    // go through each index in this amount (j and k)
    for(int j = 0; j < unique-i; j++){
      int k = i+j;
      // initialize choice on other side of array to 0
      choices[k][j] = 0;
      // calculate sum of costs between indices
      int sum = 0;
      for(int s = j; s <= k; s++){
        sum += freqs[s];
      }

      // find min of possible subtree costs
      bool first = true;
      int min_cost, min_index;
      for(int s = j; s <= k; s++){
        int test_cost = 0;
        if(s-1 >= j) test_cost += costs[j][s-1];
        if(k >= s+1) test_cost += costs[s+1][k];

        if(first || test_cost < min_cost){
          min_cost = test_cost;
          min_index = s;
          first = false;
        }
      }

      // set the cost and choice for this index
      costs[j][k] = min_cost + sum;
      choices[j][k] = min_index;
    }
  }

  // for(int i = 0; i < unique; i++){
  //   for(int j = 0; j < unique; j++){
  //     std::cout << choices[i][j] << "\t";
  //   }
  //   std::cout << "\n";
  // }

  BinarySearchTree<T> res_bst;
  // insert the root choice for the entire tree
  int root = choices[0][unique-1];
  res_bst.insert(*unique_data[root]);
  // create subtrees left and right of the root
  createSubtree(res_bst, unique_data, choices, 0, root);
  createSubtree(res_bst, unique_data, choices, root+1, unique);

  // cleanup
  for(int i = 0; i < unique; i++){
    delete[] choices[i];
  }
  delete[] choices;

  if(print_info){
    std::cout << "The minimal cost is: " << static_cast<float>(costs[0][unique-1])/size << "\n";
    res_bst.printVisual();
  }

  return res_bst;

}

template <typename T>
void BinarySearchTree<T>::createSubtree(BinarySearchTree<T>& bst, T** unique_data, int* choices[], int lower, int upper){
  if(lower == upper) return;

  int root = choices[lower][upper-1];
  bst.insert(*unique_data[root]);
  createSubtree(bst, unique_data, choices, lower, root);
  createSubtree(bst, unique_data, choices, root+1, upper);
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value){
  root = insertHelper(root, value);
  size++;
}

template <typename T>
void BinarySearchTree<T>::deleteVal(const T& value) throw(ValueNotFound<T>){
  root = deleteFinder(root, value);
  size--;
}

template <typename T>
bool BinarySearchTree<T>::find(const T& value) const{
  return findHelper(root, value);
}

template <typename T>
T BinarySearchTree<T>::findMin() const throw(EmptyStructure){
  if(root == nullptr) throw EmptyStructure();

  BSTNode<T>* leftmost = root;
  while(leftmost->getLeft() != nullptr){
    leftmost = leftmost->getLeft();
  }

  return leftmost->getValue();
}

template <typename T>
T BinarySearchTree<T>::findMax() const throw(EmptyStructure){
  if(root == nullptr) throw EmptyStructure();

  BSTNode<T>* rightmost = root;
  while(rightmost->getRight() != nullptr){
    rightmost = rightmost->getRight();
  }

  return rightmost->getValue();
}

template <typename T>
Preorder<T> BinarySearchTree<T>::preorder() const{
  return Preorder<T>(*this);
}

template <typename T>
Inorder<T> BinarySearchTree<T>::inorder() const{
  return Inorder<T>(*this);
}

template <typename T>
Postorder<T> BinarySearchTree<T>::postorder() const{
  return Postorder<T>(*this);
}

template <typename T>
Levelorder<T> BinarySearchTree<T>::levelorder() const{
  return Levelorder<T>(*this);
}

template <typename T>
void BinarySearchTree<T>::printVisual() const{
  if(root != nullptr){
    LinkedList<LinkedList<BSTNode<T>*>> layers;
    LinkedList<BSTNode<T>*>* cur_layer = new LinkedList<BSTNode<T>*>();
    LinkedList<BSTNode<T>*>* store = new LinkedList<BSTNode<T>*>();
    store->insertBack(root);

    bool notNull = true;
    while(notNull){
      //store->print();
      layers.insertBack(*store);
      cur_layer = store;
      store = new LinkedList<BSTNode<T>*>();
      notNull = false;
      while(!cur_layer->isEmpty()){
        BSTNode<T>* next = cur_layer->popFront();
        BSTNode<T>* l = (next==nullptr ? nullptr : next->getLeft());
        BSTNode<T>* r = (next==nullptr ? nullptr : next->getRight());
        store->insertBack(l);
        store->insertBack(r);
        if(l != nullptr || r != nullptr) notNull = true;
        //store->print();
      }
      //store->print();
    }

    int layer_index = layers.getLength();
    //std::cout << layer_index << "\n";
    while(!layers.isEmpty()){
      for(int i = 0; i < pow(2, layer_index-1)-1; i++){
        std::cout << "\t";
      }
      LinkedList<BSTNode<T>*> cur = layers.popFront();
      while(!cur.isEmpty()){
        BSTNode<T>* node = cur.popFront();
        if(node != nullptr){
          std::cout << node->getValue();
        }
        //if(!cur.isEmpty()){
          for(int i = 0; i < pow(2, layer_index); i++){
            std::cout << "\t";
          }
        //}
      }
      std::cout << "\n";
      layer_index--;
    }
  }
}

template <typename T>
void BinarySearchTree<T>::destroySubtree(BSTNode<T>* st){
  if(st != nullptr){
    destroySubtree(st->getLeft());
    destroySubtree(st->getRight());
    delete st;
  }
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::copySubtree(BSTNode<T>* st){
  if(st == nullptr) return nullptr;

  BSTNode<T>* new_st = st->getChildlessCopy();
  new_st->setLeft(copySubtree(st->getLeft()));
  new_st->setRight(copySubtree(st->getRight()));
  return new_st;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::insertHelper(BSTNode<T>* st, const T& value){
  if(st == nullptr){
    return new BSTNode<T>(value);
  }
  else if(value < st->getValue()){
    st->setLeft(insertHelper(st->getLeft(), value));
  }
  else{
    st->setRight(insertHelper(st->getRight(), value));
  }
  return st;
}

template <typename T>
bool BinarySearchTree<T>::findHelper(BSTNode<T>* st, const T& value) const{
  if(st == nullptr) return false;

  if(st->getValue() == value) return true;

  if(value < st->getValue()) return findHelper(st->getLeft(), value);

  return findHelper(st->getRight(), value);
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::deleteFinder(BSTNode<T>* st, const T& value) throw(ValueNotFound<T>){
  if(st == nullptr) throw ValueNotFound<T>(value);

  if(st->getValue() == value) return deleteHelper(st);

  if(value < st->getValue()) st->setLeft(deleteFinder(st->getLeft(), value));
  else st->setRight(deleteFinder(st->getRight(), value));

  return st;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::deleteHelper(BSTNode<T>* st){

  BSTNode<T>* save = st->getRight();

  if(save == nullptr){
    save = st->getLeft();
    delete st;
    return save;
  }

  if(save->getLeft() == nullptr){
    save->setLeft(st->getLeft());
    delete st;
    return save;
  }

  while(save->getLeft()->getLeft() != nullptr) save = save->getLeft();
  st->setValue(save->getLeft()->getValue());
  save->setLeft(deleteHelper(save->getLeft()));
  return st;

}
