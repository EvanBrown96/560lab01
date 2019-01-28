/**
 * @author: Evan Brown
 * @file: LinkedList.hpp
 * @date: 1/25/19
 * @brief: header file for linked list
 */

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include "Node.hpp"
#include "exceptions/ValueNotFound.hpp"
#include "exceptions/EmptyList.hpp"

template <typename A>
class LinkedList{

public:

  /**
   * constructor
   * @post: linked list is created with no items
   */
  LinkedList();

  /**
   * copy constructor
   * copies all data from passed-in copy_list to a new list instance
   * does not affect passed-in copy_list
   * @param copy_list: list to copy data from into new list
   * @post: newly created list contains copy of all data from copy_list
   */
  LinkedList(const LinkedList<A>& copy_list);

  /**
   * destructor
   * @post: all nodes of this list are deleted
   */
  ~LinkedList();

  /**
   * assignment operator
   * deletes all data currently in this list, then copies all data from passed-in copy_list to this list
   * does not affect passed-in copy_list
   * @param copy_list: list to copy data from into this list
   * @post: this list contains copy of all data from copy_list
   * @return: reference to this list, for chaining
   */
  LinkedList<A>& operator =(const LinkedList<A>& copy_list);

  /**
   * tells if this list is empty
   * @return: true if list has no elements, false otherwise
   */
  bool isEmpty() const;

  /**
   * inserts a given value at the end of the list
   * @param value: the value to add
   * @post: the given value is added to the end of the list
   */
  void insert(const A& value);

  /**
   * deletes the given value from the list
   * @pre: the value to delete exists in the list
   * @param value: the value to remove
   * @throw ValueNotFound<A>: if the given value does not exist in the list
   * @post: the first instance of the given value found in the list is removed
   */
  void deleteVal(const A& value) throw(ValueNotFound<A>);

  /**
   * finds the smallest value in the list
   * @pre: the list is not empty
   * @throw EmptyList: if the list is empty
   * @return: the smallest value in the list
   */
  A smallest() const throw(EmptyList);

  /**
   * finds the largest value in the list
   * @pre: the list is not empty
   * @throw EmptyList: if the list is empty
   * @return: the largest value in the list
   */
  A largest() const throw(EmptyList);

  /**
   * finds the average of all the values in the list
   * @pre: the list is not empty
   * @throw EmptyList: if the list is empty
   * @return: the average of the values in the list (rounded down, since it is an int)
   */
  A average() const throw(EmptyList);

  /**
   * merges the given list into the current list
   * also sorts the resulting list smallest to largest
   * does not affect the passed-in newlist
   * @param newlist: the list whose values to add to the current list
   * @post: the current list is sorted and has all of the values from newlist added to it
   */
  void merge2lists(const LinkedList<A>& newlist);

  /**
   * prints all of the values currently in the list
   */
  void print() const;

private:

  Node<A>* head;
  Node<A>* tail;

  /**
   * deletes all of the nodes in the list
   * @post: all nodes in list deleted; head is nullptr; tail may be dangling!
   */
  void removeEverything();

  /**
   * copies all the values from copy_list into the current list
   * copy_list is not affected
   * @pre: the current list has no values in it; otherwise these values will be rendered inaccessible
   * @param copy_list: list whose values to copy to the current list
   * @post: the current list contains all of the values from copy_list, in order
   */
  void copyEverything(const LinkedList<A>& copy_list);

  /**
   * adds the given value to the in-progress merge list
   * then removes it from the list passed in operand
   * and updates pointers for the next addition
   * @param operand: the list that "value" came from
   * @param value: the new smallest value to add to the merge list
   * @post: a new node with "value" is created and added to the merge list; value is deleted from the operand list
   */
  void mergeHelper(LinkedList<A>& operand, A& value);

  Node<A>* merge_new_head;
  Node<A>* merge_prev;
  Node<A>* merge_next;


};

#include "LinkedList.cpp"

#endif
