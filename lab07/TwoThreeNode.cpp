template <typename T>
enum NodeType TwoThreeNode<T>::getType() const{
  return ntype;
}

template <typename T>
TwoThreeNode<T>::TwoThreeNode(const T& value):
  ntype(TWO), lvalue(value), ltree(nullptr), rtree(nullptr){}

template <typename T>
TwoThreeNode<T>::TwoThreeNode(const T& lvalue, const T& rvalue):
  ntype(THREE), lvalue(lvalue), rvalue(rvalue), ltree(nullptr), mtree(nullptr), rtree(nullptr){}

template <typename T>
T TwoThreeNode<T>::getVal() const throw(InvalidNodeType){
  if(ntype != TWO) throw InvalidNodeType();
  return lvalue;
}

template <typename T>
void TwoThreeNode<T>::setVal(const T& value) throw(InvalidNodeType){
  if(ntype != TWO) throw InvalidNodeType();
  lvalue = value;
}

template <typename T>
T TwoThreeNode<T>::getLeftVal() const throw(InvalidNodeType){
  if(ntype != THREE) throw InvalidNodeType();
  return lvalue;
}

template <typename T>
T TwoThreeNode<T>::getRightVal() const throw(InvalidNodeType){
  if(ntype != THREE) throw InvalidNodeType();
  return rvalue;
}

template <typename T>
void TwoThreeNode<T>::setLeftVal(const T& value) throw(InvalidNodeType){
  if(ntype != THREE) throw InvalidNodeType();
  lvalue = value;
}

template <typename T>
void TwoThreeNode<T>::setRightVal(const T& value) throw(InvalidNodeType){
  if(ntype != THREE) throw InvalidNodeType();
  rvalue = value;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getMiddleTree() const throw(InvalidNodeType){
  if(ntype != THREE) throw InvalidNodeType();
  return mtree;
}

template <typename T>
void TwoThreeNode<T>::setMiddleTree(TwoThreeNode<T>* tree) throw(InvalidNodeType){
  if(ntype != THREE) throw InvalidNodeType();
  mtree = tree;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getLeftTree() const{
  return ltree;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getRightTree() const{
  return rtree;
}

template <typename T>
void TwoThreeNode<T>::setLeftTree(TwoThreeNode<T>* tree){
  ltree = tree;
}

template <typename T>
void TwoThreeNode<T>::setRightTree(TwoThreeNode<T>* tree){
  rtree = tree;
}
