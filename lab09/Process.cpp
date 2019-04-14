// 4/13

#include <ios>
#include "Process.hpp"
#include "QuickQueue.hpp"

int Process::count = 1;

std::ostream& operator<<(std::ostream& stream, const Process& p){

    stream << "P";
    stream << p.id;

    return stream;

}

std::istream& operator>>(std::istream& stream, Process& p){

  int priority;
  int time_left;

  char cur;
  stream >> cur;
  while(cur != '(') stream >> cur;
  if(!(stream >> priority)){ stream.setstate(std::ios::failbit); return stream; }

  stream >> cur;
  while(cur != ',') stream >> cur;
  if(!(stream >> time_left)){ stream.setstate(std::ios::failbit); return stream; }

  while(cur != ')') stream >> cur;

  p.priority = priority;
  p.time_left = time_left;

  return stream;

}



Process::Process(int priority, int time_left):
  id(count), priority(priority), time_left(time_left){

  count++;

}

bool Process::operator<(const Process& p) const{
  return priority < p.priority;
}

bool Process::operator>(const Process& p) const{
  return priority > p.priority;
}

bool Process::operator<=(const Process& p) const{
  return priority <= p.priority;
}

bool Process::operator>=(const Process& p) const{
  return priority >= p.priority;
}
