/**
 * @author: Evan Brown
 * @file: HashTable.cpp
 * @date: 1/31/19
 * @brief: implementation of hash table
 */

#include <iostream>
#include <cmath>

template <typename T>
HashTable<T>::HashTable(int initial_size, int (*hash_function)(const T& value), const CollisionResolution& cr): current(0), size(initial_size), hash_function(hash_function){

  //buckets = new LinkedList<int>[size];

}

template <typename T>
HashTable<T>::~HashTable(){

  //delete[] buckets;

}

template <typename T>
HashTable<T>::HashTable(const HashTable<T>& copy_hash){

  //copyEverything(copy_hash);

}

template <typename T>
HashTable<T>& HashTable<T>::operator=(const HashTable<T>& copy_hash){

  // delete[] buckets;
  // copyEverything(copy_hash);

}

template <typename T>
void HashTable<T>::copyEverything(const HashTable<T>& copy_hash){

  // current = copy_hash.current;
  // size = copy_hash.size;
  // hash_function = copy_hash.hash_function;
  //
  // buckets = new LinkedList<int>[size];
  // for(int i = 0; i < size; i++){
  //   buckets[i] = copy_hash.buckets[i];
  // }

}

template <typename T>
void HashTable<T>::insert(const T& value) throw(DuplicateValue<T>){

  // LinkedList<int>& bucket = buckets[hash(value)];
  //
  // if(bucket.contains(value)){
  //   throw DuplicateValue<T>(value);
  // }
  //
  // bucket.insertFront(value);
  // current++;
  //
  // if(current > size){
  //   rehash();
  // }

}

template <typename T>
void HashTable<T>::deleteVal(const T& value) throw(ValueNotFound<T>){

  // LinkedList<int>& bucket = buckets[hash(value)];
  //
  // if(!bucket.contains(value)){
  //   throw ValueNotFound<T>(value);
  // }
  //
  // bucket.deleteVal(value);
  // current--;

}

template <typename T>
int HashTable<T>::find(const T& value) const throw(ValueNotFound<T>){

  // int hash_val = hash(value);
  //
  // if(!buckets[hash_val].contains(value)){
  //   throw ValueNotFound<T>(value);
  // }
  //
  // return hash_val;

}

template <typename T>
void HashTable<T>::print() const{

  // std::cout << "\nHash contents:\n";
  // for(int i = 0; i < size; i++){
  //   std::cout << i << ":";
  //   buckets[i].print();
  // }

}

template <typename T>
int HashTable<T>::hash(const T& value) const{

  // return hash_function(value)%size;

}

template <typename T>
void HashTable<T>::rehash(){

  // std::cout << "Rehashing table...\n";
  //
  // LinkedList<int>* old_buckets = buckets;
  // int old_size = size;
  //
  // current = 0;
  // size = nextPrime(old_size*2);
  // buckets = new LinkedList<int>[size];
  //
  // for(int i = 0; i < old_size; i++){
  //   while(!old_buckets[i].isEmpty()){
  //     insert(old_buckets[i].popFront());
  //   }
  // }
  //
  // delete[] old_buckets;

}

template <typename T>
int HashTable<T>::nextPrime(int value) const{

  value += (value%2)+1;
  while(!isPrime(value)){
    value += 2;
  }

  return value;

}

template <typename T>
bool HashTable<T>::isPrime(int value) const{

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
