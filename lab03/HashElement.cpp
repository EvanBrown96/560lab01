/**
 * @author: Evan Brown
 * @file: HashElement.cpp
 * @date: 2/8/19
 * @brief: implementation of wrapper class for hash table elements
 */

template <typename T>
HashElement<T>::HashElement(): state(EMPTY){

}

template <typename T>
HashElement<T>::~HashElement(){

  if(state == FULL){
    delete value;
  }

}

template <typename T>
HashElement<T>::HashElement(const HashElement<T>& copy_elem){

  if(copy_elem.state == FULL){
    this->value = new T(*copy_elem.value);
  }

  state = copy_elem.state;

}

template <typename T>
HashElement<T>& HashElement<T>::operator=(const HashElement<T>& copy_elem){

  if(state == FULL){
    delete value;
  }

  if(copy_elem.state == FULL){
    this->value = new T(*copy_elem.value);
  }

  state = copy_elem.state;

  return *this;

}


template <typename T>
void HashElement<T>::set(const T& value){

  if(state == FULL){
    delete value;
  }

  this->value = new T(value);
  state = FULL;

}

template <typename T>
T HashElement<T>::get() const throw(EmptyLocation){

  if(state != FULL){
    throw EmptyLocation();
  }

  return *value;

}

template <typename T>
void HashElement<T>::remove() throw(EmptyLocation){

  if(state != FULL){
    throw EmptyLocation();
  }

  delete value;
  state = REMOVED;

}

template <typename T>
enum HashStates HashElement<T>::getState() const{
  return state;
}
