#include <iostream>

template <typename T>
MinMax<T>::MinMax():
  data(new T*[1]), size(1), count(0){}

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
      if(indexLT(iter, check)){
        swap(iter, check);
        iter = check;
      }
      if(check == 0) break;
      check = grandparent(check);
    }

  }
  else if(indexGT(iter, check)){

    // ensure check is a max-node
    if(isMinNode(check)) check = grandparent(iter);

    while(true){
      if(indexGT(iter, check)){
        swap(iter, check);
        iter = check;
      }
      if(check < 3) break;
      check = grandparent(check);
    }
  }

}

template <typename T>
void MinMax<T>::deleteMin() throw(EmptyStructure){

  if(count == 0) throw EmptyStructure();

  count--;
  delete data[0];
  if(count == 0) return;
  data[0] = data[count];

  int iter = 0;
  int repl;

  while(true){

    repl = iter;

    if(lchild(lchild(iter)) < count){
      // check grandchildren
      if(indexLTE(rchild(rchild(iter)), repl)) repl = rchild(rchild(iter));
      if(indexLTE(lchild(rchild(iter)), repl)) repl = lchild(rchild(iter));
      if(indexLTE(rchild(lchild(iter)), repl)) repl = rchild(lchild(iter));
      if(indexLTE(lchild(lchild(iter)), repl)) repl = lchild(lchild(iter));
    }
    else if(lchild(iter) < count){
      // check children
      if(indexLTE(rchild(iter), repl)) repl = rchild(iter);
      if(indexLTE(lchild(iter), repl)) repl = lchild(iter);
    }

    if(repl == iter) break;

    swap(iter, repl);
    iter = repl;

  }

}

template <typename T>
void MinMax<T>::deleteMax() throw(EmptyStructure){

  if(count == 0) throw EmptyStructure();

  if(count == 1) deleteMin();

  // find index of max element
  int iter = 2;
  if(count == 2 || indexGTE(1, 2)) iter = 1;

  // replace max with last element
  count--;
  delete data[iter];
  if(count == iter) return;
  data[iter] = data[count];

  int repl;

  while(true){

    repl = iter;

    if(lchild(lchild(iter)) < count){
      // check grandchildren
      if(indexGTE(rchild(rchild(iter)), repl)) repl = rchild(rchild(iter));
      if(indexGTE(lchild(rchild(iter)), repl)) repl = lchild(rchild(iter));
      if(indexGTE(rchild(lchild(iter)), repl)) repl = rchild(lchild(iter));
      if(indexGTE(lchild(lchild(iter)), repl)) repl = lchild(lchild(iter));
    }
    else if(lchild(iter) < count){
      // check children
      if(indexGTE(rchild(iter), repl)) repl = rchild(iter);
      if(indexGTE(lchild(iter), repl)) repl = lchild(iter);
    }

    if(repl == iter) break;

    swap(iter, repl);
    iter = repl;

  }

}

template <typename T>
T MinMax<T>::findMin() const throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();

  return *data[0];
}

template <typename T>
T MinMax<T>::findMax() const throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();

  if(count == 1) return *data[0];

  if(count == 2 || (*data[1]) >= (*data[2])) return *data[1];

  return *data[2];
}

template <typename T>
void MinMax<T>::levelOrder() const{

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
