#include <stdexcept>

template <typename A>
class ValueNotFound: public std::logic_error{

public:

  ValueNotFound(A err_value);
  A getErrValue();
  
private:

  A err_value;

};

#include "ValueNotFound.cpp"
