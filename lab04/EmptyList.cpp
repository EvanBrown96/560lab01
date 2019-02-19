/**
 * @author: Evan Brown
 * @file: EmptyList.cpp
 * @date: 1/26/19
 * @brief: implementation of EmptyList exception methods
 *         adapted from 560 lab 2
 */

#include "EmptyList.hpp"

EmptyList::EmptyList(): std::logic_error("Empty List"){}
