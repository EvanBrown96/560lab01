/**
 * @author: Evan Brown
 * @file: FullStructure.hpp
 * @date: 2/27/19
 * @brief: header file defining exception signifying an invalid operation was attempted on an empty data structure.
 */

#ifndef FULLSTRUCTURE_HPP
#define FULLSTRUCTURE_HPP

#include <stdexcept>

class FullStructure: public std::logic_error{

public:

  /**
   * constructor
   */
  FullStructure();

};

#endif
