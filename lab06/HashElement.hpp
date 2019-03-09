/**
 * @author: Evan Brown
 * @file: HashElement.hpp
 * @date: 2/8/19
 * @brief: specification of hash element class
 *         adapted from 560 lab 3
 */

#ifndef HASHELEMENT_HPP
#define HASHELEMENT_HPP

#include "EmptyStructure.hpp"

enum HashStates {EMPTY, FULL, REMOVED};

template <typename T>
class HashElement{

public:

  HashElement();
  ~HashElement();
  HashElement(const HashElement<T>& copy_elem);
  HashElement<T>& operator=(const HashElement<T>& copy_elem);

  void set(const T& value);
  T get() const throw(EmptyStructure);
  void remove() throw(EmptyStructure);

  enum HashStates getState() const;

private:

  enum HashStates state;
  T* value;

};

#include "HashElement.cpp"

#endif
