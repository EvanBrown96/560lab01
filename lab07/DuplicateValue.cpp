/**
 * @author: Evan Brown
 * @file: DuplicateValue.cpp
 * @date: 2/1/19
 * @brief: implementation of DuplicateValue exception
 *         adapted from 560 lab 6
 */

template <typename A>
DuplicateValue<A>::DuplicateValue(A err_value): std::logic_error("Duplicate Value"), err_value(err_value){}

template <typename A>
A DuplicateValue<A>::getErrValue() const{
  return err_value;
}
