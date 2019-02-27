template <typename T>
Preorder<T>::Preorder(const BinarySearchTree<T>& bst): Traversal<T>(){
  this->size = bst.size;
  this->values = new T*[this->size];
  int index = 0;

  creationHelper(bst.root, index);

}

template <typename T>
void Preorder<T>::creationHelper(BSTNode<T>* st, int& index){
  if(st != nullptr){
    this->values[index] = new T(st->getValue());
    index += 1;
    creationHelper(st->getLeft(), index);
    creationHelper(st->getRight(), index);
  }
}
