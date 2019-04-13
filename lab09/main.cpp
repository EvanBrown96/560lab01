#include "MinMax.hpp"
#include "UserInput.hpp"

int main(int argc, char** argv){
  MinMax<Process> mm;
  // mm.insert(12);
  // mm.insert(25);
  // mm.insert(2);
  // mm.insert(11);
  // mm.insert(22);
  // mm.insert(111);
  // mm.insert(17);

  UserInput ui(mm);
  ui.start();
}
