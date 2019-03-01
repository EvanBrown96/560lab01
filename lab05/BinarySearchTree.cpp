/**
 * @author: Evan Brown
 * @file: BinarySearchTree.cpp
 * @date: 2/27/19
 * @brief: implementation of binary search tree
 */

template <typename T>
BinarySearchTree<T>::BinarySearchTree():
  root(nullptr), size(0){}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
  destroySubtree(root);
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& bst){
  root = copySubtree(bst.root);
  size = bst.size;
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& bst){
  destroySubtree(root);
  root = copySubtree(bst.root);
  size = bst.size;

  return *this;
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value){
  root = insertHelper(root, value);
  size++;
}

template <typename T>
void BinarySearchTree<T>::deleteVal(const T& value) throw(ValueNotFound<T>){

  size--;
}

template <typename T>
bool BinarySearchTree<T>::find(const T& value){
  return findHelper(root, value);
}

template <typename T>
T BinarySearchTree<T>::findMin() throw(EmptyStructure){
  if(root == nullptr) throw EmptyStructure();

  BSTNode<T>* leftmost = root;
  while(leftmost->getLeft() != nullptr){
    leftmost = leftmost->getLeft();
  }

  return leftmost->getValue();
}

template <typename T>
T BinarySearchTree<T>::findMax() throw(EmptyStructure){
  if(root == nullptr) throw EmptyStructure();

  BSTNode<T>* rightmost = root;
  while(rightmost->getRight() != nullptr){
    rightmost = rightmost->getRight();
  }

  return rightmost->getValue();
}

template <typename T>
Preorder<T> BinarySearchTree<T>::preorder() const{
  return Preorder<T>(*this);
}

template <typename T>
Inorder<T> BinarySearchTree<T>::inorder() const{
  return Inorder<T>(*this);
}

template <typename T>
Postorder<T> BinarySearchTree<T>::postorder() const{
  return Postorder<T>(*this);
}

template <typename T>
Levelorder<T> BinarySearchTree<T>::levelorder() const{
  return Levelorder<T>(*this);
}

template <typename T>
void BinarySearchTree<T>::destroySubtree(BSTNode<T>* st){
  if(st != nullptr){
    destroySubtree(st->getLeft());
    destroySubtree(st->getRight());
    delete st;
  }
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::copySubtree(BSTNode<T>* st){
  if(st == nullptr) return nullptr;

  BSTNode<T>* new_st = st->getChildlessCopy();
  new_st->setLeft(copySubtree(st->getLeft()));
  new_st->setRight(copySubtree(st->getRight()));
  return new_st;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::insertHelper(BSTNode<T>* st, const T& value){
  if(st == nullptr){
    return new BSTNode<T>(value);
  }
  else if(value < st->getValue()){
    st->setLeft(insertHelper(st->getLeft(), value));
  }
  else{
    st->setRight(insertHelper(st->getRight(), value));
  }
  return st;
}

template <typename T>
bool BinarySearchTree<T>::findHelper(BSTNode<T>* st, const T& value) const{
  if(st == nullptr) return false;

  if(st->getValue() == value) return true;

  if(value < st->getValue()) return findHelper(st->getLeft(), value);

  return findHelper(st->getRight(), value);
}
