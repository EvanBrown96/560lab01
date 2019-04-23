/**
 * @author: Evan Brown
 * @file: Timer.cpp
 * @date: 2/19/19
 * @brief: implementation of timer wrapper
 *         adapted from 560 lab 4
 */

#include "Timer.hpp"

Timer::Timer(): saved_time(0), last_start(0), is_running(false){

}

void Timer::start(){

  last_start = clock();
  is_running = true;

}

void Timer::stop(){

  if(is_running){
    saved_time = saved_time + clock() - last_start;
    is_running = false;
  }

}

void Timer::reset(){

  saved_time = 0;
  is_running = 0;

}

clock_t Timer::get() const{

  if(is_running){
    return saved_time + clock() - last_start;
  }
  return saved_time;

}

float Timer::getMS() const{
  return static_cast<float>(get())*1000/CLOCKS_PER_SEC;
}
