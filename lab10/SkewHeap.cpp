// 4/17

template <typename T>
SkewHeap<T>::SkewHeap():
    root(nullptr){}

template <typename T>
SkewHeap<T>::SkewHeap(const QuickQueue<T>& initial_data):
    root(nullptr){

  while(!initial_data.isEmpty()){
    insert(initial_data.pop());
  }

}

template <typename T>
SkewHeap<T>::~SkewHeap(){
  destroyHeap(root);
}

template <typename T>
SkewHeap<T>::SkewHeap(const SkewHeap<T>& copy){
  root = copyHeap(copy->root);
}


template <typename T>
SkewHeap<T>& SkewHeap<T>::operator=(const SkewHeap<T>& copy){

  destroyHeap(root);
  root = copyHeap(copy->root);

  return *this;

}

template <typename T>
SkewHeap<T> SkewHeap<T>::merge(const SkewHeap<T>& h1, const SkewHeap<T>& h2){

  SkewHeap<T> h1_copy = h1;
  SkewHeap<T> h2_copy = h2;

  SkewHeap<T> new_heap;
  new_heap->root = baseMerge(h1_copy->root, h2_copy->root);

  return new_heap;

}

template <typename T>
void SkewHeap<T>::insert(const T& item){

  SkewNode<T>* new_node = new SkewNode<T>(item);

  root = baseMerge(root, new_node);

}

template <typename T>
void SkewHeap<T>::deleteMax(){

  if(isEmpty()) throw EmptyStructure();

  SkewNode<T>* new_root = baseMerge(root->getLeft(), root->getRight());
  delete root;
  root = new_root;

}

template <typename T>
T SkewHeap<T>::findMax() const{

  if(isEmpty()) throw EmptyStructure();

  return root->get();

}

template <typename T>
bool SkewHeap<T>::isEmpty() const{
  return (root == nullptr);
}

template <typename T>
QuickQueue<T> SkewHeap<T>::inorder() const{

  QuickQueue<T> qq(10);
  inorderHelper(root, qq);

  return qq;

}

template <typename T>
QuickQueue<T> SkewHeap<T>::preorder() const{

  QuickQueue<T> qq(10);
  preorderHelper(root, qq);

  return qq;

}

template <typename T>
QuickQueue<T> SkewHeap<T>::postorder() const{

  QuickQueue<T> qq(10);
  preorderHelper(root, qq);

  return qq;

}

template <typename T>
void SkewHeap<T>::preorderHelper(SkewNode<T>* subtree, QuickQueue<T>& qq){

  qq.push(subtree->get());
  preorderHelper(subtree->getLeft(), qq);
  preorderHelper(subtree->getRight(), qq);

}

template <typename T>
void SkewHeap<T>::inorderHelper(SkewNode<T>* subtree, QuickQueue<T>& qq);

template <typename T>
void SkewHeap<T>::postorderHelper(SkewNode<T>* subtree, QuickQueue<T>& qq);

template <typename T>
QuickQueue<QuickQueue<T>> SkewHeap<T>::levelorder() const{}

template <typename T>
void SkewHeap<T>::destroyHeap(SkewNode<T>* subtree){

  if(subtree == nullptr) return;

  destroyHeap(subtree->getLeft());
  destroyHeap(subtree->getRight());
  delete subtree;

}

template <typename T>
SkewNode<T>* SkewHeap<T>::copyHeap(SkewNode<T>* subtree){

  if(subtree == nullptr) return nullptr;

  SkewNode<T>* new_node = new SkewNode<T>(subtree->get());
  new_node->setLeft(copyHeap(new_node->getLeft()));
  new_node->setRight(copyHeap(new_node->getRight()));

  return new_node;

}

template <typename T>
SkewNode<T>* SkewHeap<T>::baseMerge(SkewNode<T>* st1, SkewNode<T>* st2){

  if(st1 == nullptr) return st2;
  if(st2 == nullptr) return st1;

  SkewNode<T>* helper;

  if(st1->get() < st2->get()){
    // swap order of trees
    helper = st1;
    st1 = st2;
    st2 = helper;
  }

  helper = baseMerge(st1->getRight(), st2);
  st1->setRight(st1->getLeft());
  st1->setLeft(helper);

  return st1;

}
