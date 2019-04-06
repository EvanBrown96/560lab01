#include "Heap.hpp"

bool compare(const int& v1, const int& v2){
  return (v1 < v2);
}

int main(int argc, char** argv){
  Heap<5, int> h(compare);

}
