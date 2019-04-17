// 4/16

template <typename T>
SkewNode<T>::SkewNode(const T& item):
    item(item), left(nullptr), right(nullptr){}

template <typename T>
T& SkewNode<T>::get() const{
  return item;
}

template <typename T>
void SkewNode<T>::set(const T& item){
  this->item = item;
}

template <typename T>
SkewNode<T>* SkewNode<T>::getLeft(){
  return left;
}

template <typename T>
void SkewNode<T>::setLeft(SkewNode<T>* left){
  this->left = left;
}

template <typename T>
SkewNode<T>* SkewNode<T>::getRight(){
  return right;
}

template <typename T>
void SkewNode<T>::setRight(SkewNode<T>* right){
  this->right = right;
}
