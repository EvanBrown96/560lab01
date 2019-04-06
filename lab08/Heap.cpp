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
Heap<ch, T>::~Heap(){
  destroyHeap();
}

template <int ch, typename T>
void Heap<ch, T>::insert(const T& val){
  if(size == count) resizeHeap();

  data[count] = new T(val);

  int iter = count;
  count++;

  while(iter > 0 && compare(val, data[parent(iter)])){
    swap(iter, parent(iter));
    iter = parent(iter);
  }
}

template <int ch, typename T>
T Heap<ch, T>::findMin() const throw(EmptyStructure){

}

template <int ch, typename T>
T Heap<ch, T>::findMax() const throw(EmptyStructure){

}

template <int ch, typename T>
int Heap<ch, T>::deleteMin() throw(EmptyStructure){

}

template <int ch, typename T>
int Heap<ch, T>::deleteMax() throw(EmptyStructure){

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
