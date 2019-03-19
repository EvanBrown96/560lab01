#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP

template <typename T>
void swap(T** a, T** b){
  T* x = *a;
  *a = *b;
  *b = x;
}

template <typename T>
void quicksort(T** arr, int length){
  if(length < 2) return;

  int larger = 1;

  for(int i = 1; i < length; i++){
    if(*arr[i] < *arr[0]){
      swap(arr+i, arr+larger);
      larger++;
    }
  }

  swap(arr, arr+larger-1);
  quicksort(arr, larger-1);
  quicksort(arr+larger, length-larger);
}

#endif
