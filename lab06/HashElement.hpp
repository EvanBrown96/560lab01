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

template <typename K, typename V>
class HashElement{

public:

  HashElement();
  ~HashElement();
  HashElement(const HashElement<K, V>& copy_elem);
  HashElement<K, V>& operator=(const HashElement<K, V>& copy_elem);

  void set(const K& key, const V& value);
  V get() const throw(EmptyStructure);
  K getKey() const throw(EmptyStructure);
  void remove() throw(EmptyStructure);

  enum HashStates getState() const;

private:

  enum HashStates state;
  K* key;
  V* value;

};

#include "HashElement.cpp"

#endif
