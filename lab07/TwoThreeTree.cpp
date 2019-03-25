template <typename T>
TwoThreeTree<T>::TwoThreeTree():
  root(nullptr){}

template <typename T>
TwoThreeTree<T>::~TwoThreeTree(){
  destroyTree(root);
}

template <typename T>
TwoThreeTree<T>::TwoThreeTree(const TwoThreeTree<T>& copy){
  root = copyTree(copy->root);
}

template <typename T>
TwoThreeTree<T>& TwoThreeTree<T>::operator=(const TwoThreeTree<T>& copy){

}

template <typename T>
void TwoThreeTree<T>::insert(const T& value){

}

template <typename T>
void TwoThreeTree<T>::remove(const T& value) throw(ValueNotFound<T>){

}

template <typename T>
void TwoThreeTree<T>::removeMin() throw(EmptyStructure){

}

template <typename T>
void TwoThreeTree<T>::removeMax() throw(EmptyStructure){

}

template <typename T>
bool TwoThreeTree<T>::find(const T& value) const{

}

template <typename T>
T TwoThreeTree<T>::findMin() const throw(EmptyStructure){

}

template <typename T>
T TwoThreeTree<T>::findMax() const throw(EmptyStructure){

}

template <typename T>
void TwoThreeTree<T>::destroyTree(TwoThreeNode<T>* tree){
  if(tree == nullptr) return;
  destroyTree(tree->getLeftTree());
  destroyTree(tree->getRightTree());
  if(tree->getType() == THREE) destroyTree(tree->getMiddleTree());
  delete tree;
}

template <typename T>
TwoThreeNode<T>* TwoThreeTree<T>::copyTree(TwoThreeNode<T>* tree){
  if(tree == nullptr) return nullptr;

  TwoThreeNode<T>* ret = new TwoThreeNode<T>(*tree);
  ret->setLeftTree(copyTree(tree->getLeftTree()));
  ret->setRightTree(copyTree(tree->getRightTree()));
  if(tree->getType() == THREE) ret->setMiddleTree(copyTree(tree->getMiddleTree()));
  return ret;
}
