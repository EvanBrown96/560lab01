#include <iostream>


template <typename T>
QuickQueue<T>::QuickQueue(int size):
  size(size), start(0), count(0), contents(new T*[size]){}

template <typename T>
QuickQueue<T>::~QuickQueue(){
  destroyQueue();
}

template <typename T>
QuickQueue<T>::QuickQueue(const QuickQueue<T>& qq){

}

template <typename T>
QuickQueue<T>& QuickQueue<T>::operator=(const QuickQueue<T>& qq){
  destroyQueue();
}

template <typename T>
T QuickQueue<T>::peek() const throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();

  return *contents[start];
}

template <typename T>
T QuickQueue<T>::pop() throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();

  T ret = *contents[start];
  delete contents[start];
  start = (start+1)%size;
  count--;

}

template <typename T>
void QuickQueue<T>::push(const T& item) throw(FullStructure){
  if(count == size) throw FullStructure();

  contents[start+count] = new T(item);
  if(item != nullptr){
    std::cout << "inserting " << item->getValue() << " into position " << start+count << "\n";
    std::cout << "inserted " << contents[start+count]->getValue() << "\n";
  }
  count++;

}

template <typename T>
bool QuickQueue<T>::isEmpty() const{
  return (count == 0);
}

template <typename T>
void QuickQueue<T>::destroyQueue(){
  for(int i = start; i < start+count; i=(i+1)%size){
    delete contents[i];
  }
  delete[] contents;
}
