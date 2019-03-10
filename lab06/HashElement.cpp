/**
 * @author: Evan Brown
 * @file: HashElement.cpp
 * @date: 2/8/19
 * @brief: implementation of wrapper class for hash table elements
 *         adapted from 560 lab 3
 */

template <typename K, typename V>
HashElement<K, V>::HashElement(): state(EMPTY){

}

template <typename K, typename V>
HashElement<K, V>::~HashElement(){

  if(state == FULL){
    delete value;
    delete key;
  }

}

template <typename K, typename V>
HashElement<K, V>::HashElement(const HashElement<K, V>& copy_elem){

  if(copy_elem.state == FULL){
    this->key = new K(*copy_elem.key);
    this->value = new V(*copy_elem.value);
  }

  state = copy_elem.state;

}

template <typename K, typename V>
HashElement<K, V>& HashElement<K, V>::operator=(const HashElement<K, V>& copy_elem){

  if(state == FULL){
    delete key;
    delete value;
  }

  if(copy_elem.state == FULL){
    this->key = new K(*copy_elem.key);
    this->value = new V(*copy_elem.value);
  }

  state = copy_elem.state;

  return *this;

}


template <typename K, typename V>
void HashElement<K, V>::set(const K& key, const V& value){

  if(state == FULL){
    delete this->key;
    delete this->value;
  }

  this->key = new K(key);
  this->value = new V(value);
  state = FULL;

}

template <typename K, typename V>
V HashElement<K, V>::get() const throw(EmptyStructure){

  if(state != FULL){
    throw EmptyStructure();
  }

  return *value;

}

template <typename K, typename V>
K HashElement<K, V>::getKey() const throw(EmptyStructure){

  if(state != FULL){
    throw EmptyStructure();
  }

  return *key;
}

template <typename K, typename V>
void HashElement<K, V>::remove() throw(EmptyStructure){

  if(state != FULL){
    throw EmptyStructure();
  }

  delete key;
  delete value;
  state = REMOVED;

}

template <typename K, typename V>
enum HashStates HashElement<K, V>::getState() const{
  return state;
}
