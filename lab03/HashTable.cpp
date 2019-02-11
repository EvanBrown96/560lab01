/**
 * @author: Evan Brown
 * @file: HashTable.cpp
 * @date: 2/11/19
 * @brief: implementation of hash table
 */

#include <iostream>
#include <cmath>

template <typename T, typename CR>
HashTable<T, CR>::HashTable(int initial_size, int (*hash_function)(const T& value)): current(0), size(initial_size), hash_function(hash_function){

  buckets = new HashElement<T>[size];

}

template <typename T, typename CR>
HashTable<T, CR>::~HashTable(){

  delete[] buckets;

}

template <typename T, typename CR>
HashTable<T, CR>::HashTable(const HashTable<T, CR>& copy_hash){

  copyEverything(copy_hash);

}

template <typename T, typename CR>
HashTable<T, CR>& HashTable<T, CR>::operator=(const HashTable<T, CR>& copy_hash){

  delete[] buckets;
  copyEverything(copy_hash);

}

template <typename T, typename CR>
void HashTable<T, CR>::copyEverything(const HashTable<T, CR>& copy_hash){

  current = copy_hash.current;
  size = copy_hash.size;
  hash_function = copy_hash.hash_function;

  buckets = new HashElement<T>[size];
  for(int i = 0; i < size; i++){
    buckets[i] = copy_hash.buckets[i];
  }

}

template <typename T, typename CR>
void HashTable<T, CR>::insert(const T& value) throw(DuplicateValue<T>){

  int hash_val = hash(value);
  CR hash_resolver(hash_val);
  HashElement<T>& cur_elem = buckets[hash_resolver.getNewHash()];

  while(cur_elem.getState() == FULL){
    if(cur_elem.get() == value){
      throw DuplicateValue<T>(value);
    }

    hash_resolver.next();
    cur_elem = buckets[hash_resolver.getNewHash()];
  }

  cur_elem.set(value);
  current++;

  if(current*2 > size){
    rehash();
  }

}

template <typename T, typename CR>
void HashTable<T, CR>::deleteVal(const T& value) throw(ValueNotFound<T>){

  buckets[find(value)].remove();
  current--;

}

template <typename T, typename CR>
int HashTable<T, CR>::find(const T& value) const throw(ValueNotFound<T>){

  int hash_val = hash(value);
  CR hash_resolver(hash_val);
  HashElement<T>& cur_elem = buckets[hash_resolver.getNewHash()];

  while(cur_elem.getState() != EMPTY){
    if(cur_elem.getState() == FULL && cur_elem.get() == value){
      return hash_resolver.getNewHash();
    }

    hash_resolver.next();
    cur_elem = buckets[hash_resolver.getNewHash()];
  }

  throw ValueNotFound<T>(value);

}

template <typename T, typename CR>
void HashTable<T, CR>::findPalindromes() const{

}

template <typename T, typename CR>
void HashTable<T, CR>::reverseString(int location) throw(EmptyLocation){

}

template <typename T, typename CR>
void HashTable<T, CR>::print() const{

  std::cout << "\nHash contents:\n";
  for(int i = 0; i < size; i++){
    std::cout << i << ": ";
    if(buckets[i].getState() == FULL){
      std::cout << buckets[i].get();
    }
    std::cout << "\n";
  }

}

template <typename T, typename CR>
int HashTable<T, CR>::hash(const T& value) const{

  return hash_function(value)%size;

}

template <typename T, typename CR>
void HashTable<T, CR>::rehash(){

  std::cout << "Rehashing table...\n";

  HashElement<T>* old_buckets = buckets;
  int old_size = size;

  current = 0;
  size = nextPrime(old_size*2);
  buckets = new HashElement<T>[size];

  for(int i = 0; i < old_size; i++){
    if(old_buckets[i].getState() == FULL){
      insert(old_buckets[i].get());
    }
  }

  delete[] old_buckets;

}

template <typename T, typename CR>
int HashTable<T, CR>::nextPrime(int value) const{

  value += (value%2)+1;
  while(!isPrime(value)){
    value += 2;
  }

  return value;

}

template <typename T, typename CR>
bool HashTable<T, CR>::isPrime(int value) const{

  if(value%2 == 0){
    return false;
  }
  for(int i = 3; i < std::sqrt(value)+1; i+=2){
    if(value%i == 0){
      return false;
    }
  }

  return true;

}
