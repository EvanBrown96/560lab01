/**
 * @author: Evan Brown
 * @file: Timer.hpp
 * @date: 2/19/19
 * @brief: header file for timing wrapper
 */

#ifndef Timer_hpp
#define Timer_hpp

#include <time.h>

class Timer{

public:

  Timer();

  void start();

  void stop();

  void reset();

  clock_t get() const;

private:

  clock_t saved_time;
  clock_t last_start;
  bool is_running;

};

#endif
