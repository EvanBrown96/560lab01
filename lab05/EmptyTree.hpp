/**
 * @author: Evan Brown
 * @file: EmptyTree.hpp
 * @date: 2/27/19
 * @brief: header file defining exception signifying an invalid operation was attempted on an empty tree.
 */

#ifndef EMPTYTREE_HPP
#define EMPTYTREE_HPP

#include <stdexcept>

class EmptyTree: public std::logic_error{

public:

  /**
   * constructor
   */
  EmptyTree();

};

#endif
