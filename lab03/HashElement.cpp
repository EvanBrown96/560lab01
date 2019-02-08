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

  this->value = new T(*copy_elem.value);
  state = copy_elem.state;

}

template <typename T>
HashElement<T>& HashElement<T>::operator=(const HashElement<T>& copy_elem){

  delete value;
  this->value = new T(*copy_elem.value);
  state = copy_elem.state;

  return *this;

}


template <typename T>
void HashElement<T>::set(const T& value){

  this->value = new T(value);
  state = FULL;

}

template <typename T>
T HashElement<T>::get() const{

  return *value;

}

template <typename T>
void HashElement<T>::remove(){

  delete value;
  state = REMOVED;

}

template <typename T>
enum HashStates HashElement<T>::getState() const{
  return state;
}
