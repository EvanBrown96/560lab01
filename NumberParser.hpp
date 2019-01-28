#ifndef NumberParser_hpp
#define NumberParser_hpp

#include <istream>
#include "LinkedList.hpp"

class NumberParser{
public:
  static void parse(std::istream& stream, LinkedList<int>& ll);
};

#endif
