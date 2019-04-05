template <typename T>
Heap<T>::Heap(): data(new T*[1]), size(1), count(0){}

template <typename T>
Heap<T>::~Heap(){
  destroyHeap()
}

template <typename T>
void Heap<T>::destroyHeap(){
  for(int i = 0; i < count; i++){
    delete data[i];
  }
  delete[] data;
}

template <typename T>
QuickQueue<T> Heap<T>::levelOrder() const;
