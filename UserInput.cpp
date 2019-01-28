/**
 * @author: Evan Brown
 * @file: UserInput.cpp
 * @date: 1/26/19
 * @brief: implementation of UserInput functions
 */

#include "UserInput.hpp"
#include <iostream>
#include <limits>

void UserInput::clearCin(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UserInput::start(){

  choice = 0;

  while(true){

    std::cout << "Choose one operation from the options below:\n\n";
    std::cout << "\t1. Insert\n";
    std::cout << "\t2. Delete\n";
    std::cout << "\t3. Find smallest number\n";
    std::cout << "\t4. Find largest number\n";
    std::cout << "\t5. Average of numbers\n";
    std::cout << "\t6. Merge2Lists\n";
    std::cout << "\t7. Print\n";
    std::cout << "\t8. Exit\n";

    while(!(std::cin >> choice && choice > 0 && choice < 9)){
      clearCin();
      std::cout << "Invalid choice, try again: ";
    }

    if(choice == 8){
      break;
    }

    switch(choice){
      case 1: {
        userInsert();
        break;
      }
      case 2: {
        userDelete();
        break;
      }
      case 3: {
        userSmallest();
        break;
      }
      case 4: {
        userLargest();
        break;
      }
      case 5: {
        userAverage();
        break;
      }
      case 6: {
        userMerge();
        break;
      }
      default: {
        ll.print();
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::userInsert(){

  std::cout << "Enter number to insert: ";
  if(std::cin >> choice){
    ll.insert(choice);
  }
  else{
    clearCin();
    std::cout << "Invalid number entered.\n";
  }

}

void UserInput::userDelete(){

  std::cout << "Enter number to be deleted: ";
  if(std::cin >> choice){
    try{
      ll.deleteVal(choice);
      std::cout << "Delete was successful.\n";
    }
    catch(ValueNotFound<int>& err){
      std::cout << "Delete failed. Number was not found in the list\n";
    }
  }
  else{
    clearCin();
    std::cout << "Invalid number entered.\n";
  }

}

void UserInput::userSmallest(){

  try{
    choice = ll.smallest();
    std::cout << "Smallest number: " << choice << "\n";
  }
  catch(EmptyList& err){
    std::cout << "List is empty, so it has no smallest number.\n";
  }

}

void UserInput::userLargest(){

  try{
    choice = ll.largest();
    std::cout << "Largest number: " << choice << "\n";
  }
  catch(EmptyList& err){
    std::cout << "List is empty, so it has no largest number.\n";
  }

}

void UserInput::userAverage(){

  try{
    choice = ll.average();
    std::cout << "Average: " << choice << "\n";
  }
  catch(EmptyList& err){
    std::cout << "List is empty, so it has no average.\n";
  }

}

void UserInput::userMerge(){

  std::cout << "Enter new list to be merged:\n";

  // clear any previous stuff in input buffer
  clearCin();

  char res;
  int cur;
  LinkedList<int> temp;
  bool is_neg;

  // get first character of input
  std::cin.get(res);

  // repeat until reach end of line
  while(res != '\n'){

    // reset current value
    choice = 0;
    // throw out any whitespace before next number
    while(res == ' ' || res == '\t'){
      std::cin.get(res);
    }

    // check if first character of input is a minus sign
    is_neg = false;
    if(res == '-'){
      is_neg = true;
      std::cin.get(res);
    }

    // repeat until we reach space again
    while(res != ' ' && res != '\t' && res != '\n'){

      // get integer value of current character
      cur = static_cast<int>(res) - 48;
      // if the character is not a number, exit function
      if(cur < 0 || cur > 9){
        std::cout << "Invalid number entered.\n";
        // clear rest of input so it doesn't interfere with subsequent operations
        clearCin();
        return;
      }

      // update current value with the most recent character
      choice *= 10;
      choice += cur;

      // get next character
      std::cin.get(res);

    }

    // add the current value to the linked list
    temp.insert(is_neg ? (-1)*choice : choice);

  }

  // merge the existing linked list with the entered linked list
  ll.merge2lists(temp);

}
