/**
 * @author: Evan Brown
 * @file: EmptyStructure.cpp
 * @date: 2/27/19
 * @brief: implementation of EmptyStructure exception methods
 *         adapted from 560 lab 9
 */

#include "EmptyStructure.hpp"

EmptyStructure::EmptyStructure(): std::logic_error("Empty Structure"){}
