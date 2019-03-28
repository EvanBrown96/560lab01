#include <iostream>

template <typename T>
enum NodeType TwoThreeNode<T>::getType() const{
  return ntype;
}

template <typename T>
bool TwoThreeNode<T>::isLeaf() const{
  if(ntype == HOLE){
    return (ltree == nullptr);
  }
  if(ntype == TWO){
    return (ltree == nullptr && rtree == nullptr);
  }
  return (ltree == nullptr && mtree == nullptr && rtree == nullptr);
}

template <typename T>
T TwoThreeNode<T>::makeHole() throw(InvalidNodeType){
  checkInvalidType(TWO, "makeHole");
  if(rtree != nullptr) throw InvalidNodeType("makeHole requires empty right tree");
  ntype = HOLE;
  return lvalue;
}

template <typename T>
T TwoThreeNode<T>::make2NodeFromLeft() throw(InvalidNodeType){
  checkInvalidType(THREE, "make2NodeFromLeft");
  if(rtree != nullptr) throw InvalidNodeType("make2NodeFromLeft requires empty right tree");
  ntype = TWO;
  rtree = mtree;
  return rvalue;
}

template <typename T>
T TwoThreeNode<T>::make2NodeFromRight() throw(InvalidNodeType){
  checkInvalidType(THREE, "make3NodeFromLeft");
  if(ltree != nullptr) throw InvalidNodeType("make2NodeFromLeft requires empty left tree");
  ntype = TWO;
  T save = lvalue;
  lvalue = rvalue;
  ltree = mtree;
  return save;
}

template <typename T>
void TwoThreeNode<T>::checkInvalidType(enum NodeType safe, const char* msg) const throw(InvalidNodeType){
  if(ntype != safe) throw InvalidNodeType(msg);
}

template <typename T>
void TwoThreeNode<T>::checkInvalidType(enum NodeType safe, enum NodeType safe2, const char* msg) const throw(InvalidNodeType){
  if(ntype != safe && ntype != safe2) throw InvalidNodeType(msg);
}

template <typename T>
TwoThreeNode<T>::TwoThreeNode(const T& value):
  ntype(TWO), lvalue(value), ltree(nullptr), mtree(nullptr), rtree(nullptr){}

template <typename T>
TwoThreeNode<T>::TwoThreeNode(const T& lvalue, const T& rvalue):
  ntype(THREE), lvalue(lvalue), rvalue(rvalue), ltree(nullptr), mtree(nullptr), rtree(nullptr){}

template <typename T>
T TwoThreeNode<T>::getVal() const throw(InvalidNodeType){
  checkInvalidType(TWO, "getVal");
  return lvalue;
}

template <typename T>
void TwoThreeNode<T>::setVal(const T& value) throw(InvalidNodeType){
  checkInvalidType(TWO, "setVal");
  lvalue = value;
}

template <typename T>
void TwoThreeNode<T>::absorbLeftKickUp() throw(InvalidNodeType, EmptyStructure){
  if(ltree == nullptr) throw EmptyStructure();
  if(ltree->ntype != TWO) throw InvalidNodeType("absorbLeftKickUp requires left node be a 2-node");

  if(ntype == TWO){
    // turn parent node into 3-node
    ntype = THREE;
    // keep reference to current left tree
    TwoThreeNode<T>* save = ltree;
    // make old 2-node value right value of 3-node
    rvalue = lvalue;
    // make value of kick-up node left value of 3-node
    lvalue = save->lvalue;
    // make right tree of kick-up node middle tree of 3-node
    mtree = save->rtree;
    // make left tree of kick-up node left tree of 3-node
    ltree = save->ltree;
    // delete kick-up node
    delete save;
  }
  else{
    // turn parent node into 2-node
    ntype = TWO;
    // make new node with old right 3-node value
    TwoThreeNode<T>* rnew = new TwoThreeNode<T>(rvalue);
    // make middle tree of old 3-node left tree of new node
    rnew->ltree = mtree;
    // make right tree of old 3-node right tree of new node
    rnew->rtree = rtree;
    // make new node right tree of parent node
    rtree = rnew;

    mtree = nullptr; //safety
  }
}

template <typename T>
void TwoThreeNode<T>::absorbRightKickUp() throw(InvalidNodeType, EmptyStructure){
  if(rtree == nullptr) throw EmptyStructure();
  if(rtree->ntype != TWO) throw InvalidNodeType("absorbRightKickUp requires right node be a 2-node");

  if(ntype == TWO){
    ntype = THREE;

    TwoThreeNode<T>* save = rtree;
    rvalue = save->lvalue;
    mtree = save->ltree;
    rtree = save->rtree;
    delete save;
  }
  else{
    ntype = TWO;

    TwoThreeNode<T>* lnew = new TwoThreeNode<T>(lvalue);
    lnew->ltree = ltree;
    lnew->rtree = mtree;

    lvalue = rvalue;
    ltree = lnew;

    mtree = nullptr; //safety
  }

}

template <typename T>
void TwoThreeNode<T>::absorbMiddleKickUp() throw(InvalidNodeType, EmptyStructure){
  checkInvalidType(THREE, "absorbMiddleKickUp");
  if(mtree == nullptr) throw EmptyStructure();
  if(mtree->ntype != TWO) throw InvalidNodeType("absorbMiddleKickUp requires middle node be a 2-node");

  ntype = TWO;

  TwoThreeNode<T>* lnew = new TwoThreeNode<T>(lvalue);
  TwoThreeNode<T>* rnew = new TwoThreeNode<T>(rvalue);
  lnew->ltree = ltree;
  lnew->rtree = mtree->ltree;
  rnew->ltree = mtree->rtree;
  rnew->rtree = rtree;

  lvalue = mtree->lvalue;
  delete mtree;
  mtree = nullptr;
  ltree = lnew;
  rtree = rnew;

}

template <typename T>
void TwoThreeNode<T>::absorbLeftHole() throw(InvalidNodeType, EmptyStructure){
  if(ltree == nullptr) throw EmptyStructure();
  if(ltree->ntype != HOLE) throw InvalidNodeType("absorbLeftHole requires left node be a hole node");

  if(ntype == TWO) absorbLeftHoleTwoNode();
  else absorbLeftHoleThreeNode();
}

template <typename T>
void TwoThreeNode<T>::absorbLeftHoleTwoNode() throw(InvalidNodeType, EmptyStructure){
  if(rtree == nullptr) throw EmptyStructure();

  if(rtree->ntype == TWO){ // case 1-1
    // make parent node into hole
    ntype = HOLE;
    // make right node into 3-node
    rtree->ntype = THREE;
    // make left tree of old right node it's middle tree
    rtree->mtree = rtree->ltree;
    // make subtree of hole node into 3-node's left tree
    rtree->ltree = ltree->ltree;
    // make old 2-node value new 3-node's right value
    rtree->rvalue = rtree->lvalue;
    // make parent node value new 3-node's left value
    rtree->lvalue = lvalue;
    // delete hole node
    delete ltree;
    // make new hole node's subtree old updated 3-node
    ltree = rtree;
  }
  else if(rtree->ntype == THREE){ // case 2-1
    // make left node into 2-node
    ltree->ntype = TWO;
    // make right node into 2-node
    rtree->ntype = TWO;
    // set left tree value to parent node current value
    ltree->lvalue = lvalue;
    // set parent node value to rtree current left value
    lvalue = rtree->lvalue;
    // move rtree right value to left value
    rtree->lvalue = rtree->rvalue;
    // set ltree right subtree to rtree left subtree
    ltree->rtree = rtree->ltree;
    // move old rtree mtree to be it's ltree
    rtree->ltree = rtree->mtree;
    rtree->mtree = nullptr; //safety
  }
  else throw InvalidNodeType("absorbLeftHoleTwoNode requires right node not be a hole node");
}

template <typename T>
void TwoThreeNode<T>::absorbLeftHoleThreeNode() throw(InvalidNodeType, EmptyStructure){
  if(mtree == nullptr) throw EmptyStructure();

  if(mtree->ntype == TWO){ // case 3a-1
    ntype = TWO;
    ltree->ntype = THREE;
    ltree->lvalue = lvalue;
    ltree->rvalue = mtree->lvalue;
    lvalue = rvalue;
    ltree->mtree = mtree->ltree;
    ltree->rtree = mtree->rtree;
    delete mtree;
    mtree = nullptr; //safety
  }
  else if(mtree->ntype == THREE){ // case 4a-1
    ltree->ntype = TWO;
    mtree->ntype = TWO;
    ltree->lvalue = lvalue;
    lvalue = mtree->lvalue;
    mtree->lvalue = mtree->rvalue;
    ltree->rtree = mtree->ltree;
    mtree->ltree = mtree->mtree;
    mtree->mtree = nullptr; //safety
  }
  else throw InvalidNodeType("absorbLeftHoleThreeNode requires middle node not be a hole node");
}

template <typename T>
void TwoThreeNode<T>::absorbRightHole() throw(InvalidNodeType, EmptyStructure){
  if(rtree == nullptr) throw EmptyStructure();
  if(rtree->ntype != HOLE) throw InvalidNodeType("absorbRightHole requires right node be a hole node");

  if(ntype == TWO) absorbRightHoleTwoNode();
  else absorbRightHoleThreeNode();
}

template <typename T>
void TwoThreeNode<T>::absorbRightHoleTwoNode() throw(InvalidNodeType, EmptyStructure){
  if(ltree == nullptr) throw EmptyStructure();

  if(ltree->ntype == TWO){ // case 1-2
    ntype = HOLE;
    ltree->ntype = THREE;
    ltree->mtree = ltree->rtree;
    ltree->rtree = rtree->ltree;
    ltree->rvalue = lvalue;
    delete rtree;
    rtree = nullptr; //safety
  }
  else if(ltree->ntype == THREE){ // case 2-2
    ltree->ntype = TWO;
    rtree->ntype = TWO;
    rtree->lvalue = lvalue;
    lvalue = ltree->rvalue;
    rtree->ltree = ltree->rtree;
    ltree->rtree = ltree->mtree;
    ltree->mtree = nullptr; //safety
  }
  else throw InvalidNodeType("absorbRightHoleTwoNode requires left node not be a hole node");
}

template <typename T>
void TwoThreeNode<T>::absorbRightHoleThreeNode() throw(InvalidNodeType, EmptyStructure){
  if(mtree == nullptr) throw EmptyStructure();

  if(mtree->ntype == TWO){ // case 3b-2
    ntype = TWO;
    rtree->ntype = THREE;
    rtree->lvalue = mtree->lvalue;
    rtree->rvalue = rvalue;
    rtree->rtree = rtree->ltree;
    rtree->mtree = mtree->rtree;
    rtree->ltree = mtree->ltree;
    delete mtree;
    mtree = nullptr; //safety
  }
  else if(mtree->ntype == THREE){ // case 4b-2
    mtree->ntype = TWO;
    rtree->ntype = TWO;
    rtree->lvalue = rvalue;
    rvalue = mtree->rvalue;
    rtree->rtree = rtree->ltree;
    rtree->ltree = mtree->rtree;
    mtree->rtree = mtree->mtree;
    mtree->mtree = nullptr; //safety
  }
  else throw InvalidNodeType("absorbRightHoleThreeNode requires middle node not be a hole node");
}

template <typename T>
void TwoThreeNode<T>::absorbMiddleHole() throw(InvalidNodeType, EmptyStructure){
  if(mtree == nullptr) throw EmptyStructure();
  if(mtree->ntype != HOLE) throw InvalidNodeType("absorbMiddleHole requires middle node be a hole node");

  if(ltree == nullptr && rtree == nullptr) throw EmptyStructure();

  //std::cout << "UNDEFINED FUNCTION!!!!\n";

  if(ltree != nullptr && ltree->ntype == TWO){ // case 3a-2
    ntype = TWO;
    ltree->ntype = THREE;
    ltree->rvalue = lvalue;
    lvalue = rvalue;
    ltree->mtree = ltree->rtree;
    ltree->rtree = mtree->ltree;
    delete mtree;
    mtree = nullptr; //safety
  }
  else if(rtree != nullptr && rtree->ntype == TWO){ // case 3b-1
    ntype = TWO;
    rtree->ntype = THREE;
    rtree->rvalue = rtree->lvalue;
    rtree->lvalue = rvalue;
    rtree->mtree = rtree->ltree;
    rtree->ltree = mtree->ltree;
    delete mtree;
    mtree = nullptr; //safety
  }
  else if(ltree != nullptr && ltree->ntype == THREE){ // case 4a-2
    ltree->ntype = TWO;
    mtree->ntype = TWO;
    mtree->lvalue = lvalue;
    lvalue = ltree->rvalue;
    mtree->rtree = mtree->ltree;
    mtree->ltree = ltree->rtree;
    ltree->rtree = ltree->mtree;
    ltree->mtree = nullptr; //safety
  }
  else if(rtree != nullptr && rtree->ntype == THREE){ // case 4b-1
    mtree->ntype = TWO;
    rtree->ntype = TWO;
    mtree->lvalue = rvalue;
    rvalue = rtree->lvalue;
    rtree->lvalue = rtree->rvalue;
    mtree->rtree = rtree->ltree;
    rtree->ltree = rtree->mtree;
    rtree->mtree = nullptr; //safety
  }
  else throw InvalidNodeType("absorbMiddleHole requires either left node or right node not be a hole node");

}

template <typename T>
T TwoThreeNode<T>::getLeftVal() const throw(InvalidNodeType){
  checkInvalidType(THREE, "getLeftVal");
  return lvalue;
}

template <typename T>
T TwoThreeNode<T>::getRightVal() const throw(InvalidNodeType){
  checkInvalidType(THREE, "getRightVal");
  return rvalue;
}

template <typename T>
void TwoThreeNode<T>::setLeftVal(const T& value) throw(InvalidNodeType){
  checkInvalidType(THREE, "setLeftVal");
  lvalue = value;
}

template <typename T>
void TwoThreeNode<T>::setRightVal(const T& value) throw(InvalidNodeType){
  checkInvalidType(THREE, "setRightVal");
  rvalue = value;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getMiddleTree() const throw(InvalidNodeType){
  checkInvalidType(THREE, "getMiddleTree");
  return mtree;
}

template <typename T>
void TwoThreeNode<T>::setMiddleTree(TwoThreeNode<T>* tree) throw(InvalidNodeType){
  checkInvalidType(THREE, "setMiddleTree");
  mtree = tree;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getLeftTree() const throw(InvalidNodeType){
  checkInvalidType(TWO, THREE, "getLeftTree");
  return ltree;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getRightTree() const throw(InvalidNodeType){
  checkInvalidType(TWO, THREE, "getRightTree");
  return rtree;
}

template <typename T>
void TwoThreeNode<T>::setLeftTree(TwoThreeNode<T>* tree) throw(InvalidNodeType){
  checkInvalidType(TWO, THREE, "setLeftTree");
  ltree = tree;
}

template <typename T>
void TwoThreeNode<T>::setRightTree(TwoThreeNode<T>* tree) throw(InvalidNodeType){
  checkInvalidType(TWO, THREE, "setRightTree");
  rtree = tree;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getTree() const throw(InvalidNodeType){
  checkInvalidType(HOLE, "getTree");
  return ltree;
}

template <typename T>
void TwoThreeNode<T>::setTree(TwoThreeNode<T>* tree) throw(InvalidNodeType){
  checkInvalidType(HOLE, "setTree");
  ltree = tree;
}
