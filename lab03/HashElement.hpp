#ifndef HashElement_hpp
#define HashElement_hpp


enum HashStates = {EMPTY, FULL, REMOVED};


template <typename T>
class HashElement{

public:

  HashElement();
  ~HashElement();
  void set(const T& value);
  T get() const;

  enum HashStates getState() const;

private:

  enum HashStates state;
  T* value;

};

#endif
