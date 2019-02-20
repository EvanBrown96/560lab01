/**
 * @author: Evan Brown
 * @file: ClosedHashTable.cpp
 * @date: 2/11/19
 * @brief: implementation of hash table
 *         adapted from 560 lab 3
 */

#include <iostream>
#include <cmath>
// #include "CharacterWrapper.hpp"

template <typename T, typename CR>
ClosedHashTable<T, CR>::ClosedHashTable(int initial_size, int (*hash_function)(const T& value)): current(0), size(initial_size), hash_function(hash_function), do_rehashing(true){

  buckets = new HashElement<T>[size];

}

template <typename T, typename CR>
ClosedHashTable<T, CR>::~ClosedHashTable(){

  delete[] buckets;

}

template <typename T, typename CR>
ClosedHashTable<T, CR>::ClosedHashTable(const ClosedHashTable<T, CR>& copy_hash){

  copyEverything(copy_hash);

}

template <typename T, typename CR>
ClosedHashTable<T, CR>& ClosedHashTable<T, CR>::operator=(const ClosedHashTable<T, CR>& copy_hash){

  delete[] buckets;
  copyEverything(copy_hash);

}

template <typename T, typename CR>
void ClosedHashTable<T, CR>::copyEverything(const ClosedHashTable<T, CR>& copy_hash){

  current = copy_hash.current;
  size = copy_hash.size;
  hash_function = copy_hash.hash_function;

  buckets = new HashElement<T>[size];
  for(int i = 0; i < size; i++){
    buckets[i] = copy_hash.buckets[i];
  }

}

template <typename T, typename CR>
void ClosedHashTable<T, CR>::insert(const T& value) throw(DuplicateValue<T>){

  int hash_val = hash_function(value);
  CR hash_resolver(hash_val);
  int cur_hash = hash_resolver.getNewHash()%size;

  while(buckets[cur_hash].getState() == FULL){
    if(buckets[cur_hash].get() == value){
      throw DuplicateValue<T>(value);
    }

    hash_resolver.next();
    cur_hash = hash_resolver.getNewHash()%size;
  }

  buckets[cur_hash].set(value);
  current++;

  if(do_rehashing && current*2 > size){
    rehash();
  }

}

template <typename T, typename CR>
void ClosedHashTable<T, CR>::deleteVal(const T& value) throw(ValueNotFound<T>){

  buckets[find(value)].remove();
  current--;

}

template <typename T, typename CR>
int ClosedHashTable<T, CR>::find(const T& value) const throw(ValueNotFound<T>){

  int hash_val = hash_function(value);
  CR hash_resolver(hash_val);
  int cur_hash = hash_resolver.getNewHash()%size;

  while(buckets[cur_hash].getState() != EMPTY){
    if(buckets[cur_hash].getState() == FULL && buckets[cur_hash].get() == value){
      return cur_hash;
    }

    hash_resolver.next();
    cur_hash = hash_resolver.getNewHash()%size;
  }

  throw ValueNotFound<T>(value);

}

// template <typename T, typename CR>
// int ClosedHashTable<T, CR>::findReverse(const T& value) const throw(ValueNotFound<T>){
//
//   CharacterWrapper cw = CharacterWrapper::getReverse(value);
//
//   int hash_val = hash_function(value);
//   CR hash_resolver(hash_val);
//   int cur_hash = hash_resolver.getNewHash()%size;
//
//   while(buckets[cur_hash].getState() != EMPTY){
//     if(buckets[cur_hash].getState() == FULL && buckets[cur_hash].get() == cw){
//       return cur_hash;
//     }
//
//     hash_resolver.next();
//     cur_hash = hash_resolver.getNewHash()%size;
//   }
//
//   throw ValueNotFound<T>(value);
//
// }

// template <typename T, typename CR>
// void ClosedHashTable<T, CR>::findPalindromes() const{
//
//   std::cout << "Palindrome strings: ";
//
//   for(int i = 0; i < size; i++){
//     if(buckets[i].getState() == FULL){
//       CharacterWrapper cw = buckets[i].get();
//       CharacterWrapper cw2 = CharacterWrapper::getReverse(cw);
//       if(hash_function(cw) == hash_function(cw2)){
//         std::cout << cw << " ";
//       }
//     }
//   }
//
//   std::cout << "\n";
//
// }
//
// template <typename T, typename CR>
// void ClosedHashTable<T, CR>::reverseString(int location) throw(EmptyLocation){
//
//   if(location < 0 || location >= size){
//     throw EmptyLocation();
//   }
//
//   if(buckets[location].getState() != FULL){
//     throw EmptyLocation();
//   }
//
//   CharacterWrapper cw = buckets[location].get();
//   CharacterWrapper cw2 = CharacterWrapper::getReverse(cw);
//   buckets[location].set(cw2);
//
// }

template <typename T, typename CR>
T ClosedHashTable<T, CR>::getByLocation(int location) throw(EmptyLocation){

  if(location < 0 || location >= size){
    throw EmptyLocation();
  }

  return buckets[location].get();

}

template <typename T, typename CR>
void ClosedHashTable<T, CR>::print() const{

  for(int i = 0; i < size; i++){
    std::cout << i << ": ";
    if(buckets[i].getState() == FULL){
      std::cout << buckets[i].get();
    }
    std::cout << "\n";
  }

}

template <typename T, typename CR>
void ClosedHashTable<T, CR>::disableRehashing(){
  do_rehashing = false;
}

template <typename T, typename CR>
void ClosedHashTable<T, CR>::enableRehashing(){
  do_rehashing = true;
}

template <typename T, typename CR>
void ClosedHashTable<T, CR>::rehash(){

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
int ClosedHashTable<T, CR>::nextPrime(int value) const{

  value += (value%2)+1;
  while(!isPrime(value)){
    value += 2;
  }

  return value;

}

template <typename T, typename CR>
bool ClosedHashTable<T, CR>::isPrime(int value) const{

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
