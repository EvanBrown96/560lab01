/**
 * @author: Evan Brown
 * @file: HashTable.hpp
 * @date: 1/31/19
 * @brief: header file for hash table
 */

#ifndef HashTable_hpp
#define HashTable_hpp

#include "LinkedList.hpp"

template <typename T>
class HashTable{

public:

  HashTable(int initial_size, int (*hash_function)(const T& value));
  ~HashTable();
  HashTable(const HashTable<T>& copy_hash);
  HashTable<T>& operator=(const HashTable<T>& copy_hash);

  void insert(const T& value); // throw duplicatevalue
  void deleteVal(const T& value); // throw valuenotfound
  int find(const T& value) const; // throw valuenotfound

  void print() const;

private:

  int hash(const T& value) const;
  void rehash();
  void copyEverything(const HashTable<T>& copy_hash);

  int size;
  int (*hash_function)(const T& value);
  LinkedList<int>* buckets;

};

#include "HashTable.cpp"

#endif
