/**
 * @author: Evan Brown
 * @file: EmptyLocation.hpp
 * @date: 2/5/19
 * @brief: header file defining exception signifying a location in the hash table was empty
 */

#ifndef EmptyLocation_hpp
#define EmptyLocation_hpp

#include <stdexcept>

class EmptyLocation: public std::logic_error{

public:

  /**
   * constructor
   */
  EmptyLocation();

};

#endif
