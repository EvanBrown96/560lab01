// 4/13

#ifndef PROCESS_HPP
#define PROCESS_HPP

#include <iostream>

struct Process{

  static int count;

  int id;
  int priority;
  int time_left;

  Process(int priority, int time_left);

  bool operator<(const Process& p) const;

  bool operator>(const Process& p) const;

  bool operator<=(const Process& p) const;

  bool operator>=(const Process& p) const;

  friend std::istream& operator>>(std::istream& stream, Process& p);
  friend std::ostream& operator<<(std::ostream& stream, const Process& p);

};

#endif
