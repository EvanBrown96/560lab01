// 4/13

#include "Scheduler.hpp"
#include "QuickQueue.hpp"
#include <iostream>

Scheduler::Scheduler(const MinMax<Process>& to_run):
  to_run(to_run){}

void Scheduler::run(){

  std::cout << "Initial Minmax heap:\n";
  to_run.levelOrder();

  std::cout << "Scheduling output:\n";

  int interval = 1;
  int time_left;

  QuickQueue<Process> scheduler_order(10);
  QuickQueue<Process> recently_completed(10);
  QuickQueue<Process> recently_executed(10);

  try{
    while(true){
      // high priority interval
      std::cout << "T" << interval << ": 20ms\n";
      time_left = 20;
      while(time_left > 0){

        Process& cur = to_run.getActualMin();
        recently_executed.push(cur);
        if(time_left >= cur.time_left){
          std::cout << cur << "(" << cur.priority << ",0), ";
          time_left -= cur.time_left;
          recently_completed.push(cur);
          scheduler_order.push(cur);
          to_run.deleteMin();
        }
        else{
          cur.time_left -= time_left;
          std::cout << cur << "(" << cur.priority << "," << cur.time_left << "), ";
          time_left = 0;
        }

      }

      to_run.findMin();
      printStatus(recently_executed, recently_completed);
      interval++;

      // low priority interval
      std::cout << "T" << interval << ": 10ms\n";
      time_left = 10;
      while(time_left > 0){

        Process& cur = to_run.getActualMax();
        recently_executed.push(cur);
        if(time_left >= cur.time_left){
          std::cout << cur << "(" << cur.priority << ",0), ";
          time_left -= cur.time_left;
          recently_completed.push(cur);
          scheduler_order.push(cur);
          to_run.deleteMax();
        }
        else{
          cur.time_left -= time_left;
          std::cout << cur << "(" << cur.priority << "," << cur.time_left << "), ";
          time_left = 0;
        }
      }

      to_run.findMin();
      printStatus(recently_executed, recently_completed);
      interval++;

    }
  }
  catch(EmptyStructure& err){} // expected exception when heap ran out of processes.

  printStatus(recently_executed, recently_completed);

  std::cout << "Scheduling Order:\n";

  while(!scheduler_order.isEmpty()) std::cout << scheduler_order.pop() << " ";

  std::cout << "\n\n--------------------------------------------------------\n";

}

void Scheduler::printStatus(QuickQueue<Process>& recently_executed, QuickQueue<Process>& recently_completed){

  std::cout << "\n" << recently_executed.pop();
  while(!recently_executed.isEmpty()){
    std::cout << " and " << recently_executed.pop();
  }
  std::cout << " is/are executed. ";

  if(!recently_completed.isEmpty()){
    std::cout << recently_completed.pop();
    while(!recently_completed.isEmpty()){
      std::cout << " and " << recently_completed.pop();
    }
    std::cout << " is/are completed and removed from the heap.";
  }

  std::cout << "\n\nUpdated minmax heap:\n";
  to_run.levelOrder();

}
