#ifndef Clock_h
#define Clock_h

class Clock 
{  
public:
  Clock();
  void tick();
  inline int getCurrent() { return _current; }
  
private:
    int _current;
};

#endif // Clock_h
