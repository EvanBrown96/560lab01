/**
 * @author: Evan Brown
 * @file: ValueNotFound.cpp
 * @date: 1/26/19
 * @brief: implementation of ValueNotFound exception
 */

template <typename A>
ValueNotFound<A>::ValueNotFound(A err_value): std::logic_error("Value Not Found"), err_value(err_value){}

template <typename A>
A ValueNotFound<A>::getErrValue() const{
  return err_value;
}
