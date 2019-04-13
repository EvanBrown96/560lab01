// 4/13

struct Process{
  int priority;
  int time_left;

  Process(priority, time_left): priority(priority), time_left(time_left){}

  bool operator<(const Process& p) const{
    return priority < p.priority;
  }

  bool operator>(const Process& p) const{
    return priority > p.priority;
  }

  bool operator<=(const Process& p) const{
    return priority <= p.priority;
  }

  bool operator>=(const Process& p) const{
    return priority >= p.priority;
  }

};
