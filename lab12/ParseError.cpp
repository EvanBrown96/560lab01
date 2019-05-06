/**
 * @author: Evan Brown
 * @file: ParseError.cpp
 * @date: 2/11/19
 * @brief: implementation of ParseError exception methods
 *         adapted from 560 lab 7
 */

#include "ParseError.hpp"

ParseError::ParseError(std::istream& stream): std::logic_error("Stream data could not be parsed."), err_pos(stream.tellg()){}

int ParseError::getErrPos(){
  return err_pos;
}
