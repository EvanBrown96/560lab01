/**
 * @author: Evan Brown
 * @file: ClosedHashTable.hpp
 * @date: 3/9/19
 * @brief: header file for hash table
 *         adapted from 560 lab 4
 */

#ifndef CLOSEDHASHTABLE_HPP
#define CLOSEDHASHTABLE_HPP

#include "DuplicateValue.hpp"
#include "ValueNotFound.hpp"
#include "HashElement.hpp"

template <typename K, typename V, typename CR> // doubly templated - key type, item type, and collision resolution subclass
class ClosedHashTable{

public:

  /**
   * constructor
   * @param initial_size: size to make the hash table to start with
   * @param hash_function: function that takes a value to hash and returns the integer hashed value
   *
   * @post: new empty hash table instance created with given initial size and hash function
   */
  ClosedHashTable(int initial_size, int (*hash_function)(const K& value));

  /**
   * destructor
   * @post: all data in hash table is deleted
   */
  ~ClosedHashTable();

  /**
   * copy constructor
   * @param copy_hash: the hash table to make a copy of
   * @post: new hash table created containing copy of all data in copy_hash
   */
  ClosedHashTable(const ClosedHashTable<K, V, CR>& copy_hash);

  /**
   * assignment operator
   * @param copy_hash: the hash table whose data to copy
   * @post: all data currently in the hash table deleted, replaced with copy of all data in copy_hash
   */
  ClosedHashTable<K, V, CR>& operator=(const ClosedHashTable<K, V, CR>& copy_hash);

  /**
   * inserts a value into the hash table
   * computes the hash of the value and inserts it into the front of the corresponding bucket
   * @param value: the value to insert
   * @throw DuplicateValue<T>: if the value being inserted is already in the table
   * @post: the value is added to the hash table
   */
  void insert(const K& key, const V& value) throw(DuplicateValue<K>);

  /**
   * removes a value from the hash table
   * @param value: the value to remove
   * @throw ValueNotFound<T>: if the value to delete is not found in the table
   * @post: the value is removed from the hash table
   */
  void remove(const K& key) throw(ValueNotFound<K>);

  /**
   * finds the location of a value in the hash table
   * if the value is not present, but is present in reverse order, returns that location
   * @param value: the value to find in the hash table
   * @throw ValueNotFound<T>: if the value to find is not in the hash table
   * @return: the bucket index that the value was found in
   */
  V find(const K& key) const throw(ValueNotFound<K>);

  bool isInTable(const K& key) const;

private:

  /**
   * doubles (approximately) the size of the hash table and reinserts all items
   * @post: hash table is doubled in size and all items moved around according to updated hash values
   */
  void rehash();

  /**
   * computes the subsequent prime number to value
   * @param value: the value to start at
   * @return: the first prime number after the value
   */
  int nextPrime(int value) const;

  /**
   * checks if a number is prime or not
   * @param value: the number to check primality of
   * @return: true if the number is prime, false otherwise
   */
  bool isPrime(int value) const;

  /**
   * copies all the data from copy_hash into this hash table
   * @pre: any previous data in the hash table has been deleted (otherwise memory leaks will occur)
   * @param copy_hash: the hash table to copy values from
   * @post: this hash table contains a copy of all the data in copy_hash
   */
  void copyEverything(const ClosedHashTable<K, V, CR>& copy_hash);

  int findLocation(const K& key) const;

  HashElement<K, V>* buckets;
  int current;
  int size;
  int (*hash_function)(const K& value);
  bool do_rehashing;

};

#include "ClosedHashTable.cpp"

#endif
