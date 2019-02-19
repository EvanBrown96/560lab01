/**
 * @author: Evan Brown
 * @file: HashElement.hpp
 * @date: 2/8/19
 * @brief: specification of hash element class
 *         adapted from 560 lab 3
 */

#ifndef HashElement_hpp
#define HashElement_hpp

enum HashStates {EMPTY, FULL, REMOVED};

template <typename T>
class HashElement{

public:

  HashElement();
  ~HashElement();
  HashElement(const HashElement<T>& copy_elem);
  HashElement<T>& operator=(const HashElement<T>& copy_elem);

  void set(const T& value);
  T get() const throw(EmptyLocation);
  void remove() throw(EmptyLocation);

  enum HashStates getState() const;

private:

  enum HashStates state;
  T* value;

};

#include "HashElement.cpp"

#endif
