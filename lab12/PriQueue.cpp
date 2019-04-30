// 4/30

template <typename T>
PriQueue<T>::PriQueue(){}

template <typename T>
void PriQueue<T>::push(const T& item){
  base.insert(item);
}

template <typename T>
T PriQueue<T>::pop(){
  T outp = base.findMin();
  base.deleteMin();
  return outp;
}

template <typename T>
T PriQueue<T>::peek() const{
  return base.findMin();
}
