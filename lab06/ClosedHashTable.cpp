/**
 * @author: Evan Brown
 * @file: ClosedHashTable.cpp
 * @date: 2/11/19
 * @brief: implementation of hash table
 *         adapted from 560 lab 4
 */

#include <iostream>
#include <cmath>

template <typename K, typename V, typename CR>
ClosedHashTable<K, V, CR>::ClosedHashTable(int initial_size, int (*hash_function)(const K& value)): current(0), size(initial_size), hash_function(hash_function), do_rehashing(true){

  buckets = new HashElement<K, V>[size];

}

template <typename K, typename V, typename CR>
ClosedHashTable<K, V, CR>::~ClosedHashTable(){

  delete[] buckets;

}

template <typename K, typename V, typename CR>
ClosedHashTable<K, V, CR>::ClosedHashTable(const ClosedHashTable<K, V, CR>& copy_hash){

  copyEverything(copy_hash);

}

template <typename K, typename V, typename CR>
ClosedHashTable<K, V, CR>& ClosedHashTable<K, V, CR>::operator=(const ClosedHashTable<K, V, CR>& copy_hash){

  delete[] buckets;
  copyEverything(copy_hash);

}

template <typename K, typename V, typename CR>
void ClosedHashTable<K, V, CR>::copyEverything(const ClosedHashTable<K, V, CR>& copy_hash){

  current = copy_hash.current;
  size = copy_hash.size;
  hash_function = copy_hash.hash_function;

  buckets = new HashElement<K, V>[size];
  for(int i = 0; i < size; i++){
    buckets[i] = copy_hash.buckets[i];
  }

}

template <typename K, typename V, typename CR>
void ClosedHashTable<K, V, CR>::insert(const K& key, const V& value) throw(DuplicateValue<K>){

  int hash_val = hash_function(key);
  CR hash_resolver(hash_val);
  int cur_hash = hash_resolver.getNewHash()%size;

  while(buckets[cur_hash].getState() == FULL){
    if(buckets[cur_hash].getKey() == key){
      throw DuplicateValue<K>(key);
    }

    hash_resolver.next();
    cur_hash = hash_resolver.getNewHash()%size;
  }

  buckets[cur_hash].set(key, value);
  current++;

  if(current*2 > size){
    rehash();
  }

}

template <typename K, typename V, typename CR>
void ClosedHashTable<K, V, CR>::remove(const K& key) throw(ValueNotFound<K>){

  int loc = findLocation(key);
  if(loc < 0) throw(ValueNotFound<K>(key));

  buckets[loc].remove();
  current--;

}


template <typename K, typename V, typename CR>
V ClosedHashTable<K, V, CR>::find(const K& key) const throw(ValueNotFound<K>){

  int loc = findLocation(key);
  if(loc < 0) throw(ValueNotFound<K>(key));

  return buckets[loc].get();

}

template <typename K, typename V, typename CR>
int ClosedHashTable<K, V, CR>::findLocation(const K& key) const{

  int hash_val = hash_function(key);
  CR hash_resolver(hash_val);
  int cur_hash = hash_resolver.getNewHash()%size;

  while(buckets[cur_hash].getState() != EMPTY){
    if(buckets[cur_hash].getState() == FULL && buckets[cur_hash].getKey() == key){
      return cur_hash;
    }

    hash_resolver.next();
    cur_hash = hash_resolver.getNewHash()%size;
  }

  return -1;

}

template <typename K, typename V, typename CR>
void ClosedHashTable<K, V, CR>::rehash(){

  HashElement<K, V>* old_buckets = buckets;
  int old_size = size;

  current = 0;
  size = nextPrime(old_size*2);
  buckets = new HashElement<K, V>[size];

  for(int i = 0; i < old_size; i++){
    if(old_buckets[i].getState() == FULL){
      insert(old_buckets[i].getKey(), old_buckets[i].get());
    }
  }

  delete[] old_buckets;

}

template <typename K, typename V, typename CR>
int ClosedHashTable<K, V, CR>::nextPrime(int value) const{

  value += (value%2)+1;
  while(!isPrime(value)){
    value += 2;
  }

  return value;

}

template <typename K, typename V, typename CR>
bool ClosedHashTable<K, V, CR>::isPrime(int value) const{

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
