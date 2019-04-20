// 4/17

#include <iostream>
#include <cmath>

template <typename T>
SkewHeap<T>::SkewHeap():
    root(nullptr){}

template <typename T>
SkewHeap<T>::SkewHeap(const QuickQueue<T>& initial_data):
    root(nullptr){

  QuickQueue<T> dup(initial_data);

  while(!dup.isEmpty()){
    insert(dup.pop());
  }

}

template <typename T>
SkewHeap<T>::~SkewHeap(){
  destroyHeap(root);
}

template <typename T>
SkewHeap<T>::SkewHeap(const SkewHeap<T>& copy){
  root = copyHeap(copy.root);
}


template <typename T>
SkewHeap<T>& SkewHeap<T>::operator=(const SkewHeap<T>& copy){

  destroyHeap(root);
  root = copyHeap(copy.root);

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
void SkewHeap<T>::preorderHelper(SkewNode<T>* subtree, QuickQueue<T>& qq) const{

  if(subtree == nullptr) return;

  qq.push(subtree->get());
  preorderHelper(subtree->getLeft(), qq);
  preorderHelper(subtree->getRight(), qq);

}

template <typename T>
void SkewHeap<T>::inorderHelper(SkewNode<T>* subtree, QuickQueue<T>& qq) const{

  if(subtree == nullptr) return;

  inorderHelper(subtree->getLeft(), qq);
  qq.push(subtree->get());
  inorderHelper(subtree->getRight(), qq);

}

template <typename T>
void SkewHeap<T>::postorderHelper(SkewNode<T>* subtree, QuickQueue<T>& qq) const{

  if(subtree == nullptr) return;

  postorderHelper(subtree->getLeft(), qq);
  postorderHelper(subtree->getRight(), qq);
  qq.push(subtree->get());

}

template <typename T>
QuickQueue<T> SkewHeap<T>::levelorder() const{

  QuickQueue<T> data(10);

  if(root == nullptr) return data;

  QuickQueue<SkewNode<T>> qq(10);
  qq.push(*root);

  while(!qq.isEmpty()){
    SkewNode<T> next = qq.pop();

    data.push(next.get());

    if(next.getLeft() != nullptr) qq.push(*next.getLeft());
    if(next.getRight() != nullptr) qq.push(*next.getRight());
  }

  return data;

}

template <typename T>
void SkewHeap<T>::printSpace(int count) const{
  for(int i = 0; i < count; i++){
    std::cout << " ";
  }
}

template <typename T>
void SkewHeap<T>::printMaxLen(int val, int max) const{

  bool neg = false;
  if(val < 0){
    val *= -1;
    neg = true;
  }
  QuickQueue<char> qq(10);
  if(val == 0) qq.push('0');
  while(val > 0){
    qq.push('0' + val%10);
    val /= 10;
  }

  int length = qq.getSize()+1+(neg ? 1 : 0);
  char string[length];
  string[length-1] = '\0';
  if(neg) string[0] = '-';

  int ci = length-2;
  while(!qq.isEmpty()){
    string[ci] = qq.pop();
    ci--;
  }

  if(length-1 <= max){
    length--;
    int side = (max-length)/2;
    for(int i = 0; i < side; i++){
      std::cout << "?";
    }
    std::cout << string;
    for(int i = 0; i < max - length - side; i++){
      std::cout << "?";
    }
    return;
  }
  for(int i = 0; i < max-3; i++){
    std::cout << string[i];
  }
  std::cout << "...";
}

template <typename T>
void SkewHeap<T>::printVisual() const{
  if(root != nullptr){
    QuickQueue<QuickQueue<SkewNode<T>*>> layers(10);
    QuickQueue<SkewNode<T>*>* cur_layer = new QuickQueue<SkewNode<T>*>(10);
    QuickQueue<SkewNode<T>*>* store = new QuickQueue<SkewNode<T>*>(10);
    store->push(root);

    bool notNull = true;
    while(notNull){
      //store->print();
      layers.push(*store);
      delete cur_layer;
      cur_layer = store;
      store = new QuickQueue<SkewNode<T>*>(10);
      notNull = false;
      while(!cur_layer->isEmpty()){
        SkewNode<T>* next = cur_layer->pop();
        SkewNode<T>* l = (next==nullptr ? nullptr : next->getLeft());
        SkewNode<T>* r = (next==nullptr ? nullptr : next->getRight());
        store->push(l);
        store->push(r);
        if(l != nullptr || r != nullptr) notNull = true;
      }
    }
    delete cur_layer;
    delete store;

    int layer_index = layers.getSize();

    while(!layers.isEmpty()){
      int lines = DISPLAY_LEN*pow(2, layer_index-1)/2;

      for(int i = 0; i < lines; i++){
        int opp_i = lines-i-1;
        QuickQueue<SkewNode<T>*> cur = layers.peek();
        if(cur.getSize() <= 1) break;
        printSpace(DISPLAY_LEN * (pow(2, layer_index-1)-1));
        int isleft = true;
        while(!cur.isEmpty()){
          SkewNode<T>* node = cur.pop();
          if(node != nullptr){
            if(isleft){
              printSpace(opp_i*2+4);
              std::cout << "/";
              printSpace(i*2+1);
            }
            else{
              printSpace(i*2+1);
              std::cout << "\\";
              printSpace(opp_i*2+4);
            }
          }
          else{
            printSpace(i*2+opp_i*2+6);
          }
          if(!isleft) printSpace(DISPLAY_LEN * (pow(2, layer_index)-1));
          isleft = !isleft;
        }
        std::cout << "\n";
      }

      printSpace(DISPLAY_LEN * (pow(2, layer_index-1)-1));
      QuickQueue<SkewNode<T>*> cur = layers.pop();
      while(!cur.isEmpty()){
        SkewNode<T>* node = cur.pop();
        if(node != nullptr){
          printMaxLen(node->get(), DISPLAY_LEN);
        }
        else{
          printSpace(DISPLAY_LEN);
        }
        printSpace(DISPLAY_LEN * (pow(2, layer_index)-1));
      }
      std::cout << "\n";
      layer_index--;
    }
  }
}

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

  if(st1->get() > st2->get()){
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
