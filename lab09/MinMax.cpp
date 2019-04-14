// 4/13

#include <iostream>

template <typename T>
MinMax<T>::MinMax():
  data(new T*[1]), size(1), count(0){}

template <typename T>
MinMax<T>::MinMax(QuickQueue<T> qq){

  count = qq.getSize();
  // set size to an evenly-layered number
  size = 1;
  while(size < count){
    size = (size*2)+1;
  }

  // add items to the tree, in level order
  data = new T*[size];
  for(int i = 0; i < count; i++){
    data[i] = new T(qq.pop());
  }

  // start at the last non-leaf node and go to the root
  for(int i = parent(count-1); i > -1; i--){
    if(isMinNode(i)) pushDownMin(i);
    else pushDownMax(i);
  }

}

template <typename T>
MinMax<T>::~MinMax(){
  destroyHeap();
}

template <typename T>
MinMax<T>::MinMax(const MinMax<T>& copy){
  copyHeap(copy);
}

template <typename T>
MinMax<T>& MinMax<T>::operator=(const MinMax<T>& copy){
  destroyHeap();
  copyHeap(copy);
}

template <typename T>
void MinMax<T>::insert(const T& item){
  if(count == size) resizeHeap();

  data[count] = new T(item);
  count++;

  // don't need to do anything else if this was first element
  if(count == 1) return;

  int iter = count-1;
  int check = parent(iter);

  if(indexLT(iter, check)){

    // ensure check is a min-node
    if(!isMinNode(check)) check = grandparent(iter);

    while(true){
      if(check < 0) break;
      if(indexLT(iter, check)){
        swap(iter, check);
        iter = check;
      }
      check = grandparent(check);
    }

  }
  else if(indexGT(iter, check)){
    // ensure check is a max-node
    if(isMinNode(check)) check = grandparent(iter);

    while(true){
      if(check < 0) break;
      if(indexGT(iter, check)){
        swap(iter, check);
        iter = check;
      }
      check = grandparent(check);
    }
  }

}

template <typename T>
void MinMax<T>::deleteMin() throw(EmptyStructure){

  if(count == 0) throw EmptyStructure();

  count--;
  delete data[0];
  if(count == 0){
    data[0] = nullptr;
    return;
  }
  data[0] = data[count];
  data[count] = nullptr;

  pushDownMin(0);

}

template <typename T>
void MinMax<T>::pushDownMin(int index){

  int repl;

  while(true){

    repl = index;

    if(lchild(lchild(index)) < count){
      // check grandchildren
      for(int i = rchild(rchild(index)); i >= lchild(lchild(index)); i--){
        if(i < count && indexLT(i, repl)) repl = i;
      }
    }
    else if(lchild(index) < count){
      // check children
      for(int i = rchild(index); i >= lchild(index); i--){
        if(i < count && indexLT(i, repl)) repl = i;
      }
    }

    if(repl == index) break;

    swap(index, repl);
    index = repl;

  }

}

template <typename T>
void MinMax<T>::deleteMax() throw(EmptyStructure){

  if(count == 0) throw EmptyStructure();

  if(count == 1){
    deleteMin();
    return;
  }

  // find index of max element
  int max = 2;
  if(count == 2 || indexGTE(1, 2)) max = 1;

  // replace max with last element
  count--;
  delete data[max];
  if(count == max){
    data[max] = nullptr;
    return;
  }
  data[max] = data[count];
  data[count] = nullptr;

  pushDownMax(max);

}

template <typename T>
void MinMax<T>::pushDownMax(int index){

  int repl;

  while(true){

    repl = index;

    if(lchild(lchild(index)) < count){
      // check grandchildren
      for(int i = rchild(rchild(index)); i >= lchild(lchild(index)); i--){
        if(i < count && indexGT(i, repl)) repl = i;
      }
    }
    else if(lchild(index) < count){
      // check children
      for(int i = rchild(index); i >= lchild(index); i--){
        if(i < count && indexGT(i, repl)) repl = i;
      }
    }

    if(repl == index) break;

    swap(index, repl);
    index = repl;

  }

}

template <typename T>
T MinMax<T>::findMin() const throw(EmptyStructure){
  return getActualMin();
}

template <typename T>
T& MinMax<T>::getActualMin() const throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();

  return *data[0];
}

template <typename T>
T MinMax<T>::findMax() const throw(EmptyStructure){
  return getActualMax();
}

template <typename T>
T& MinMax<T>::getActualMax() const throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();

  if(count == 1) return *data[0];

  if(count == 2 || (*data[1]) >= (*data[2])) return *data[1];

  return *data[2];
}

template <typename T>
void MinMax<T>::levelOrder() const{

  if(count == 0){
    std::cout << "Heap is empty\n\n";
    return;
  }

  int line = 0;
  for(int i = 0; i < count; i++){
    std::cout << *data[i] << " ";
    if(i == line){
      std::cout << "\n";
      line = (line+1)*2;
    }
    else if(i%2 == 0){
      std::cout << "- ";
    }
  }

  std::cout << "\n\n";

}

template <typename T>
void MinMax<T>::resizeHeap(){
  T** old_data = data;
  data = new T*[(size*2)+1];

  for(int i = 0; i < count; i++){
    data[i] = old_data[i];
  }

  delete[] old_data;
  size = (size*2)+1;
}

template <typename T>
void MinMax<T>::destroyHeap(){

  for(int i = 0; i < count; i++){
    delete data[i];
  }
  delete[] data;

}

template <typename T>
void MinMax<T>::copyHeap(const MinMax<T>& copy){

  size = copy.size;
  count = copy.count;
  data = new T*[size];

  for(int i = 0; i < count; i++){
    data[i] = new T(*(copy.data[i]));
  }

}

template <typename T>
int MinMax<T>::parent(int index) const{
  if(index < 1) return -1;
  return (index-1)/2;
}

template <typename T>
int MinMax<T>::grandparent(int index) const{
  return parent(parent(index));
}

template <typename T>
int MinMax<T>::lchild(int index) const{
  return (index*2)+1;
}

template <typename T>
int MinMax<T>::rchild(int index) const{
  return (index*2)+2;
}

template <typename T>
bool MinMax<T>::isMinNode(int index) const{
  bool ret = true;

  while(index > 0){
    index = parent(index);
    ret = !ret;
  }

  return ret;
}

template <typename T>
void MinMax<T>::swap(int idx1, int idx2){
  T* store = data[idx1];
  data[idx1] = data[idx2];
  data[idx2] = store;
}

template <typename T>
bool MinMax<T>::indexLT(int idx1, int idx2) const{
  return (*data[idx1]) < (*data[idx2]);
}

template <typename T>
bool MinMax<T>::indexGT(int idx1, int idx2) const{
  return (*data[idx1]) > (*data[idx2]);
}

template <typename T>
bool MinMax<T>::indexLTE(int idx1, int idx2) const{
  return !indexGT(idx1, idx2);
}

template <typename T>
bool MinMax<T>::indexGTE(int idx1, int idx2) const{
  return !indexLT(idx1, idx2);
}
