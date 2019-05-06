template <typename T>
Set<T>::Set(SetNode<T>* root, int rank):
    root(root), rank(rank), prev(nullptr), next(nullptr){}

template <typename T>
Set<T>::Set(const T& item):
    rank(0), prev(nullptr), next(nullptr){

  root = new SetNode<T>(item, this);

}

template <typename T>
int Set<T>::getRank() const{
  return rank;
}

template <typename T>
void Set<T>::setRank(int rank){
  this->rank = rank;
}

template <typename T>
T Set<T>::getRootItem() const{
  return root->getItem();
}

template <typename T>
bool Set<T>::operator==(const Set<T>& test) const{
  return root == test.root;
}

template <typename T>
bool Set<T>::operator!=(const Set<T>& test) const{
  return root != test.root;
}

template <typename T>
SetNode<T>* Set<T>::getRoot() const{
  return root;
}

template <typename T>
void Set<T>::setRoot(SetNode<T>* root){
  this->root = root;
}

template <typename T>
Set<T>* Set<T>::getPrev() const{
  return prev;
}

template <typename T>
void Set<T>::setPrev(Set<T>* prev){
  this->prev = prev;
}

template <typename T>
Set<T>* Set<T>::getNext() const{
  return next;
}

template <typename T>
void Set<T>::setNext(Set<T>* next){
  this->next = next;
}
