// 4/13

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "MinMax.hpp"
#include "Process.hpp"

class Scheduler{
public:

  Scheduler(const MinMax<Process>& to_run);

  void run();

private:

  MinMax<Process> to_run;

  void printStatus(QuickQueue<Process>& recently_executed, QuickQueue<Process>& recently_completed);

};

#endif
