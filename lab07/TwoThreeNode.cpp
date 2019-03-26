template <typename T>
enum NodeType TwoThreeNode<T>::getType() const{
  return ntype;
}

template <typename T>
void TwoThreeNode<T>::checkInvalidType(enum NodeType safe) const throw(InvalidNodeType){
  if(ntype != safe) throw InvalidNodeType();
}

template <typename T>
void TwoThreeNode<T>::checkInvalidType(enum NodeType safe, enum NodeType safe2) const throw(InvalidNodeType){
  if(ntype != safe && ntype != safe2) throw InvalidNodeType();
}

template <typename T>
TwoThreeNode<T>::TwoThreeNode(const T& value):
  ntype(TWO), lvalue(value), ltree(nullptr), mtree(nullptr), rtree(nullptr){}

template <typename T>
TwoThreeNode<T>::TwoThreeNode(const T& lvalue, const T& rvalue):
  ntype(THREE), lvalue(lvalue), rvalue(rvalue), ltree(nullptr), mtree(nullptr), rtree(nullptr){}

template <typename T>
T TwoThreeNode<T>::getVal() const throw(InvalidNodeType){
  checkInvalidType(TWO);
  return lvalue;
}

template <typename T>
void TwoThreeNode<T>::setVal(const T& value) throw(InvalidNodeType){
  checkInvalidType(TWO);
  lvalue = value;
}

template <typename T>
void TwoThreeNode<T>::absorbLeftKickUp() throw(InvalidNodeType, EmptyStructure){
  if(ltree == nullptr) throw EmptyStructure();
  if(ltree->ntype != TWO) throw InvalidNodeType();

  if(ntype == TWO){
    ntype = THREE;

    TwoThreeNode<T>* save = ltree;
    rvalue = lvalue;
    lvalue = save->lvalue;
    mtree = save->rtree;
    ltree = save->ltree;
    delete save;
  }
  else{
    ntype = TWO;

    TwoThreeNode<T>* rnew = new TwoThreeNode<T>(rvalue);
    rnew->ltree = mtree;
    rnew->rtree = rtree;

    rtree = rnew;
  }
}

template <typename T>
void TwoThreeNode<T>::absorbRightKickUp() throw(InvalidNodeType, EmptyStructure){
  if(rtree == nullptr) throw EmptyStructure();
  if(rtree->ntype != TWO) throw InvalidNodeType();

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
  }

}

template <typename T>
void TwoThreeNode<T>::absorbMiddleKickUp() throw(InvalidNodeType, EmptyStructure){
  if(mtree == nullptr) throw EmptyStructure();
  if(ntype != THREE || mtree->ntype != TWO) throw InvalidNodeType();

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
T TwoThreeNode<T>::getLeftVal() const throw(InvalidNodeType){
  checkInvalidType(THREE);
  return lvalue;
}

template <typename T>
T TwoThreeNode<T>::getRightVal() const throw(InvalidNodeType){
  checkInvalidType(THREE);
  return rvalue;
}

template <typename T>
void TwoThreeNode<T>::setLeftVal(const T& value) throw(InvalidNodeType){
  checkInvalidType(THREE);
  lvalue = value;
}

template <typename T>
void TwoThreeNode<T>::setRightVal(const T& value) throw(InvalidNodeType){
  checkInvalidType(THREE);
  rvalue = value;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getMiddleTree() const throw(InvalidNodeType){
  checkInvalidType(THREE);
  return mtree;
}

template <typename T>
void TwoThreeNode<T>::setMiddleTree(TwoThreeNode<T>* tree) throw(InvalidNodeType){
  checkInvalidType(THREE);
  mtree = tree;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getLeftTree() const throw(InvalidNodeType){
  checkInvalidType(TWO, THREE);
  return ltree;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getRightTree() const throw(InvalidNodeType){
  checkInvalidType(TWO, THREE);
  return rtree;
}

template <typename T>
void TwoThreeNode<T>::setLeftTree(TwoThreeNode<T>* tree) throw(InvalidNodeType){
  checkInvalidType(TWO, THREE);
  ltree = tree;
}

template <typename T>
void TwoThreeNode<T>::setRightTree(TwoThreeNode<T>* tree) throw(InvalidNodeType){
  checkInvalidType(TWO, THREE);
  rtree = tree;
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getTree() const throw(InvalidNodeType){
  checkInvalidType(HOLE);
  return ltree;
}

template <typename T>
void TwoThreeNode<T>::setTree(TwoThreeNode<T>* tree) throw(InvalidNodeType){
  checkInvalidType(HOLE);
  ltree = tree;
}
