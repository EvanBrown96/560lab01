template <typename T>
Traversal<T>::Traversal(): values(nullptr), size(0){}

template <typename T>
Traversal<T>::~Traversal(){
  if(values != nullptr){
    for(int i = 0; i < size; i++){
      delete values[i];
    }
    delete[] values;
  }
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Traversal<T>& t){

  for(int i = 0; i < t.size; i++){
    stream << *t.values[i] << " ";
  }
  stream << "\n";

  return stream;

}
