/**
 * @author: Evan Brown
 * @file: HashTable.hpp
 * @date: 1/31/19
 * @brief: header file for hash table
 */

#ifndef HashTable_hpp
#define HashTable_hpp

#include "LinkedList.hpp"
#include "exceptions/DuplicateValue.hpp"
#include "exceptions/ValueNotFound.hpp"

template <typename T>
class HashTable{

public:

  HashTable(int initial_size, int (*hash_function)(const T& value));
  ~HashTable();
  HashTable(const HashTable<T>& copy_hash);
  HashTable<T>& operator=(const HashTable<T>& copy_hash);

  void insert(const T& value) throw(DuplicateValue<T>);
  void deleteVal(const T& value) throw(ValueNotFound<T>);
  int find(const T& value) const throw(ValueNotFound<T>);

  void print() const;

private:

  int hash(const T& value) const;
  void rehash();
  int nextPrime(int value) const;
  bool isPrime(int value) const;
  void copyEverything(const HashTable<T>& copy_hash);

  int current;
  int size;
  int (*hash_function)(const T& value);
  LinkedList<int>* buckets;

};

#include "HashTable.cpp"

#endif
