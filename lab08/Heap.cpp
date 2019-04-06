/**
 * @author: Evan Brown
 * @file: Heap.cpp
 * @date: 4/6/19
 * @brief: implementation of general heap functions
 */

#include <math.h>
#include <iostream>

template <int ch, typename T>
Heap<ch, T>::Heap(bool (*compare)(const T& v1, const T& v2)):
  data(new T*[1]), size(1), count(0), compare(compare){}

template <int ch, typename T>
Heap<ch, T>::Heap(bool (*compare)(const T& v1, const T& v2), const QuickQueue<T>& initial):
  compare(compare){

  // count = initial.getSize();
  // set size to an evenly-layered number
  // size = 1;
  // while(size < count){
  //   size = (size*5)+1;
  // }
  //
  // // add items to the tree, in level order
  // data = new T*[size];
  // for(int i = 0; i < count; i++){
  //   data[i] = new T(initial.pop());
  // }
  //
  // // start at the last non-leaf node and go to the root
  // for(int i = parent(count-1); i > -1; i--){
  //   pushDown(i);
  // }

}

template <int ch, typename T>
Heap<ch, T>::~Heap(){
  destroyHeap();
}

template <int ch, typename T>
void Heap<ch, T>::insert(const T& val){
  if(size == count) resizeHeap();

  data[count] = new T(val);

  int iter = count;
  count++;

  while(iter > 0 && indexCompare(iter, parent(iter))){
    swap(iter, parent(iter));
    iter = parent(iter);
  }
}

template <int ch, typename T>
T Heap<ch, T>::findHighest() const throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();
  return data[0];
}

template <int ch, typename T>
T Heap<ch, T>::findLowest() const throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();
  return *data[findLowestIndex()];
}

template <int ch, typename T>
void Heap<ch, T>::deleteHighest() throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();
  safeRemove(0);
}

template <int ch, typename T>
void Heap<ch, T>::deleteLowest() throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();
  safeRemove(findLowestIndex());
}

template <int ch, typename T>
int Heap<ch, T>::findLowestIndex() const{
  if(count == 1) return 0;
  // start at first leaf node
  int curlow = parent(count-1)+1;
  for(int i = curlow+1; i < count; i++){
    if(compare(curlow, i)) curlow = i;
  }

  return curlow;
}

template <int ch, typename T>
void Heap<ch, T>::levelOrder() const{

  int line = 0;
  for(int i = 0; i < count; i++){
    std::cout << *data[i] << " ";
    if(i == line){
      std::cout << "\n";
      line = (line+1)*ch;
    }
    else if(i%ch == 0){
      std::cout << "- ";
    }
  }

  std::cout << "\n\n";

}

template <int ch, typename T>
void Heap<ch, T>::destroyHeap(){
  for(int i = 0; i < count; i++){
    delete data[i];
  }
  delete[] data;
}

template <int ch, typename T>
void Heap<ch, T>::resizeHeap(){
  T** old_data = data;
  data = new T*[(size*ch)+1];

  for(int i = 0; i < count; i++){
    data[i] = old_data[i];
  }

  delete[] old_data;
  size = (size*ch)+1;
}

template <int ch, typename T>
int Heap<ch, T>::parent(int child) const{
  return (child-1)/ch;
}

template <int ch, typename T>
void Heap<ch, T>::swap(int idx1, int idx2){
  T* store = data[idx1];
  data[idx1] = data[idx2];
  data[idx2] = store;
}

template <int ch, typename T>
void Heap<ch, T>::safeRemove(int index){

  count--;
  delete data[index];
  data[index] = data[count];

  pushDown(index);

}

template <int ch, typename T>
void Heap<ch, T>::pushDown(int index){
  levelOrder();
  fflush(stdout);
  if(index >= count) return;

  int worthy = index;

  // find most worthy element of the given index and all its children
  for(int child = index*5+1; child < index*5+6 && child < count; child++){
    if(indexCompare(child, worthy)) worthy = child;
  }

  // do a swap if necessary
  if(worthy != index){
    swap(worthy, index);
    pushDown(worthy);
  }

}

template <int ch, typename T>
bool Heap<ch, T>::indexCompare(int idx1, int idx2) const{
  return compare(*data[idx1], *data[idx2]);
}
