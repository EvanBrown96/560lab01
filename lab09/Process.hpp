// 4/13

#include <iostream>

struct Process{
  int id;
  int priority;
  int time_left;

  Process(int id, int priority, int time_left);

  bool operator<(const Process& p) const;

  bool operator>(const Process& p) const;

  bool operator<=(const Process& p) const;

  bool operator>=(const Process& p) const;

  friend std::istream& operator>>(std::istream& stream, Process& p);
  friend std::ostream& operator<<(std::ostream& stream, const Process& p);

};
