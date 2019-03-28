template <typename T>
TwoThreeTree<T>::TwoThreeTree():
  root(nullptr){}

template <typename T>
TwoThreeTree<T>::~TwoThreeTree(){
  destroyTree(root);
}

template <typename T>
TwoThreeTree<T>::TwoThreeTree(const TwoThreeTree<T>& copy){
  root = copyTree(copy.root);
}

template <typename T>
TwoThreeTree<T>& TwoThreeTree<T>::operator=(const TwoThreeTree<T>& copy){
  destroyTree(root);
  root = copyTree(copy.root);

  return *this;
}

template <typename T>
void TwoThreeTree<T>::insert(const T& value) throw(DuplicateValue<T>){

  bool kick_up = false;
  root = insertHelper(value, root, kick_up);

}

template <typename T>
TwoThreeNode<T>* TwoThreeTree<T>::insertHelper(const T& value, TwoThreeNode<T>* tree, bool& kick_up){
  if(tree == nullptr){
    // if we've reached an empty spot, create new node and return it, and
    // indicate that a kick-up is needed
    kick_up = true;
    return new TwoThreeNode<T>(value);
  }

  if(tree->getType() == TWO){
    if(value < tree->getVal()){
      TwoThreeNode<T>* res = insertHelper(value, tree->getLeftTree(), kick_up);
      tree->setLeftTree(res);
      if(kick_up) tree->absorbLeftKickUp();
    }
    else if(value > tree->getVal()){
      TwoThreeNode<T>* res = insertHelper(value, tree->getRightTree(), kick_up);
      tree->setRightTree(res);
      if(kick_up) tree->absorbRightKickUp();
    }
    else throw DuplicateValue<T>(value);
    // if we encounter a 2-node, we know that the kick-up will be absorbed completely
    // and we don't need to kick up anything else
    kick_up = false;
  }
  else{
    if(value < tree->getLeftVal()){
      TwoThreeNode<T>* res = insertHelper(value, tree->getLeftTree(), kick_up);
      tree->setLeftTree(res);
      if(kick_up) tree->absorbLeftKickUp();
    }
    else if(value > tree->getRightVal()){
      TwoThreeNode<T>* res = insertHelper(value, tree->getRightTree(), kick_up);
      tree->setRightTree(res);
      if(kick_up) tree->absorbRightKickUp();
    }
    else if(value > tree->getLeftVal() && value < tree->getRightVal()){
      TwoThreeNode<T>* res = insertHelper(value, tree->getMiddleTree(), kick_up);
      tree->setMiddleTree(res);
      if(kick_up) tree->absorbMiddleKickUp();
    }
    else throw DuplicateValue<T>(value);
  }
  return tree;
}

template <typename T>
void TwoThreeTree<T>::remove(const T& value) throw(ValueNotFound<T>){

  //bool hole = false;
  removeHelperFindStage(value, root);
  // if resultant root is a hole, get rid of it and set its subtree as root
  if(root->getType() == HOLE){
    TwoThreeNode<T>* del = root;
    root = root->getTree();
    delete del;
  }

}

template <typename T>
void TwoThreeTree<T>::removeHelperFindStage(const T& value, TwoThreeNode<T>* tree) throw(ValueNotFound<T>){

  if(tree == nullptr){
    throw ValueNotFound<T>(value);
  }

  if(tree->getType() == TWO){
    if(value < tree->getVal()){
      removeHelperFindStage(value, tree->getLeftTree());
      if(tree->getLeftTree()->getType() == HOLE){
        tree->absorbLeftHole();
      }
    }
    else if(value > tree->getVal()){
      removeHelperFindStage(value, tree->getRightTree());
      if(tree->getRightTree()->getType() == HOLE){
        tree->absorbRightHole();
      }
    }
    else{
      removeHelperSingleLeftStage(value, tree);

    }
  }
  else{
    if(value < tree->getLeftVal()){
      removeHelperFindStage(value, tree->getLeftTree());
      if(tree->getLeftTree()->getType() == HOLE){
        tree->absorbLeftHole();
      }
    }
    else if(value > tree->getRightVal()){
      removeHelperFindStage(value, tree->getRightTree());
      if(tree->getRightTree()->getType() == HOLE){
        tree->absorbRightHole();
      }
    }
    else if(value > tree->getLeftVal() && value < tree->getRightVal()){
      removeHelperFindStage(value, tree->getMiddleTree());
      if(tree->getMiddleTree()->getType() == HOLE){
        tree->absorbMiddleHole();
      }
    }
    else removeHelperSingleLeftStage(value, tree);
  }

}

template <typename T>
void TwoThreeTree<T>::removeHelperSingleLeftStage(const T& value, TwoThreeNode<T>* tree){
  if(tree->getType() == TWO){
    // node containing value to delete is already leaf
    if(tree->getLeftTree() == nullptr){
      // make this node a hole; don't care about the value returned since this is the node we want to delete
      tree->makeHole();
    }
    else{
      // get largest predecessor and propogate hole up left subtree, if there is one
      T swap_val = removeHelperFindPredecessorStage(tree->getLeftTree());
      // replace value in node to delete with largest predecessor
      tree->setVal(swap_val);
      // absorb the hole, if there is one
      if(tree->getLeftTree()->getType() == HOLE){
        tree->absorbLeftHole();
      }
    }
  }
  else{
    // want to delete left value of 3-node
    if(value == tree->getLeftVal()){
      // node containing value to delete is already leaf
      if(tree->getLeftTree() == nullptr){
        tree->make2NodeFromRight();
      }
      else{
        T swap_val = removeHelperFindPredecessorStage(tree->getLeftTree());
        tree->setLeftVal(swap_val);
        if(tree->getLeftTree()->getType() == HOLE){
          tree->absorbLeftHole();
        }
      }
    }
    // want to delete right value of 3-node
    else{
      if(tree->getMiddleTree() == nullptr){
        tree->make2NodeFromLeft();
      }
      else{
        T swap_val = removeHelperFindPredecessorStage(tree->getMiddleTree());
        tree->setRightVal(swap_val);
        if(tree->getMiddleTree()->getType() == HOLE){
          tree->absorbMiddleHole();
        }
      }
    }
  }
}

template <typename T>
T TwoThreeTree<T>::removeHelperFindPredecessorStage(TwoThreeNode<T>* tree){
  // found predecessor
  if(tree->getRightTree() == nullptr){
    if(tree->getType() == TWO){
      // make this node a hole and return the value in it
      return tree->makeHole();
    }
    else{
      // make this node into a 2-node with its left value and return its right value
      return tree->make2NodeFromLeft();
    }
  }
  else{
    T swap_val = removeHelperFindPredecessorStage(tree->getRightTree());
    if(tree->getRightTree()->getType() == HOLE){
      tree->absorbRightHole();
    }
    return swap_val;
  }
}

template <typename T>
void TwoThreeTree<T>::removeMin() throw(EmptyStructure){
  remove(findMin());
}

template <typename T>
void TwoThreeTree<T>::removeMax() throw(EmptyStructure){
  remove(findMax());
}

template <typename T>
bool TwoThreeTree<T>::find(const T& value) const{

  return findHelper(value, root);

}

template <typename T>
bool TwoThreeTree<T>::findHelper(const T& value, TwoThreeNode<T>* tree) const{

  if(tree == nullptr) return false;

  if(tree->getType() == TWO){
    if(value == tree->getVal()) return true;
    if(value < tree->getVal()) return findHelper(value, tree->getLeftTree());
    return findHelper(value, tree->getRightTree());
  }

  // if a 3-node
  if(value == tree->getLeftVal() || value == tree->getRightVal()) return true;
  if(value < tree->getLeftVal()) return findHelper(value, tree->getLeftTree());
  if(value > tree->getRightVal()) return findHelper(value, tree->getRightTree());
  return findHelper(value, tree->getMiddleTree());

}

template <typename T>
T TwoThreeTree<T>::findMin() const throw(EmptyStructure){
  if(root == nullptr) throw EmptyStructure();

  TwoThreeNode<T>* iter = root;
  while(iter->getLeftTree() != nullptr) iter = iter->getLeftTree();

  if(iter->getType() == TWO) return iter->getVal();
  return iter->getLeftVal();
}

template <typename T>
T TwoThreeTree<T>::findMax() const throw(EmptyStructure){
  if(root == nullptr) throw EmptyStructure();

  TwoThreeNode<T>* iter = root;
  while(iter->getRightTree() != nullptr) iter = iter->getRightTree();

  if(iter->getType() == TWO) return iter->getVal();
  return iter->getRightVal();
}

template <typename T>
QuickQueue<T> TwoThreeTree<T>::levelOrder() const{
  QuickQueue<T> output(10);
  QuickQueue<TwoThreeNode<T>*> qq(2);
  qq.push(root);

  while(!qq.isEmpty()){
    TwoThreeNode<T>* cur = qq.pop();
    if(cur != nullptr){
      qq.push(cur->getLeftTree());
      if(cur->getType() == TWO){
        output.push(cur->getVal());
      }
      else{
        output.push(cur->getLeftVal());
        output.push(cur->getRightVal());
        qq.push(cur->getMiddleTree());
      }
      qq.push(cur->getRightTree());
    }
  }

  return output;

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
