/**
 * @author: Evan Brown
 * @file: EmptyTree.cpp
 * @date: 2/27/19
 * @brief: implementation of EmptyTree exception methods
 */

#include "EmptyTree.hpp"

EmptyTree::EmptyTree(): std::logic_error("Empty Tree"){}
