/**
 * @author: Evan Brown
 * @file: InvalidNodeType.cpp
 * @date: 3/25/19
 * @brief: implementation of exception for invalid node type
 */

#include "InvalidNodeType.hpp"

InvalidNodeType::InvalidNodeType(const char* msg): std::logic_error(msg){}
