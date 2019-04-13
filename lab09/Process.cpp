// 4/13

#include <ios>
#include "Process.hpp"

std::ostream& operator<<(std::ostream& stream, const Process& p){

    stream << "P";
    stream << p.id;

    return stream;

}

std::istream& operator>>(std::istream& stream, Process& p){

  char cur = ' ';
  while(cur == ' ') stream >> cur;

  if(cur != '('){
    stream.setstate(std::ios::failbit);
    return stream;
  }

  int priority;
  stream >> priority;

  cur = ' ';
  while(cur == ' ') stream >> cur;

  if(cur != ','){
    stream.setstate(std::ios::failbit);
    return stream;
  }

  cur = ' ';
  while(cur == ' ') stream >> cur;

  int time_left;
  stream >> time_left;

  cur = ' ';
  while(cur == ' ') stream >> cur;

  if(cur != ')'){
    stream.setstate(std::ios::failbit);
    return stream;
  }

  p.priority = priority;
  p.time_left = time_left;

  return stream;

}



Process::Process(int id, int priority, int time_left):
  id(id), priority(priority), time_left(time_left){}

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
