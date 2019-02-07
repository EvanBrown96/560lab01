/**
 * @author: Evan Brown
 * @file: EmptyList.cpp
 * @date: 1/26/19
 * @brief: implementation of EmptyList exception methods
 */

#include "EmptyLocation.hpp"

EmptyLocation::EmptyLocation(): std::logic_error("Empty Location"){}
