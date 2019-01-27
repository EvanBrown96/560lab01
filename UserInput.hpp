#include "LinkedList.hpp"

class UserInput{

public:

  void start();

private:

  int choice;
  LinkedList<int> ll;

  void clearCin();
  void userInsert();
  void userDelete();
  void userSmallest();
  void userLargest();
  void userAverage();
  void userMerge();

};
