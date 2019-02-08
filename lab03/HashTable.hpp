/**
 * @author: Evan Brown
 * @file: HashTable.hpp
 * @date: 1/31/19
 * @brief: header file for hash table
 */

#ifndef HashTable_hpp
#define HashTable_hpp

#include "DuplicateValue.hpp"
#include "ValueNotFound.hpp"
#include "EmptyLocation.hpp"
#include "CollisionResolution.hpp"
#include "HashElement.hpp"

template <typename T, typename CR> // doubly templated - type stored in hash table and collision resolution subclass
class HashTable{

public:

  /**
   * constructor
   * @param initial_size: size to make the hash table to start with
   * @param hash_function: function that takes a value to hash and returns the integer hashed value
   *
   * @post: new empty hash table instance created with given initial size and hash function
   */
  HashTable(int initial_size, int (*hash_function)(const T& value));

  /**
   * destructor
   * @post: all data in hash table is deleted
   */
  ~HashTable();

  /**
   * copy constructor
   * @param copy_hash: the hash table to make a copy of
   * @post: new hash table created containing copy of all data in copy_hash
   */
  HashTable(const HashTable<T, CR>& copy_hash);

  /**
   * assignment operator
   * @param copy_hash: the hash table whose data to copy
   * @post: all data currently in the hash table deleted, replaced with copy of all data in copy_hash
   */
  HashTable<T, CR>& operator=(const HashTable<T, CR>& copy_hash);

  /**
   * inserts a value into the hash table
   * computes the hash of the value and inserts it into the front of the corresponding bucket
   * @param value: the value to insert
   * @throw DuplicateValue<T>: if the value being inserted is already in the table
   * @post: the value is added to the hash table
   */
  void insert(const T& value) throw(DuplicateValue<T>);

  /**
   * removes a value from the hash table
   * @param value: the value to remove
   * @throw ValueNotFound<T>: if the value to delete is not found in the table
   * @post: the value is removed from the hash table
   */
  void deleteVal(const T& value) throw(ValueNotFound<T>);

  /**
   * finds the location of a value in the hash table
   * if the value is not present, but is present in reverse order, returns that location
   * @param value: the value to find in the hash table
   * @throw ValueNotFound<T>: if the value to find is not in the hash table
   * @return: the bucket index that the value was found in
   */
  int find(const T& value) const throw(ValueNotFound<T>);

  /**
   * finds all of the palidrome strings in the hash table
   * and prints them out
   */
  void findPalindromes() const;

  /**
   * reverses the string present in "location" and rehashes it
   * @param location: the location to reverse the string at
   * @throw EmptyLocation: if the location to reverse the string at is empty
   * @post: the string at the given location was reversed and re-inserted into the table
   */
  void reverseString(int location) throw(EmptyLocation);

  /**
   * prints all of the contents of the hash table
   */
  void print() const;

private:

  /**
   * computes the hash function for a value and fits it to the table size
   * @param value: the value to compute the hash of
   * @return: the bucket index the value corresponds to
   */
  int hash(const T& value) const;

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
  void copyEverything(const HashTable<T, CR>& copy_hash);

  HashElement<T>* buckets;
  int current;
  int size;
  int (*hash_function)(const T& value);

};

#include "HashTable.cpp"

#endif
