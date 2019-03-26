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
  destroyTree(root);
  root = copyTree(copy->root);
}

template <typename T>
void TwoThreeTree<T>::insert(const T& value) throw(DuplicateValue<T>){
  // if tree is empty, make root a new 2-node

  // TwoThreeNode<T>* newNode = new TwoThreeNode<T>(value);

  bool kick_up = false;
  root = insertHelper(value, root, kick_up);
  // if(root == nullptr){
  //   root = new TwoThreeNode<T>(value);
  //   return;
  // }


}

template <typename T>
TwoThreeNode<T>* TwoThreeTree<T>::insertHelper(const T& value, TwoThreeNode<T>* tree, bool& kick_up){
  if(tree == nullptr){
    kick_up = true;
    return new TwoThreeNode<T>(value);
  }

  if(tree->getType() == TWO){
    if(value == tree->getVal()) throw DuplicateValue<T>(value);
    if(value < tree->getVal()){
      //tree->setLeftTree(insertHelper(value, tree->getLeftTree()));
      TwoThreeNode<T>* res = insertHelper(value, tree->getLeftTree(), kick_up);
      tree->setLeftTree(res);
      if(kick_up) tree->absorbLeftKickUp();
        // res->toThreeNodeWithRightVal(tree->getValue());
        // res->setRightTree(tree->getRightTree());
        // delete tree;
        // kick_up = false;
        // TwoThreeNode<T>* ret = new TwoThreeNode<T>(value, tree->getValue());
        // ret->setLeftTree(res->getLeftTree());
        // ret->setMiddleTree(res->getRightTree());
        // ret->setRightTree(tree->getRightTree());
        // delete res;
        // return ret;
      // }
    }
    else{
      //tree->setRightTree(insertHelper(value, tree->getRightTree()));
      TwoThreeNode<T>* res = insertHelper(value, tree->getRightTree(), kick_up);
      tree->setRightTree(res);
      if(kick_up) tree->absorbRightKickUp();
      //   res->toThreeNodeWithLeftVal(tree->getValue());
      //   res->setLeftTree(tree->getLeftTree());
      //   delete tree;
      //   kick_up = false;
      //   // TwoThreeNode<T>* ret = new TwoThreeNode<T>(value, tree->getValue());
      //   // ret->setLeftTree(tree->getLeftTree());
      //   // ret->setMiddleTree(res->getLeftTree());
      //   // ret->setRightTree(res->getRightTree());
      //   // delete res;
      //   // return ret;
      // }
      // return res;
    }
    kick_up = false;
    //return tree;

  }
  else{
    if(value < tree->getLeftVal()){ //tree->setLeftTree(insertHelper(value, tree->getLeftTree()));
      TwoThreeNode<T>* res = insertHelper(value, tree->getLeftTree(), kick_up);
      tree->setLeftTree(res);
      if(kick_up) tree->absorbLeftKickUp();
    }
    else if(value > tree->getRightVal()){ //tree->setRightTree(insertHelper(value, tree->getRightTree()));
      TwoThreeNode<T>* res = insertHelper(value, tree->getRightTree(), kick_up);
      tree->setRightTree(res);
      if(kick_up) tree->absorbRightKickUp();
    }
    else if(value > tree->getLeftVal() && value < tree->getRightVal()){
      //tree->setMiddleTree(insertHelper(value, tree->getMiddleTree()));
      TwoThreeNode<T>* res = insertHelper(value, tree->getMiddleTree(), kick_up);
      tree->setMiddleTree(res);
      if(kick_up) tree->absorbMiddleKickUp();
    }
    else throw DuplicateValue<T>(value);
  }
  return tree;
}

// void TwoThreeTree<T>::insertHelperTwo(TwoThreeNode<T>* newNode, TwoThreeNode<T>* tree) throw(DuplicateValue<T>){
//   if(newNode->getVal() < tree->getVal()) tree->setLeftSubtree(insertHelper(newNode, tree->getLeftTree()));
//   else if(newNode->getVal() > tree->getVal()) tree->setRightSubtree(insertHelper(newNode, tree->getRightTree()));
//   else throw DuplicateValue<T>(newNode->getValue());
// }

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
  if(root == nullptr) throw EmptyStructure();

  TwoThreeNode<T>* iter = root;
  while(iter->getLeftTree() != nullptr) iter = iter->getLeftTree();

  return iter->getLeftVal();
}

template <typename T>
T TwoThreeTree<T>::findMax() const throw(EmptyStructure){
  if(root == nullptr) throw EmptyStructure();

  TwoThreeNode<T>* iter = root;
  while(iter->getRightTree() != nullptr) iter = iter->getRightTree();

  return iter->getRightVal();
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
