template <typename T>
SetNode<T>::SetNode(const T& item, SetNode<T>* parent):
    item(item), parent(parent), myset(nullptr), prev(nullptr), next(nullptr){}

template <typename T>
SetNode<T>::SetNode(const T& item, Set<T>* myset):
    item(item), parent(nullptr), myset(myset), prev(nullptr), next(nullptr){}

template <typename T>
T SetNode<T>::getItem() const{
  return item;
}

template <typename T>
void SetNode<T>::setItem(const T& item){
  this->item = item;
}

template <typename T>
SetNode<T>* SetNode<T>::getParent() const{
  return parent;
}

template <typename T>
void SetNode<T>::setParent(SetNode<T>* parent){
  this->parent = parent;
  myset = nullptr;
}

template <typename T>
Set<T>* SetNode<T>::getMySet() const{
  return myset;
}

template <typename T>
void SetNode<T>::setMySet(Set<T>* myset){
  this->myset = myset;
  parent = nullptr;
}

template <typename T>
SetNode<T>* SetNode<T>::getPrev() const{
  return prev;
}

template <typename T>
void SetNode<T>::setPrev(SetNode<T>* prev){
  this->prev = prev;
}

template <typename T>
SetNode<T>* SetNode<T>::getNext() const{
  return next;
}

template <typename T>
void SetNode<T>::setNext(SetNode<T>* next){
  this->next = next;
}
