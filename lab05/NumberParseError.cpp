/**
 * @author: Evan Brown
 * @file: NumberParseError.cpp
 * @date: 1/28/19
 * @brief: implementation of NumberParseError exception methods
 *         adapted from 560 lab02
 */

#include "NumberParseError.hpp"

NumberParseError::NumberParseError(std::istream& stream): std::logic_error("Stream data could not be parsed for integers."), err_pos(stream.tellg()){}

int NumberParseError::getErrPos(){
  return err_pos;
}
