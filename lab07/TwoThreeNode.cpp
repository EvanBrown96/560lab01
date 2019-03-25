template <typename T>
TwoThreeNode<T>::TwoThreeNode(enum NodeType ntype):
  ntype(ntype){}

template <typename T>
enum NodeType TwoThreeNode<T>::getType() const{
  return ntype;
}

template <typename T>
TwoNode<T>::TwoNode(const T& value): TwoThreeNode<T>(TWO),
  value(value), ltree(nullptr), rtree(nullptr){}

template <typename T>
T TwoNode<T>::getVal() const{
  return value;
}

template <typename T>
TwoThreeNode<T>* TwoNode<T>::getLeftTree() const{
  return ltree;
}

template <typename T>
TwoThreeNode<T>* TwoNode<T>::getRightTree() const{
  return rtree;
}

template <typename T>
void TwoNode<T>::setVal(const T& value){
  this->value = value;
}

template <typename T>
void TwoNode<T>::setLeftTree(TwoThreeNode<T>* tree){
  ltree = tree;
}

template <typename T>
void TwoNode<T>::setRightTree(TwoThreeNode<T>* tree){
  rtree = tree;
}

template <typename T>
ThreeNode<T>::ThreeNode(const T& lvalue, const T& rvalue): TwoThreeNode<T>(THREE),
  lvalue(lvalue), rvalue(rvalue), ltree(nullptr), mtree(nullptr), rtree(nullptr){}

template <typename T>
T ThreeNode<T>::getLeftVal() const{
  return lvalue;
}

template <typename T>
T ThreeNode<T>::getRightVal() const{
  return rvalue;
}

template <typename T>
TwoThreeNode<T>* ThreeNode<T>::getLeftTree() const{
  return ltree;
}

template <typename T>
TwoThreeNode<T>* ThreeNode<T>::getMiddleTree() const{
  return mtree;
}

template <typename T>
TwoThreeNode<T>* ThreeNode<T>::getRightTree() const{
  return rtree;
}

template <typename T>
void ThreeNode<T>::setLeftVal(const T& value){
  lvalue = value;
}

template <typename T>
void ThreeNode<T>::setRightVal(const T& value){
  rvalue = value;
}

template <typename T>
void ThreeNode<T>::setLeftTree(TwoThreeNode<T>* tree){
  ltree = tree;
}

template <typename T>
void ThreeNode<T>::setMiddleTree(TwoThreeNode<T>* tree){
  mtree = tree;
}

template <typename T>
void ThreeNode<T>::setRightTree(TwoThreeNode<T>* tree){
  rtree = tree;
}
