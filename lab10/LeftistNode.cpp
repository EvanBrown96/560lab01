// 4/17

template <typename T>
LeftistNode<T>::LeftistNode(const T& item):
    item(item), rank(1), left(nullptr), right(nullptr){}

template <typename T>
T LeftistNode<T>::get() const{
  return item;
}

template <typename T>
void LeftistNode<T>::set(const T& item){
  this->item = item;
}

template <typename T>
LeftistNode<T>* LeftistNode<T>::getLeft() const{
  return left;
}

template <typename T>
void LeftistNode<T>::setLeft(LeftistNode<T>* left){
  this->left = left;
  calcRank();
}

template <typename T>
LeftistNode<T>* LeftistNode<T>::getRight() const{
  return right;
}

template <typename T>
void LeftistNode<T>::setRight(LeftistNode<T>* right){
  this->right = right;
  calcRank();
}

template <typename T>
int LeftistNode<T>::getRank() const{
  return rank;
}

template <typename T>
void LeftistNode<T>::calcRank(){
  if(left == nullptr || right == nullptr) rank = 1;
  else{
    int lrank = left->rank;
    int rrank = right->rank;

    if(lrank <= rrank) rank = lrank;
    else rank = rrank;
  }
}
