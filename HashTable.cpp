template <typename T>
HashTable<T>::HashTable(int initial_size, int (*hash_function)(const T& value)): hash_function(hash_function){

  buckets = new LinkedList<int>[initial_size];

}

template <typename T>
HashTable<T>::~HashTable(){

  delete[] buckets;

}

template <typename T>
HashTable<T>::HashTable(const HashTable<T>& copy_hash){

}

template <typename T>
HashTable<T>& HashTable<T>::operator=(const HashTable<T>& copy_hash){

}

template <typename T>
void HashTable<T>::insert(const T& value){ // throw duplicatevalue

}

template <typename T>
void HashTable<T>::deleteVal(const T& value){ // throw valuenotfound

}

template <typename T>
int HashTable<T>::find(const T& value){ // throw valuenotfound

}

template <typename T>
int HashTable<T>::hash(const T& value){

}

template <typename T>
void HashTable<T>::rehash(){

}
