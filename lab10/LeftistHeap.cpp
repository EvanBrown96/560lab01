// 4/17

template <typename T>
LeftistHeap<T>::LeftistHeap():
    root(nullptr){}

template <typename T>
LeftistHeap<T>::LeftistHeap(const QuickQueue<T>& initial_data):
    root(nullptr){

  QuickQueue<T> dup(initial_data);

  while(!dup.isEmpty()){
    insert(dup.pop());
  }

}

template <typename T>
LeftistHeap<T>::~LeftistHeap(){
  destroyHeap(root);
}

template <typename T>
LeftistHeap<T>::LeftistHeap(const LeftistHeap<T>& copy){
  root = copyHeap(copy->root);
}


template <typename T>
LeftistHeap<T>& LeftistHeap<T>::operator=(const LeftistHeap<T>& copy){

  destroyHeap(root);
  root = copyHeap(copy->root);

  return *this;

}

template <typename T>
LeftistHeap<T> LeftistHeap<T>::merge(const LeftistHeap<T>& h1, const LeftistHeap<T>& h2){

  LeftistHeap<T> h1_copy = h1;
  LeftistHeap<T> h2_copy = h2;

  LeftistHeap<T> new_heap;
  new_heap->root = baseMerge(h1_copy->root, h2_copy->root);

  return new_heap;

}

template <typename T>
void LeftistHeap<T>::insert(const T& item){

  LeftistNode<T>* new_node = new LeftistNode<T>(item);

  root = baseMerge(root, new_node);

}

template <typename T>
void LeftistHeap<T>::deleteMax(){

  if(isEmpty()) throw EmptyStructure();

  LeftistNode<T>* new_root = baseMerge(root->getLeft(), root->getRight());
  delete root;
  root = new_root;

}

template <typename T>
T LeftistHeap<T>::findMax() const{

  if(isEmpty()) throw EmptyStructure();

  return root->get();

}

template <typename T>
bool LeftistHeap<T>::isEmpty() const{
  return (root == nullptr);
}

template <typename T>
QuickQueue<T> LeftistHeap<T>::inorder() const{

  QuickQueue<T> qq(10);
  inorderHelper(root, qq);

  return qq;

}

template <typename T>
QuickQueue<T> LeftistHeap<T>::preorder() const{

  QuickQueue<T> qq(10);
  preorderHelper(root, qq);

  return qq;

}

template <typename T>
QuickQueue<T> LeftistHeap<T>::postorder() const{

  QuickQueue<T> qq(10);
  preorderHelper(root, qq);

  return qq;

}

template <typename T>
void LeftistHeap<T>::preorderHelper(LeftistNode<T>* subtree, QuickQueue<T>& qq) const{

  if(subtree == nullptr) return;

  qq.push(subtree->get());
  preorderHelper(subtree->getLeft(), qq);
  preorderHelper(subtree->getRight(), qq);

}

template <typename T>
void LeftistHeap<T>::inorderHelper(LeftistNode<T>* subtree, QuickQueue<T>& qq) const{

  if(subtree == nullptr) return;

  inorderHelper(subtree->getLeft(), qq);
  qq.push(subtree->get());
  inorderHelper(subtree->getRight(), qq);

}

template <typename T>
void LeftistHeap<T>::postorderHelper(LeftistNode<T>* subtree, QuickQueue<T>& qq) const{

  if(subtree == nullptr) return;

  postorderHelper(subtree->getLeft(), qq);
  postorderHelper(subtree->getRight(), qq);
  qq.push(subtree->get());

}

template <typename T>
QuickQueue<T> LeftistHeap<T>::levelorder() const{

  QuickQueue<T> data(10);

  if(root == nullptr) return data;

  QuickQueue<LeftistNode<T>> qq(10);
  qq.push(*root);

  while(!qq.isEmpty()){
    LeftistNode<T> next = qq.pop();

    data.push(next.get());

    if(next.getLeft() != nullptr) qq.push(*next.getLeft());
    if(next.getRight() != nullptr) qq.push(*next.getRight());
  }

  return data;

}

template <typename T>
void LeftistHeap<T>::destroyHeap(LeftistNode<T>* subtree){

  if(subtree == nullptr) return;

  destroyHeap(subtree->getLeft());
  destroyHeap(subtree->getRight());
  delete subtree;

}

template <typename T>
LeftistNode<T>* LeftistHeap<T>::copyHeap(LeftistNode<T>* subtree){

  if(subtree == nullptr) return nullptr;

  LeftistNode<T>* new_node = new LeftistNode<T>(subtree->get());
  new_node->setLeft(copyHeap(new_node->getLeft()));
  new_node->setRight(copyHeap(new_node->getRight()));

  return new_node;

}

template <typename T>
LeftistNode<T>* LeftistHeap<T>::baseMerge(LeftistNode<T>* st1, LeftistNode<T>* st2){

  if(st1 == nullptr) return st2;
  if(st2 == nullptr) return st1;

  LeftistNode<T>* helper;

  if(st1->get() > st2->get()){
    // swap order of trees
    helper = st1;
    st1 = st2;
    st2 = helper;
  }

  helper = baseMerge(st1->getRight(), st2);

  if(helper->getRank() < st1->getLeft()->getRank()){
    st1->setRight(st1->getLeft());
    st1->setLeft(helper);
  }
  else{
    st1->setRight(helper);
  }

  return st1;

}
